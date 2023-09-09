/*
 * bsoln.cxx
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

// typedef map<uint64_t,vector<uint64_t>> InvMod;

const uint64_t MaxN = 20000000;



// From OEIS A033948 - The sequence consists of 1, 2, 4 and numbers of the 
// form p^i and 2p^i, where p is an odd prime and i >= 1.
// 1,2,3,4,5,6,7,8,9,10,11,13,14 etc
array<uint64_t,(MaxN+1)> primitive_root = {0,1,1,0,1};

typedef array<uint64_t,MaxN+1> SqrArray;
// Allocate very large variables as globals
SqrArray sqrs;

//----------------------------------------------------------------------
//~ uint64_t find_inverse(uint64_t q, SqrArray sqrs);
//~ uint64_t find_inverse(uint64_t q, SqrArray sqrs){
	//~ uint64_t query = q;
	//~ uint64_t idx = query - 2;
	//~ while((idx < MaxN+1)&&(idx > 0)){		
		//~ if((sqrs[idx] - 1) % query == 0) {	//solution//
			//~ return idx;
		//~ } else {
			//~ idx -= 1;
		//~ }
	//~ }
	//~ return 0;		
//~ }
//----------------------------------------------------------------------
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
	cout<<"Starting primitive_roots"<<endl;
	for(auto p = primes.begin()+1; p != primes.end(); ++p) {
		uint64_t i = (*p);
		if (i > MaxN) break;
		while(i < MaxN+1) {
			primitive_root[i] = 1;
			if(2*i < (MaxN+1)) primitive_root[2*i] = 1;
			i *= (*p);
		} //while...
	} //for...
	
	uint64_t global = 0;	//global count
	for(uint64_t j = 3; j < MaxN+1; j++) {
		if(j%100000 == 0) cout<<j<<endl;
		if(primitive_root[j]==1) {
			global += 1;
		} else {
			// find inverse
			uint64_t query = j;
			uint64_t idx = query - 2;
			while((idx < MaxN+1)&&(idx > 0)){		
				if((sqrs[idx] - 1) % query == 0) {	//solution//
					//cout << idx << endl;
					global += idx;
					break;
				} else {
					idx -= 1;
				}
			} // while
		} // else
	}
	
	cout<<"global count: "<<global<<endl;
	
	
	return 0;
}

