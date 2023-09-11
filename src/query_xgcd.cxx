/*
 * query_xgcd.cxx
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


#include <iostream>

using namespace std;

typedef unsigned long long ullong;
typedef     signed long long    llong;

void xgcd(llong *result, llong a, llong b);

//----- definitions -----
void xgcd(llong *result, llong a, llong b){
    long aa[2]={1,0}, bb[2]={0,1}, q;
    while(1) {
        q = a / b; a = a % b;
        aa[0] = aa[0] - q*aa[1];  bb[0] = bb[0] - q*bb[1];
        if (a == 0) {
            result[0] = b; result[1] = aa[1]; result[2] = bb[1];
            return;
        };
        q = b / a; b = b % a;
        aa[1] = aa[1] - q*aa[0];  bb[1] = bb[1] - q*bb[0];
        if (b == 0) {
            result[0] = a; result[1] = aa[0]; result[2] = bb[0];
            return;
        };
    };
}
 

int main(int argc, char **argv)
{
	llong a,b,c[3],delta,limit;
	bool soln = false;
	llong global = 0;
	for(llong a = 3; a != 500000; ++a){
		soln = false;
		if((a%2)==0) { // check odd values only
			b = a - 3;
			delta = -2;
		} else { // check all values
			b = a - 2;
			delta = -1;
		}
		limit = a / 2;
		while(b >= limit) {
			xgcd(c,a,b);
			// check for solution where c = {gcd, s, t}
			if(c[0] == 1) { // possible solution
				if ( c[2] < 0) c[2] += a;
				if( c[2] == b) {	//SOLUTION
					//cout << "I(" << a << ")=" << c[2] << endl;
					global += c[2];
					soln = true;
					goto next_a;
				} else { // if c[2] == b
					b += delta;
				} // else
			} else { // not a soln
				b += delta;
			}
			if(soln) break;
		} // while b...
		//cout << "I(" << a << ")=" << 1 << endl;
		global += 1;
		next_a: ;
	} // for a...
	cout << "Global count: " << global << endl;
	return 0;
}
