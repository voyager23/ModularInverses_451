/*
 * squares.cxx
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
#include <cstdint>

using namespace std;

const ulong SIZE = 10000 + 1;
typedef array<ulong,SIZE> SqrArray;

ulong find_inverse(ulong q, SqrArray sqrs);
ulong find_inverse(ulong q, SqrArray sqrs){
	ulong query = q;
	ulong idx = query - 2;
	while((idx <= SIZE)&&(idx > 0)){
		if((sqrs[idx] - 1) % query == 0) {	//solution//

			return idx;
		} else {
			idx -= 1;
		}
	}
	return 0;		
}

int main(int argc, char **argv)
{
	// Create array of squares
	SqrArray sqrs;
	for(ulong m = 0; m < SIZE; ++m) sqrs[m] = m*m;
	
	ulong query = 100;
	ulong inverse = find_inverse(query, sqrs);
			cout << "I(" << query << ") = " << inverse << endl;
	return 0;
}

