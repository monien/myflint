/*
    Copyright (C) 2018 Daniel Schultz

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include "fmpz.h"
#include "mpoly.h"
#include "fmpz_mpoly.h"

void fmpz_mpoly_get_coeff_fmpz_monomial(fmpz_t c, const fmpz_mpoly_t A,
                         const fmpz_mpoly_t M, const fmpz_mpoly_ctx_t ctx)
{
    slong index;

    if (M->length != WORD(1))
    {
        flint_throw(FLINT_ERROR, "M not monomial in fmpz_mpoly_get_coeff_fmpz_monomial");
    }

    index = mpoly_monomial_index_monomial(A->exps, A->bits, A->length,
                                                 M->exps, M->bits, ctx->minfo);
    if (index < 0)
    {
        fmpz_zero(c);
    }
    else
    {
        FLINT_ASSERT(index < A->length);
        fmpz_set(c, A->coeffs + index);
    }
}
