/*
    Copyright (C) 2016 Fredrik Johansson

    This file is part of Arb.

    Arb is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "acb_dirichlet.h"

void
acb_dirichlet_zeta_rs_r(acb_t res, const acb_t s, slong K, slong prec)
{
    arb_ptr dk;
    acb_ptr Fp;
    arb_t a, p;
    acb_t U, S, u, v;
    fmpz_t N;
    mag_t err;
    slong j, k, wp;

    /* determinate K automatically */
    if (K <= 0)
    {
        double sigma, t, log2err, best_log2err;
        slong best_K;

        sigma = arf_get_d(arb_midref(acb_realref(s)), ARF_RND_DOWN);
        t = arf_get_d(arb_midref(acb_imagref(s)), ARF_RND_DOWN);

        if (!(sigma > -1e6 && sigma < 1e6) || !(t > 1 && t < 1e40))
        {
            acb_indeterminate(res);
            return;
        }

        best_K = 1;
        best_log2err = 1e300;

        /* todo: also break if too slow rate of decay? */
        for (K = 1; K < 10 + prec * 0.25; K++)
        {
            if (sigma < 0 && K + sigma < 3)
                continue;

            /* Asymptotic approximation of the error term */
            log2err = 2.7889996532222537064 - 0.12022458674074695061 / K + 
                0.2419040680416126037 * K + 0.7213475204444817037 * K * log(K)
                + (-0.7213475204444817037 - 0.7213475204444817037 * K) * log(t);

            if (sigma >= 0.0)
                log2err += -2.8073549220576041074 + 1.5 * sigma;

            if (log2err < best_log2err)
            {
                best_log2err = log2err;
                best_K = K;
            }

            if (log2err < -prec)
                break;
        }

        K = best_K;
    }

    mag_init(err);
    acb_dirichlet_zeta_rs_bound(err, s, K);

    if (!mag_is_finite(err))
    {
        acb_indeterminate(res);
        mag_clear(err);
        return;
    }

    arb_init(a);
    arb_init(p);

    acb_init(U);
    acb_init(S);
    acb_init(u);
    acb_init(v);

    fmpz_init(N);

    dk = _arb_vec_init((3 * K) / 2 + 2);
    Fp = _acb_vec_init(3 * K + 1);

    for (wp = 2 * prec; ; wp *= 2)
    {

        /* a = sqrt(t / (2pi)) */
        arb_const_pi(a, wp);
        arb_mul_2exp_si(a, a, 1);
        arb_div(a, acb_imagref(s), a, wp);
        arb_sqrt(a, a, wp);

        /* N = floor(a) */
        arb_floor(p, a, wp);
        if (!arb_get_unique_fmpz(N, p))
        {
            if (wp > 4 * prec && wp > arb_rel_accuracy_bits(acb_imagref(s)))
            {
                acb_indeterminate(res);
                goto cleanup;
            }

            continue;
        }

        /* p = 1 + 2(N-a) */
        arb_sub_fmpz(p, a, N, wp);
        arb_neg(p, p);
        arb_mul_2exp_si(p, p, 1);
        arb_add_ui(p, p, 1, wp);

        acb_dirichlet_zeta_rs_f_coeffs(Fp, p, 3 * K + 1, wp);

        if (acb_rel_accuracy_bits(Fp + 3 * K) >= prec)
            break;

        if (wp > 4 * prec && wp > arb_rel_accuracy_bits(acb_imagref(s)))
            break;
    }

    if (!fmpz_fits_si(N))
    {
        acb_indeterminate(res);
        goto cleanup;
    }

    wp = prec + 10 + 3 * fmpz_bits(N); /* xxx */
    wp = FLINT_MAX(wp, prec + 10);
    wp = wp + FLINT_BIT_COUNT(K);

    acb_zero(S);

    for (k = 0; k <= K; k++)
    {
        acb_dirichlet_zeta_rs_d_coeffs(dk, acb_realref(s), k, wp);

        acb_zero(u);
        for (j = 0; j <= (3 * k) / 2; j++)
        {
            /* todo: precompute pi powers */
            acb_const_pi(v, wp);
            acb_div_onei(v, v);
            acb_mul_2exp_si(v, v, -1);
            acb_pow_ui(v, v, j, wp);

            acb_mul_arb(v, v, dk + j, wp);
            acb_addmul(u, v, Fp + 3 * k - 2 * j, wp);
        }

        acb_const_pi(v, wp);
        acb_mul(v, v, v, wp);
        acb_mul_arb(v, v, a, wp);
        acb_pow_ui(v, v, k, wp);
        acb_div(u, u, v, wp);
        acb_add(S, S, u, wp);
    }

    acb_add_error_mag(S, err);

    /* U = exp(-i[(t/2) log(t/(2pi)) - t/2 - pi/8]) */
    arb_log(acb_realref(u), a, wp);
    arb_mul_2exp_si(acb_realref(u), acb_realref(u), 1);
    arb_sub_ui(acb_realref(u), acb_realref(u), 1, wp);
    arb_mul(acb_realref(u), acb_realref(u), acb_imagref(s), wp);
    arb_mul_2exp_si(acb_realref(u), acb_realref(u), -1);

    arb_const_pi(acb_imagref(u), wp);
    arb_mul_2exp_si(acb_imagref(u), acb_imagref(u), -3);
    arb_sub(acb_realref(u), acb_realref(u), acb_imagref(u), wp);
    arb_neg(acb_realref(u), acb_realref(u));
    arb_sin_cos(acb_imagref(U), acb_realref(U), acb_realref(u), wp);

    /* S = (-1)^(N-1) * U * a^(-sigma) * S */

    acb_mul(S, S, U, wp);
    arb_neg(acb_realref(u), acb_realref(s));
    arb_pow(acb_realref(u), a, acb_realref(u), wp);
    acb_mul_arb(S, S, acb_realref(u), wp);
    if (fmpz_is_even(N))
        acb_neg(S, S);

    if (_acb_vec_estimate_allocated_bytes(fmpz_get_ui(N) / 6, wp) < 4e9)
        acb_dirichlet_powsum_sieved(u, s, fmpz_get_ui(N), 1, wp);
    else
        acb_dirichlet_powsum_smooth(u, s, fmpz_get_ui(N), 1, wp);

    acb_add(S, S, u, wp);

    acb_set(res, S);  /* don't set_round here; the extra precision is useful */

cleanup:
    _arb_vec_clear(dk, (3 * K) / 2 + 2);
    _acb_vec_clear(Fp, 3 * K + 1);

    arb_clear(a);
    arb_clear(p);

    acb_clear(U);
    acb_clear(S);
    acb_clear(u);
    acb_clear(v);

    fmpz_clear(N);
    mag_clear(err);
}

