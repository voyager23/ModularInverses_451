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
 * 
 */


#include <iostream>
#include <numeric>

using namespace std;

int main(int argc, char **argv)
{
	for(int m = 29; m != 43; ++m) {
		for(int n = m/2; n != m-1; ++n){
			int g = gcd(m,n);
			cout << m << ","<<n<<","<<g<<endl;
		}
		cout<<endl;
	}
	return 0;
}

