/*
    Copyright (C) 2023 Albin Ahlbäck
    Copyright (C) 2024 Fredrik Johansson

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include "mpn_extras.h"

#if FLINT_HAVE_ADX

mp_limb_t flint_mpn_mul_1_1(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_2_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_2_2(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_3_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_3_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_3_3(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_4_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_4_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_4_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_4_4(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_5_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_5_5(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_6_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_6_6(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_7_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_7_7(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_8_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_8_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_9_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_9_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_10_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_10_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_11_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_11_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_12_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_12_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_13_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_13_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_14_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_14_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_15_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_15_8(mp_ptr, mp_srcptr, mp_srcptr);

mp_limb_t flint_mpn_mul_16_1(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_2(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_3(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_4(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_5(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_6(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_7(mp_ptr, mp_srcptr, mp_srcptr);
mp_limb_t flint_mpn_mul_16_8(mp_ptr, mp_srcptr, mp_srcptr);

#else

mp_limb_t flint_mpn_mul_1_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    NN_MUL_1X1(res[1], res[0], u[0], v[0]);
    return res[1];
}

mp_limb_t flint_mpn_mul_2_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(res[2], res[1], 0, a, u[1], v0);
    return res[2];
}

mp_limb_t flint_mpn_mul_2_2(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    mp_limb_t w[2];
    w[0] = v[0];
    w[1] = v[1];
    NN_MUL_1X1(a, res[0], u[0], w[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, w, 2);
    NN_ADDMUL_S2_A2_1X1(res[3], res[2], b, a, u[1], w[1]);
    return res[3];
}

mp_limb_t flint_mpn_mul_3_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(res[3], res[2], 0, a, u[2], v0);
    return res[3];
}

mp_limb_t flint_mpn_mul_3_2(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    mp_limb_t w[2];
    w[0] = v[0];
    w[1] = v[1];
    NN_MUL_1X1(a, res[0], u[0], w[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u + 1, w, 2);
    NN_ADDMUL_S2_A2_1X1(res[4], res[3], b, a, u[2], w[1]);
    return res[4];
}

mp_limb_t flint_mpn_mul_3_3(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 1, v + 1, 2);
    NN_ADDMUL_S2_A2_1X1(res[5], res[4], b, a, u[2], v[2]);
    return res[5];
}


mp_limb_t flint_mpn_mul_4_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(res[4], res[3], 0, a, u[3], v0);
    return res[4];
}

mp_limb_t flint_mpn_mul_4_2(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    mp_limb_t w[2];
    w[0] = v[0];
    w[1] = v[1];
    NN_MUL_1X1(a, res[0], u[0], w[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u + 1, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 2, w, 2);
    NN_ADDMUL_S2_A2_1X1(res[5], res[4], b, a, u[3], w[1]);
    return res[5];
}

mp_limb_t flint_mpn_mul_4_3(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 1, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 2, v + 1, 2);
    NN_ADDMUL_S2_A2_1X1(res[6], res[5], b, a, u[3], v[2]);
    return res[6];
}

mp_limb_t flint_mpn_mul_4_4(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 1, v + 1, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 2, v + 2, 2);
    NN_ADDMUL_S2_A2_1X1(res[7], res[6], b, a, u[3], v[3]);
    return res[7];
}


mp_limb_t flint_mpn_mul_5_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(res[5], res[4], 0, a, u[4], v0);
    return res[5];
}

mp_limb_t flint_mpn_mul_5_2(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    mp_limb_t w[2];
    w[0] = v[0];
    w[1] = v[1];
    NN_MUL_1X1(a, res[0], u[0], w[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u + 1, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 2, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 3, w, 2);
    NN_ADDMUL_S2_A2_1X1(res[6], res[5], b, a, u[4], w[1]);
    return res[6];
}

mp_limb_t flint_mpn_mul_5_3(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 1, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 2, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 3, v + 1, 2);
    NN_ADDMUL_S2_A2_1X1(res[7], res[6], b, a, u[4], v[2]);
    return res[7];
}

mp_limb_t flint_mpn_mul_5_4(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 1, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 2, v + 1, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 3, v + 2, 2);
    NN_ADDMUL_S2_A2_1X1(res[8], res[7], b, a, u[4], v[3]);
    return res[8];
}

mp_limb_t flint_mpn_mul_5_5(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 1, v + 1, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 2, v + 2, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 3, v + 3, 2);
    NN_ADDMUL_S2_A2_1X1(res[9], res[8], b, a, u[4], v[4]);
    return res[9];
}


mp_limb_t flint_mpn_mul_6_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(res[6], res[5], 0, a, u[5], v0);
    return res[6];
}

mp_limb_t flint_mpn_mul_6_2(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    mp_limb_t w[2];
    w[0] = v[0];
    w[1] = v[1];
    NN_MUL_1X1(a, res[0], u[0], w[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u + 1, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 2, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 3, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 4, w, 2);
    NN_ADDMUL_S2_A2_1X1(res[7], res[6], b, a, u[5], w[1]);
    return res[7];
}

mp_limb_t flint_mpn_mul_6_3(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 1, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 2, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 3, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 4, v + 1, 2);
    NN_ADDMUL_S2_A2_1X1(res[8], res[7], b, a, u[5], v[2]);
    return res[8];
}

mp_limb_t flint_mpn_mul_6_4(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 1, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 2, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 3, v + 1, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 4, v + 2, 2);
    NN_ADDMUL_S2_A2_1X1(res[9], res[8], b, a, u[5], v[3]);
    return res[9];
}

mp_limb_t flint_mpn_mul_6_5(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 1, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 2, v + 1, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 3, v + 2, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[8], 0, b, a, u + 4, v + 3, 2);
    NN_ADDMUL_S2_A2_1X1(res[10], res[9], b, a, u[5], v[4]);
    return res[10];
}

mp_limb_t flint_mpn_mul_6_6(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u, v, 6);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 1, v + 1, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 2, v + 2, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[8], 0, b, a, u + 3, v + 3, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[9], 0, b, a, u + 4, v + 4, 2);
    NN_ADDMUL_S2_A2_1X1(res[11], res[10], b, a, u[5], v[5]);
    return res[11];
}


mp_limb_t flint_mpn_mul_7_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(res[7], res[6], 0, a, u[6], v0);
    return res[7];
}

mp_limb_t flint_mpn_mul_7_2(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    mp_limb_t w[2];
    w[0] = v[0];
    w[1] = v[1];
    NN_MUL_1X1(a, res[0], u[0], w[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u + 1, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 2, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 3, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 4, w, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 5, w, 2);
    NN_ADDMUL_S2_A2_1X1(res[8], res[7], b, a, u[6], w[1]);
    return res[8];
}

mp_limb_t flint_mpn_mul_7_3(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u + 1, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 2, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 3, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 4, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 5, v + 1, 2);
    NN_ADDMUL_S2_A2_1X1(res[9], res[8], b, a, u[6], v[2]);
    return res[9];
}

mp_limb_t flint_mpn_mul_7_4(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u + 1, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 2, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 3, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 4, v + 1, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[8], 0, b, a, u + 5, v + 2, 2);
    NN_ADDMUL_S2_A2_1X1(res[10], res[9], b, a, u[6], v[3]);
    return res[10];
}

mp_limb_t flint_mpn_mul_7_5(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u + 1, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 2, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 3, v + 1, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[8], 0, b, a, u + 4, v + 2, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[9], 0, b, a, u + 5, v + 3, 2);
    NN_ADDMUL_S2_A2_1X1(res[11], res[10], b, a, u[6], v[4]);
    return res[11];
}

mp_limb_t flint_mpn_mul_7_6(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u, v, 6);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u + 1, v, 6);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 2, v + 1, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[8], 0, b, a, u + 3, v + 2, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[9], 0, b, a, u + 4, v + 3, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[10], 0, b, a, u + 5, v + 4, 2);
    NN_ADDMUL_S2_A2_1X1(res[12], res[11], b, a, u[6], v[5]);
    return res[12];
}

mp_limb_t flint_mpn_mul_7_7(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t b, a;
    NN_MUL_1X1(a, res[0], u[0], v[0]);
    NN_DOTREV_S3_A3_1X1(b, a, res[1], 0, 0, a, u, v, 2);
    NN_DOTREV_S3_A3_1X1(b, a, res[2], 0, b, a, u, v, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[3], 0, b, a, u, v, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[4], 0, b, a, u, v, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[5], 0, b, a, u, v, 6);
    NN_DOTREV_S3_A3_1X1(b, a, res[6], 0, b, a, u, v, 7);
    NN_DOTREV_S3_A3_1X1(b, a, res[7], 0, b, a, u + 1, v + 1, 6);
    NN_DOTREV_S3_A3_1X1(b, a, res[8], 0, b, a, u + 2, v + 2, 5);
    NN_DOTREV_S3_A3_1X1(b, a, res[9], 0, b, a, u + 3, v + 3, 4);
    NN_DOTREV_S3_A3_1X1(b, a, res[10], 0, b, a, u + 4, v + 4, 3);
    NN_DOTREV_S3_A3_1X1(b, a, res[11], 0, b, a, u + 5, v + 5, 2);
    NN_ADDMUL_S2_A2_1X1(res[13], res[12], b, a, u[6], v[6]);
    return res[13];
}

mp_limb_t flint_mpn_mul_8_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[6], 0, a, u[6], v0);
    NN_ADDMUL_S2_A2_1X1(res[8], res[7], 0, a, u[7], v0);
    return res[8];
}

mp_limb_t flint_mpn_mul_9_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[6], 0, a, u[6], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[7], 0, a, u[7], v0);
    NN_ADDMUL_S2_A2_1X1(res[9], res[8], 0, a, u[8], v0);
    return res[9];
}

mp_limb_t flint_mpn_mul_10_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[6], 0, a, u[6], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[7], 0, a, u[7], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[8], 0, a, u[8], v0);
    NN_ADDMUL_S2_A2_1X1(res[10], res[9], 0, a, u[9], v0);
    return res[10];
}

mp_limb_t flint_mpn_mul_11_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[6], 0, a, u[6], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[7], 0, a, u[7], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[8], 0, a, u[8], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[9], 0, a, u[9], v0);
    NN_ADDMUL_S2_A2_1X1(res[11], res[10], 0, a, u[10], v0);
    return res[11];
}

mp_limb_t flint_mpn_mul_12_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[6], 0, a, u[6], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[7], 0, a, u[7], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[8], 0, a, u[8], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[9], 0, a, u[9], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[10], 0, a, u[10], v0);
    NN_ADDMUL_S2_A2_1X1(res[12], res[11], 0, a, u[11], v0);
    return res[12];
}

mp_limb_t flint_mpn_mul_13_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[6], 0, a, u[6], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[7], 0, a, u[7], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[8], 0, a, u[8], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[9], 0, a, u[9], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[10], 0, a, u[10], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[11], 0, a, u[11], v0);
    NN_ADDMUL_S2_A2_1X1(res[13], res[12], 0, a, u[12], v0);
    return res[13];
}

mp_limb_t flint_mpn_mul_14_1(mp_ptr res, mp_srcptr u, mp_srcptr v)
{
    mp_limb_t a, v0 = v[0];
    NN_MUL_1X1(a, res[0], u[0], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[1], 0, a, u[1], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[2], 0, a, u[2], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[3], 0, a, u[3], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[4], 0, a, u[4], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[5], 0, a, u[5], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[6], 0, a, u[6], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[7], 0, a, u[7], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[8], 0, a, u[8], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[9], 0, a, u[9], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[10], 0, a, u[10], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[11], 0, a, u[11], v0);
    NN_ADDMUL_S2_A2_1X1(a, res[12], 0, a, u[12], v0);
    NN_ADDMUL_S2_A2_1X1(res[14], res[13], 0, a, u[13], v0);
    return res[14];
}

#endif

#define _MUL(mx, nx) flint_mpn_mul_##mx##_##nx
#define MUL(mx, nx) _MUL(mx, nx)


#if FLINT_HAVE_ADX

const flint_mpn_mul_func_t flint_mpn_mul_func_tab[][FLINT_MPN_MUL_FUNC_TAB_WIDTH] = {
    {NULL, NULL,           NULL,      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 1,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 2,1), MUL( 2,2),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 3,1), MUL( 3,2), MUL( 3,3),      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 4,1), MUL( 4,2), MUL( 4,3), MUL( 4,4),      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 5,1), MUL( 5,2), MUL( 5,3), MUL( 5,4), MUL( 5,5),      NULL,      NULL,      NULL},
    {NULL, MUL( 6,1), MUL( 6,2), MUL( 6,3), MUL( 6,4), MUL( 6,5), MUL( 6,6),      NULL,      NULL},
    {NULL, MUL( 7,1), MUL( 7,2), MUL( 7,3), MUL( 7,4), MUL( 7,5), MUL( 7,6), MUL( 7,7),      NULL},
    {NULL, MUL( 8,1), MUL( 8,2), MUL( 8,3), MUL( 8,4), MUL( 8,5), MUL( 8,6), MUL( 8,7), MUL( 8,8)},
    {NULL, MUL( 9,1), MUL( 9,2), MUL( 9,3), MUL( 9,4), MUL( 9,5), MUL( 9,6), MUL( 9,7), MUL( 9,8)},
    {NULL, MUL(10,1), MUL(10,2), MUL(10,3), MUL(10,4), MUL(10,5), MUL(10,6), MUL(10,7), MUL(10,8)},
    {NULL, MUL(11,1), MUL(11,2), MUL(11,3), MUL(11,4), MUL(11,5), MUL(11,6), MUL(11,7), MUL(11,8)},
    {NULL, MUL(12,1), MUL(12,2), MUL(12,3), MUL(12,4), MUL(12,5), MUL(12,6), MUL(12,7), MUL(12,8)},
    {NULL, MUL(13,1), MUL(13,2), MUL(13,3), MUL(13,4), MUL(13,5), MUL(13,6), MUL(13,7), MUL(13,8)},
    {NULL, MUL(14,1), MUL(14,2), MUL(14,3), MUL(14,4), MUL(14,5), MUL(14,6), MUL(14,7), MUL(14,8)},
    {NULL, MUL(15,1), MUL(15,2), MUL(15,3), MUL(15,4), MUL(15,5), MUL(15,6), MUL(15,7), MUL(15,8)},
    {NULL, MUL(16,1), MUL(16,2), MUL(16,3), MUL(16,4), MUL(16,5), MUL(16,6), MUL(16,7), MUL(16,8)},
};

const flint_mpn_mul_func_t flint_mpn_mul_n_func_tab[] = {
    NULL,
    MUL( 1, 1),
    MUL( 2, 2),
    MUL( 3, 3),
    MUL( 4, 4),
    MUL( 5, 5),
    MUL( 6, 6),
    MUL( 7, 7),
    MUL( 8, 8),
};

#else

const flint_mpn_mul_func_t flint_mpn_mul_func_tab[][FLINT_MPN_MUL_FUNC_TAB_WIDTH] = {
    {NULL, NULL,           NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 1,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 2,1), MUL( 2,2),      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 3,1), MUL( 3,2), MUL( 3,3),      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 4,1), MUL( 4,2), MUL( 4,3), MUL( 4,4),      NULL,      NULL,      NULL},
    {NULL, MUL( 5,1), MUL( 5,2), MUL( 5,3), MUL( 5,4), MUL( 5,5),      NULL,      NULL},
    {NULL, MUL( 6,1), MUL( 6,2), MUL( 6,3), MUL( 6,4), MUL( 6,5), MUL( 6,6),      NULL},
    {NULL, MUL( 7,1), MUL( 7,2), MUL( 7,3), MUL( 7,4), MUL( 7,5), MUL( 7,6), MUL( 7,7)},
    {NULL, MUL( 8,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL( 9,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL(10,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL(11,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL(12,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL(13,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
    {NULL, MUL(14,1),      NULL,      NULL,      NULL,      NULL,      NULL,      NULL},
};

const flint_mpn_mul_func_t flint_mpn_mul_n_func_tab[] = {
    NULL,
    MUL( 1, 1),
    MUL( 2, 2),
    MUL( 3, 3),
    MUL( 4, 4),
    MUL( 5, 5),
    MUL( 6, 6),
    MUL( 7, 7),
};

#endif

mp_limb_t
flint_mpn_mul_basecase(mp_ptr r, mp_srcptr x, mp_srcptr y, mp_size_t xn, mp_size_t yn)
{
    return flint_mpn_mul_func_tab[xn][yn](r, x, y);
}
