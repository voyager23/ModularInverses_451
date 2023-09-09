/*
 * coprimetree.cxx
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
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

typedef array<long,2> Node;

bool cmpNodes(Node a, Node b);
bool cmpNodes(Node a, Node b) {
	if (a[0] < b[0]) return true;
	if (a[0] > b[0]) return false;
	if (a[1] < b[1]) return true;
	return false;
}

int main(int argc, char **argv)
{
	vector<Node> wspace= {}; // new nodes here
	vector<Node> working = {Node{3,1}}; // previous nodes
	vector<Node> oddsave 	= {}; // final save vector
	
	int levels = 5;
	do {
		wspace.clear();
		for(Node n : working) {
			wspace.push_back(Node{2*n[0] - n[1], n[0]});
			wspace.push_back(Node{2*n[0] + n[1], n[0]});
			wspace.push_back(Node{n[0] + 2*n[1], n[1]});
		}
		// append working to oddsave
		for(Node x : working) oddsave.push_back(x);
		
		// set working = wspace
		working = wspace;
		
	} while(--levels);
	
	// finally append working to oddsave
	for(Node x : working) oddsave.push_back(x);	
	
	// append wspace to oddsave
	for(Node x : wspace) oddsave.push_back(x);
	
	sort(oddsave.begin(), oddsave.end(), cmpNodes);
	
	// output contents of oddsave
	for(Node x : oddsave) cout <<"("<< x[0] << "," << x[1] << ")" << "   ";
	cout << endl;
	
	return 0;
}

