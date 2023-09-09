/*
 * asoln.cxx
 * 
 * Copyright 2023 mike <mike@Fedora37>
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


#include <iostream>
#include <array>
#include <cmath>
#include <vector>
#include <map>
#include <cstdint>

#include "../inc/toolbox.hxx"

using namespace std;

typedef map<uint64_t,vector<uint64_t>> InvMod;

const uint64_t MaxN = 20000000;

// Allocate very large variables as globals
array<uint64_t,(MaxN+1)> sqrs;

// From OEIS A033948 - The sequence consists of 1, 2, 4 and numbers of the 
// form p^i and 2p^i, where p is an odd prime and i >= 1.
// 1,2,3,4,5,6,7,8,9,10,11,13,14 etc
array<uint64_t,(MaxN+1)> primitive_root = {0,1,1,1,1,1,1,1,1,1,1,1,0};

int main(int argc, char **argv)
{
	// Setup primes vector
	vector<uint64_t> primes;
	SieveOfEratosthenes(primes,MaxN+1);
	// Create array of squares allocated from *global* memory
	for(uint64_t m = 0; m < (MaxN+1); ++m) sqrs[m] = m*m;
	
	// Create array of primitve_roots where I(q) == 1 if q is primitive root
	// primitive roots consists of 1, 2, 4 and numbers of the form p^i and 2p^i, 
	// 		where p is an odd prime and i >= 1.
	// I(primitive root) == 1
	cout<<"Starting generate_descriptors..."<<endl;
	PfactOfN pfn;
	for(uint64_t q = 12; q != MaxN+1; ++q){
		generate_descriptors(primes, q, pfn);
	}
	cout<<"complete."<<endl;
	
	
	return 0;
}

