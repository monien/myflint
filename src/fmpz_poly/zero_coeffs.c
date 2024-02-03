/*
    Copyright (C) 2010 Sebastian Pancratz

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include "fmpz_vec.h"
#include "fmpz_poly.h"

void
fmpz_poly_zero_coeffs(fmpz_poly_t poly, slong i, slong j)
{
    if (i < 0)
        i = 0;
    if (j > poly->length)
        j = poly->length;

    _fmpz_vec_zero(poly->coeffs + i, j - i);

    if (j == poly->length)
    {
        _fmpz_poly_set_length(poly, i);
        _fmpz_poly_normalise(poly);
    }
}
