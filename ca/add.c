/*
    Copyright (C) 2020 Fredrik Johansson

    This file is part of Calcium.

    Calcium is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "ca.h"

void
_ca_mpoly_q_reduce_ideal(fmpz_mpoly_q_t res, ca_field_srcptr field, ca_ctx_t ctx)
{
    slong i, n;

    n = CA_FIELD_IDEAL_LENGTH(field);

    /* todo: optimizations */
    if (n > 0)
    {
        fmpz_mpoly_struct ** I;
        fmpz_mpoly_struct ** Q;
        fmpq_t scale;

        I = flint_malloc(sizeof(fmpz_mpoly_struct *) * n);
        for (i = 0; i < n; i++)
            I[i] = CA_FIELD_IDEAL_ELEM(field, i);

        Q = flint_malloc(sizeof(fmpz_mpoly_struct *) * n);
        for (i = 0; i < n; i++)
        {
            Q[i] = flint_malloc(sizeof(fmpz_mpoly_struct));
            fmpz_mpoly_init(Q[i], CA_FIELD_MCTX(field, ctx));
        }

        fmpq_init(scale);

        fmpz_mpoly_quasidivrem_ideal(fmpq_denref(scale), Q, fmpz_mpoly_q_numref(res), fmpz_mpoly_q_numref(res), I, n, CA_FIELD_MCTX(field, ctx));
        fmpz_mpoly_quasidivrem_ideal(fmpq_numref(scale), Q, fmpz_mpoly_q_denref(res), fmpz_mpoly_q_denref(res), I, n, CA_FIELD_MCTX(field, ctx));

        fmpq_canonicalise(scale);
        fmpz_mpoly_q_canonicalise(res, CA_FIELD_MCTX(field, ctx));
        fmpz_mpoly_q_mul_fmpq(res, res, scale, CA_FIELD_MCTX(field, ctx));

        for (i = 0; i < n; i++)
        {
            fmpz_mpoly_clear(Q[i], CA_FIELD_MCTX(field, ctx));
            flint_free(Q[i]);
        }

        flint_free(Q);
        flint_free(I);

        fmpq_clear(scale);
    }
}


void
ca_add_fmpq(ca_t res, const ca_t x, const fmpq_t y, ca_ctx_t ctx)
{
    ca_field_srcptr field;

    if (fmpq_is_zero(y) || CA_IS_SPECIAL(x))
    {
        ca_set(res, x, ctx);
        return;
    }

    if (CA_IS_QQ(x, ctx))
    {
        _ca_make_fmpq(res, ctx);
        fmpq_add(CA_FMPQ(res), CA_FMPQ(x), y);
    }
    else
    {
        field = CA_FIELD(x, ctx);
        _ca_make_field_element(res, field, ctx);

        if (CA_FIELD_IS_NF(field))
            nf_elem_add_fmpq(CA_NF_ELEM(res), CA_NF_ELEM(x), y, CA_FIELD_NF(field));
        else
            fmpz_mpoly_q_add_fmpq(CA_MPOLY_Q(res), CA_MPOLY_Q(x), y, CA_FIELD_MCTX(field, ctx));
    }
}

void
ca_add_fmpz(ca_t res, const ca_t x, const fmpz_t y, ca_ctx_t ctx)
{
    fmpq_t t;
    *fmpq_numref(t) = *y;
    *fmpq_denref(t) = 1;
    ca_add_fmpq(res, x, t, ctx);
}

void
ca_add_ui(ca_t res, const ca_t x, ulong y, ca_ctx_t ctx)
{
    fmpz_t t;
    fmpz_init_set_ui(t, y);
    ca_add_fmpz(res, x, t, ctx);
    fmpz_clear(t);
}

void
ca_add_si(ca_t res, const ca_t x, slong y, ca_ctx_t ctx)
{
    fmpz_t t;
    fmpz_init_set_si(t, y);
    ca_add_fmpz(res, x, t, ctx);
    fmpz_clear(t);
}

void
ca_add(ca_t res, const ca_t x, const ca_t y, ca_ctx_t ctx)
{
    ca_field_srcptr xfield, yfield, zfield;

    xfield = CA_FIELD(x, ctx);
    yfield = CA_FIELD(y, ctx);

    if (CA_IS_QQ(x, ctx) && (xfield == yfield))
    {
        _ca_make_fmpq(res, ctx);
        fmpq_add(CA_FMPQ(res), CA_FMPQ(x), CA_FMPQ(y));
        return;
    }

    if (CA_IS_QQ(y, ctx))
    {
        if (res == y)
        {
            fmpq_t t;
            fmpq_init(t);
            fmpq_set(t, CA_FMPQ(y));
            ca_add_fmpq(res, x, t, ctx);
            fmpq_clear(t);
        }
        else
        {
            ca_add_fmpq(res, x, CA_FMPQ(y), ctx);
        }
        return;
    }

    if (CA_IS_QQ(x, ctx))
    {
        if (res == x)
        {
            fmpq_t t;
            fmpq_init(t);
            fmpq_set(t, CA_FMPQ(x));
            ca_add_fmpq(res, y, t, ctx);
            fmpq_clear(t);
        }
        else
        {
            ca_add_fmpq(res, y, CA_FMPQ(x), ctx);
        }
        return;
    }

    if (CA_IS_SPECIAL(x) || CA_IS_SPECIAL(y))
    {
        if (CA_IS_UNDEFINED(x) || CA_IS_UNDEFINED(y))
        {
            ca_undefined(res, ctx);
            return;
        }

        if (CA_IS_UNKNOWN(x) || CA_IS_UNKNOWN(y))
        {
            ca_unknown(res, ctx);
            return;
        }

        if (!CA_IS_SPECIAL(y))
        {
            ca_set(res, x, ctx);
            return;
        }

        if (!CA_IS_SPECIAL(x))
        {
            ca_set(res, y, ctx);
            return;
        }

        if (CA_IS_INF(x) && CA_IS_INF(y))
        {
            if (CA_IS_SIGNED_INF(x) && CA_IS_SIGNED_INF(y))
            {
                truth_t eq = ca_check_equal(x, y, ctx);

                if (eq == T_TRUE)         /* sum of infs with same sign */
                    ca_set(res, x, ctx);
                else if (eq == T_FALSE)   /* sum of infs with different sign */
                    ca_undefined(res, ctx);
                else
                    ca_unknown(res, ctx);
                return;
            }
            else
            {
                ca_undefined(res, ctx);
            }
            return;
        }

        ca_unknown(res, ctx);
        return;
    }

    /* In-field operation. */
    if (xfield == yfield)
    {
        zfield = xfield;
        _ca_make_field_element(res, zfield, ctx);

        if (CA_FIELD_IS_NF(zfield))
        {
            nf_elem_add(CA_NF_ELEM(res), CA_NF_ELEM(x), CA_NF_ELEM(y), CA_FIELD_NF(zfield));
        }
        else
        {
            fmpz_mpoly_q_add(CA_MPOLY_Q(res), CA_MPOLY_Q(x), CA_MPOLY_Q(y), CA_FIELD_MCTX(zfield, ctx));
            _ca_mpoly_q_reduce_ideal(CA_MPOLY_Q(res), zfield, ctx);
        }

        ca_condense_field(res, ctx);

        return;
    }

    /* Coerce to a common field. */
    {
        ca_t t, u;

        ca_init(t, ctx);
        ca_init(u, ctx);

        ca_merge_fields(t, u, x, y, ctx);
        ca_add(res, t, u, ctx);
        ca_condense_field(res, ctx);

        ca_clear(t, ctx);
        ca_clear(u, ctx);
    }
}

void
ca_sub(ca_t res, const ca_t x, const ca_t y, ca_ctx_t ctx)
{
    ca_t t;
    ca_init(t, ctx);
    ca_neg(t, y, ctx);
    ca_add(res, x, t, ctx);
    ca_clear(t, ctx);
}

void
ca_sub_fmpq(ca_t res, const ca_t x, const fmpq_t y, ca_ctx_t ctx)
{
    fmpq_t t;
    fmpq_init(t);
    fmpq_neg(t, y);
    ca_add_fmpq(res, x, t, ctx);
    fmpq_clear(t);
}

void
ca_sub_fmpz(ca_t res, const ca_t x, const fmpz_t y, ca_ctx_t ctx)
{
    fmpq_t t;
    *fmpq_numref(t) = *y;
    *fmpq_denref(t) = 1;
    ca_sub_fmpq(res, x, t, ctx);
}

void
ca_sub_ui(ca_t res, const ca_t x, ulong y, ca_ctx_t ctx)
{
    fmpz_t t;
    fmpz_init_set_ui(t, y);
    ca_sub_fmpz(res, x, t, ctx);
    fmpz_clear(t);
}

void
ca_sub_si(ca_t res, const ca_t x, slong y, ca_ctx_t ctx)
{
    fmpz_t t;
    fmpz_init_set_si(t, y);
    ca_sub_fmpz(res, x, t, ctx);
    fmpz_clear(t);
}

void
ca_fmpq_sub(ca_t res, const fmpq_t x, const ca_t y, ca_ctx_t ctx)
{
    ca_sub_fmpq(res, y, x, ctx);
    ca_neg(res, res, ctx);
}

void
ca_fmpz_sub(ca_t res, const fmpz_t x, const ca_t y, ca_ctx_t ctx)
{
    fmpq_t t;
    *fmpq_numref(t) = *x;
    *fmpq_denref(t) = 1;
    ca_fmpq_sub(res, t, y, ctx);
}

void
ca_ui_sub(ca_t res, ulong x, const ca_t y, ca_ctx_t ctx)
{
    fmpz_t t;
    fmpz_init_set_ui(t, x);
    ca_fmpz_sub(res, t, y, ctx);
    fmpz_clear(t);
}

void
ca_si_sub(ca_t res, slong x, const ca_t y, ca_ctx_t ctx)
{
    fmpz_t t;
    fmpz_init_set_si(t, x);
    ca_fmpz_sub(res, t, y, ctx);
    fmpz_clear(t);
}
