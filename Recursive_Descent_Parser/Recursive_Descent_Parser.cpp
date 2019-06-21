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
#define ln "\n"
using namespace std;
const char spaceChar = ' ';
const char endOfStatement = ';';

//	Set of commands the parser must identify.
string command[] = { "status", "print", "end" };

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


/**
	IdentifierLookupTable implements CompilerTable.
*/
class IdentifierLookupTable : public CompilerTable {

private:
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
		return iList;
	}

	double getIdentifierValue(string identifier) {
		for (auto it : table) {
			if (it.first == identifier) return it.second;
		}

		//	issueError("Internal parser problem");	
	}

	void insertIdentifierNode(string identifier, double value) {
		table[identifier] = value;
	}
};


class IdentifierNode {
private:
	string identifier;
	double value;

public:
	IdentifierNode(string identifier, double value) {
		this->identifier = identifier;
		this->value = value;
	}

	friend ostream& operator<< (ostream &, const IdentifierNode &);
};


class Parser {
private:
	char runner;
	IdentifierLookupTable lookup;

	double factor();
	double term();
	double expression();
	void readLValue(string &);
	double findValue(const string &);
	void insertIdentifierNode(const IdentifierNode);
	void insertIdentifierNode(const string &, const double &);

	void issueError(string err) {
		cout << "======================================================" << endl;
		cerr << err << endl;
		cout << "======================================================" << endl;

		exit(1);
	}

public:
	void parseStatement();	//	Entry point of the parser.
	friend ostream& operator<< (ostream &, const Parser &);
};

void Parser::insertIdentifierNode(const string &identifier, const double& value) {

}

void Parser::insertIdentifierNode(const IdentifierNode idNode) {

}

double Parser::findValue(const string &identifier) {

}

void Parser::readLValue(string &lValue) {

}

double Parser::factor() {

}

double Parser::term() {
	double fVal = factor();
	while (1) {
		switch (runner) {
		case '*':
			fVal *= factor();
			break;

		case '/':
			fVal /= factor();
			break;

		default:
			return fVal;
		}
	}
}

double Parser::expression() {
	double termVal = term();
	while (1) {
		switch (runner) {
		case '+':
			termVal += term();
			break;
			
		case '-':
			termVal -= term();
			break;

		default:
			return termVal;
		}
	}
}

void Parser::parseStatement() {
	string lValue = "";
	double expVal;
	cout << "$: ";
	cin >> runner;
	readLValue(lValue);

	if (lValue == "status") {
		cout << this;
	}
	else if (lValue == "print") {
		readLValue(lValue);	//	print the variable after the print command.
		cout << lValue << ": " << findValue(lValue) << ln;
	}
	else if (lValue == "exit") {
		exit(1);
	}
	else {
		while (runner == spaceChar) cin >> runner;
		
		if (runner == '=') {
			expVal = expression();
			if (runner != endOfStatement) {
				issueError("Expected ';' at the end of the statement");
			}
			else insertIdentifierNode(lValue, expVal);
		}
		else {
			issueError("Invalid statement");
		}
	}
}


int main() {
	//	Start the interpreter!
	cout << "Hello world!!" << endl;
	cout << "Press any key to continue:" << ln;
	cin.get();

	Parser parser;
	while (1) {
		parser.parseStatement();
	}
}


