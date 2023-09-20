/*
 * mygcd.cxx
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
 * 451. 153651073760956
 */


#include <iostream>
#include <numeric>

using namespace std;

void xgcd(long *result, long a, long b){
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
	long a,b,c[3];
	long start,end,delta,inverse;
	long modulus;
	long global = 0;
	modulus = 3;
	while(modulus != 100001){
		start = modulus - 2;
		delta = -1;
		if((modulus % 2) == 0){	// even modulus
			start -= 1;
			delta -= 1;
		}
		end = modulus/2;
		bool flag = false;
		for(long i = start; i >= end; --i){
			xgcd(c,  modulus, i*i);
			if((c[0]  ==  1)&&(c[2]==1)) {
				//cout << modulus << " " << i << endl;
				global += i;
				flag = true;
				break; 
			}
			
		}
		//if(!flag) cout << modulus << " " << 1 << endl;
		global += 1;
		modulus += 1;
	}
	cout << "Global: " << global << endl;
	//return 0;
	
}

