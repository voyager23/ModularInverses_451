/*
 * gmpxgcd.cxx
 * 
 * Copyright 2023 Michael Tate <mike@Michaels-MBP>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
//~ g++ gmpxgcd.cxx --std=c++20 -I/usr/local/include -L/usr/local/lib 
	//~ -lgmpxx -lgmp -o gxd

#include <iostream>
#include <vector>
#include <stdint.h>
#include <gmp.h>

using namespace std;

int main(int argc, char **argv)
{
	mpz_t  g,s,t,a,b;
	mpz_inits(g,s,t,a,b,NULL);
	
	vector<unsigned long> m = {111,114,109,118} ;	// I(111)=73 I(114)=77 I(109)=I(118)=1
	
	for(auto &n:m){
		mpz_set_ui(a, (unsigned)n);
		mpz_sub_ui(b, a, 38U);
		//cout << b << " " << a << endl;
		mpz_gcdext(g,s,t,a,b);
		gmp_printf("%Zd %Zd %Zd %Zd %Zd\n",g,s,t,a,b);
	}
		
		
		
	mpz_clears(g,s,t,a,b,NULL);
	return 0;
}

