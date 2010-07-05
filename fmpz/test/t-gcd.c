/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/****************************************************************************

   Copyright (C) 2009 William Hart

*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mpir.h>
#include "flint.h"
#include "ulong_extras.h"
#include "fmpz.h"

int main(void)
{
   int result;
   printf("gcd...."); fflush(stdout);
   fflush(stdout);

   fmpz_randinit();

   for (ulong i = 0; i < 100000UL; i++) 
   {
      fmpz_t a, b, c;
      mpz_t d, e, f, g;
      
      fmpz_init(a);
      fmpz_init(b);
      fmpz_init(c);
      
      mpz_init(d);
      mpz_init(e);
      mpz_init(f);
      mpz_init(g);
      
      fmpz_randtest(a, 200);
      fmpz_randtest(b, 200);
      fmpz_randtest(c, 200);
      fmpz_mul(a, a, c);
      fmpz_mul(b, b, c);
      fmpz_get_mpz(d, a);
      fmpz_get_mpz(e, b);
      
      fmpz_gcd(c, a, b);
      mpz_gcd(f, d, e);

      fmpz_get_mpz(g, c);
         
      result = (mpz_cmp(f, g) == 0);

      if (!result)
      {
         printf("FAIL\n"); fflush(stdout);
         gmp_printf("d = %Zd, e = %Zd, f = %Zd, g = %Zd\n", d, e, f, g);
         abort();
      }

      fmpz_clear(a);
      fmpz_clear(b);
      fmpz_clear(c);
      
      mpz_clear(d);
      mpz_clear(e);
      mpz_clear(f);
      mpz_clear(g);
   }
   printf("here\n"); fflush(stdout);
   // check aliasing of a and b
   for (ulong i = 0; i < 100000UL; i++) 
   {
      fmpz_t a, b, c;
      mpz_t d, e, f, g;
      
      fmpz_init(a);
      fmpz_init(c);
      
      mpz_init(d);
      mpz_init(f);
      mpz_init(g);
      
      fmpz_randtest(a, 200);
      
      fmpz_get_mpz(d, a);
      
      fmpz_gcd(c, a, a);
      mpz_gcd(f, d, d);
      
      fmpz_get_mpz(g, c);
         
      result = (mpz_cmp(f, g) == 0);

      if (!result)
      {
         printf("FAIL\n"); fflush(stdout);
         gmp_printf("d = %Zd, f = %Zd, g = %Zd\n", d, f, g);
         abort();
      }

      fmpz_clear(a);
      fmpz_clear(c);
      
      mpz_clear(d);
      mpz_clear(f);
      mpz_clear(g);
   }
   printf("here2\n"); fflush(stdout);
   // test aliasing of a and c
   for (ulong i = 0; i < 100000UL; i++) 
   {
      fmpz_t a, b, c;
      mpz_t d, e, f, g;
      
      fmpz_init(a);
      fmpz_init(b);
      fmpz_init(c);
      
      mpz_init(d);
      mpz_init(e);
      mpz_init(f);
      mpz_init(g);
      
      fmpz_randtest(a, 200);
      fmpz_randtest(b, 200);
      fmpz_randtest(c, 200);
      fmpz_mul(a, a, c);
      fmpz_mul(b, b, c);

      fmpz_get_mpz(d, a);
      fmpz_get_mpz(e, b);
      
      fmpz_gcd(a, a, b);
      mpz_gcd(f, d, e);
      
      fmpz_get_mpz(g, a);
         
      result = (mpz_cmp(f, g) == 0);

      if (!result)
      {
         printf("FAIL\n"); fflush(stdout);
         gmp_printf("d = %Zd, e = %Zd, f = %Zd, g = %Zd\n", d, e, f, g);
         abort();
      }

      fmpz_clear(a);
      fmpz_clear(b);
      fmpz_clear(c);
      
      mpz_clear(d);
      mpz_clear(e);
      mpz_clear(f);
      mpz_clear(g);
   }
   printf("here3\n"); fflush(stdout);
   // test aliasing of b and c
   for (ulong i = 0; i < 100000UL; i++) 
   {
      fmpz_t a, b, c;
      mpz_t d, e, f, g;
      
      fmpz_init(a);
      fmpz_init(b);
      fmpz_init(c);
      
      mpz_init(d);
      mpz_init(e);
      mpz_init(f);
      mpz_init(g);
      
      fmpz_randtest(a, 200);
      fmpz_randtest(b, 200);
      fmpz_randtest(c, 200);
      fmpz_mul(a, a, c);
      fmpz_mul(b, b, c);

      fmpz_get_mpz(d, a);
      fmpz_get_mpz(e, b);
      
      fmpz_gcd(b, a, b);
      mpz_gcd(f, d, e);
      
      fmpz_get_mpz(g, b);
         
      result = (mpz_cmp(f, g) == 0);

      if (!result)
      {
         printf("FAIL\n"); fflush(stdout);
         gmp_printf("d = %Zd, e = %Zd, f = %Zd, g = %Zd\n", d, e, f, g);
         abort();
      }

      fmpz_clear(a);
      fmpz_clear(b);
      fmpz_clear(c);
      
      mpz_clear(d);
      mpz_clear(e);
      mpz_clear(f);
      mpz_clear(g);
   }

   fmpz_randclear();

   _fmpz_cleanup();
   printf("PASS\n"); fflush(stdout);
   return 0;
}
