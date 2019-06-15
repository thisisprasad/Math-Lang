// Recursive_Descent_Parser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//	#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <algorithm>
using namespace std;
#define ln "\n"

void issueError(string err) {
	cout << "======================================================" << endl;
	cerr << err << endl;
	cout << "======================================================" << endl;
}

/*
	This is an interface.
*/
class CompilerTable {
public:
	virtual vector<pair<string, double> > getAllIdentifiers() = 0;
	
	/* Searches for a pattern in the Indentifiers */
	virtual vector<pair<string, double> > getAllIdentifiers(string pattern) = 0;

	virtual double getIdentifierValue(string identifier) = 0;
	
	virtual vector<pair<string, double> > getAllIdentifiersForValue(double value) = 0;

};


class IdentifierLookupTable : public CompilerTable {

	unordered_map<string, double> table;

public:
//	friend void issueError(string);
	vector<pair<string, double> > getAllIdentifiers() {
		vector<pair<string, double> > iList;
		for (auto it : table) {
			iList.push_back(make_pair(it.first, it.second));
		}

		return iList;
	}

	/* Empty implementation */
	vector<pair<string, double> > getAllIdentifiers(string pattern) {}

	vector<pair<string, double> > getAllIdentifiersForValue(double value) {
		vector<pair<string, double> > iList;
		for (auto it : table) {
			if (it.second == value)
				iList.push_back(make_pair(it.first, it.second));
		}
	}

	double getIdentifierValue(string identifier) {
		for (auto it : table) {
			if (it.first == identifier) return it.second;
		}

		issueError("Internal parser problem");
	}
};


class IdentifierNode {
private:

};


class Parser {

};


int main() {
	//	Start the interpreter!
	cout << "Hello world!!" << endl;

	cin.get();
}


