/*
 * queries.cxx
 * 
 * Copyright 2023 Mike <mike@pop-os>
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
 * 153651073760956
 */


#include <iostream>
#include <array>
#include <cmath>
#include <vector>
#include <map>
#include <cstdint>

using namespace std;

typedef map<uint64_t,vector<uint64_t> > InvMod;

const uint64_t MaxN = 20000000;
// Allocate very large variables as globals
array<uint64_t,(MaxN+1)> sqrs;

// From OEIS A033948 - The sequence consists of 1, 2, 4 and numbers of the 
// form p^i and 2p^i, where p is an odd prime and i >= 1.
// 1,2,3,4,5,6,7,8,9,10,11,13,14 etc
array<uint64_t,(MaxN+1)> primitive_root = {0,1,1,1,1,1,1,1,1,1,1,1,0};

int main(int argc, char **argv)
{
	
	// Create array of squares allocated from *global* memory
	for(uint64_t m = 0; m < (MaxN+1); ++m) sqrs[m] = m*m;
	// Create array of queries where I(q) == 1 if q is primitive root
	// primitive roots consists of 1, 2, 4 and numbers of the form p^i and 2p^i, 
	// where p is an odd prime and i >= 1.
	// I(primitive root) == 1
	
	InvMod invmod;	
	for(uint64_t query = 3; query != 50; ++query){
		uint64_t idx = query - 2;
		while((idx <= 100000)&&(idx > 0)){
			if((sqrs[idx] - 1) % query == 0) {	//solution//
				//cout << "I(" << query << ") = " << idx << endl;
				// add solution to map
				auto iter = invmod.find(idx);
				if (iter == invmod.end()) { // new entry
					invmod.emplace(idx,vector<uint64_t>{query});					
				} else { // add to vector
					(*iter).second.push_back(query);
				}					
				break;
			} else {
				idx -= 1;
			} //if_else...
		} //while...
	} //for query...
	// output map contents <modularinverse> <vector uint64_t>
	for(auto i = invmod.begin(); i != invmod.end(); ++i){
		cout<<"I(";
		for (auto j = i->second.begin(); j != i->second.end(); ++j)
			cout<<*j<<" ";
		cout<<") = "<<i->first<<endl;
		// add additional calc here
		cout << ((double)i->first / (double)i->second.back()) << endl;
	}
	
	
	return 0;
}

