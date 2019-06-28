// Recursive_Descent_Parser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//	#include<bits/stdc++.h>
#include<conio.h>
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

void debug(string dbg, bool flag = false) {
	cout << dbg << ln;
	if (flag) cin.get();
}

void issueError(string err) {
	cout << "======================================================" << endl;
	cerr << err << endl;
	cout << "======================================================" << endl;

	char ch;
	getch();
	exit(0);
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
	vector<pair<string, double> > getAllIdentifiers(string pattern) {
		vector<pair<string, double> > iList;
		return iList;
	}

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

public:
	void parseStatement();	//	Entry point of the parser.
	friend ostream& operator<< (ostream &, const Parser &);
};

void Parser::insertIdentifierNode(const string &identifier, const double& value) {

}

void Parser::insertIdentifierNode(const IdentifierNode idNode) {

}

double Parser::findValue(const string &identifier) {
	return 0.0;
}

void Parser::readLValue(string &lValue) {

}

double Parser::factor() {
	double var, minus = 1.0;
	static string lValue;	//	Why like this.
	cin >> runner;

	while (runner == '+' || runner == '-') {
		if (runner == '-') cin >> runner;
	}

	if ((runner >= '0' && runner <= '9') || runner == '.') {
		cin.putback(runner);
		cin >> var >> runner;
	}
	else if (runner == '(') {
		var = expression();
		if (runner == ')')
			cin >> runner;
		else issueError("Missing matching parenthesis");
	}
	else {
		readLValue(lValue);
		while (runner == spaceChar) cin >> runner;
		var = findValue(lValue);
	}

	return minus*var;
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
	debug("Inside expression");
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
	debug("parsing the statement");
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

	Parser parser;
	while (1) {
		parser.parseStatement();
	}

	cin.get();
	return 0;
}


