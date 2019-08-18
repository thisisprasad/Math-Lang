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
#include "Parser.hpp"


//using namespace std;
//const char spaceChar = ' ';
//const char endOfStatement = ';';
//
//bool debugSwitch = false;	//	This acts as switch to print the debug statements
//
////	Set of commands the parser must identify.
//string command[] = { "status", "print", "end" };
//
//bool isAlphabet(char ch){
//	return ((ch>='a' and ch<='z') or (ch>='A' and ch<='Z'));
//}
//
//bool isDigit(char ch){
//	return (ch>='0' and ch<='9');
//}
//
//void debug(string dbg, bool flag = false) {
//	if(!debugSwitch) return ;
//	cout << dbg << ln;
//	if (flag) cin.get();
//}
//
//void issueError(string err) {
//	cout << "======================================================" << endl;
//	cerr << err << endl;
//	cout << "======================================================" << endl;
//
//	char ch;
//	getch();
//	exit(0);
//}
//
///*
//	This is an interface.
//*/
//class CompilerTable {
//public:
//	virtual vector<pair<string, double> > getAllIdentifiers() = 0;
//
//	/* Searches for a pattern in the Indentifiers */
//	virtual vector<pair<string, double> > getAllIdentifiers(string pattern) = 0;
//
//	virtual double getIdentifierValue(string identifier) = 0;
//
//	virtual vector<pair<string, double> > getAllIdentifiersForValue(double value) = 0;
//
//};
//
//
///**
//	IdentifierLookupTable implements CompilerTable.
//*/
//class IdentifierLookupTable : public CompilerTable {
//
//private:
//	friend class Parser;
//	unordered_map<string, double> table;
//
//public:
////	friend void issueError(string);
//	vector<pair<string, double> > getAllIdentifiers() {
//		vector<pair<string, double> > iList;
//		for (auto it : table) {
//			iList.push_back(make_pair(it.first, it.second));
//		}
//
//		return iList;
//	}
//
//	/**
//		Empty implementation
//	*/
//	vector<pair<string, double> > getAllIdentifiers(string pattern) {
//		vector<pair<string, double> > iList;
//		return iList;
//	}
//
//	vector<pair<string, double> > getAllIdentifiersForValue(double value) {
//		vector<pair<string, double> > iList;
//		for (auto it : table) {
//			if (it.second == value)
//				iList.push_back(make_pair(it.first, it.second));
//		}
//		return iList;
//	}
//
//	double getIdentifierValue(string identifier) {
//		debug("getIdentifierValue");
//		for (auto it : table) {
//			if (it.first == identifier){
//				debug("it.first: " + it.first + ", it.second: " + to_string(it.second));
//				return it.second;
//			}
//		}
//
//		issueError("No such variable as " + identifier);
//	}
//
//	void insertIdentifierNode(string identifier, double value) {
//		debug("IdentifierLookUpTable::insertIdentifierNode");
//		table[identifier] = value;
//		debug("table[identifier]: " + identifier + ", " + to_string(value));
//	}
//
//	/**
//		Print the lookup table.
//	*/
//	void printTable() const {
//		for(auto it: table){
//			cout<<"identifier: "<<it.first<<", Value: "<<it.second<<ln;
//		}
//	}
//};
//
//
//class IdentifierNode {
//private:
//	string identifier;
//	double value;
//
//public:
//	IdentifierNode(string identifier, double value) {
//		this->identifier = identifier;
//		this->value = value;
//	}
//
//	friend ostream& operator<< (ostream &, const IdentifierNode &);
//};
//
//
//class Parser {
//private:
//	char runner;
//	IdentifierLookupTable lookup;
//
//	double factor();
//	double term();
//	double expression();
//	void readLValue(string &);
//	double findValue(const string &);
//	void insertIdentifierNode(const IdentifierNode);
//	void insertIdentifierNode(const string &, const double &);
//
//public:
//	void parseStatement();	//	Entry point of the parser.
//	friend ostream& operator<< (ostream &, const Parser &);
//};
//
//ostream& operator<< (ostream & out, const Parser &parser) {
//	debug("print the lookup table");
//	parser.lookup.printTable();
////	while(it != parser.lookup.table.end()){
////		out<<"identifier: "<<it->first<<", Value: "<<it->second<<ln;
////		it++;
////	}
//	return out;
//}
//
//void Parser::insertIdentifierNode(const string &identifier, const double& value) {
//	debug("inside insertIdentifierNode(key, val");
//	this->lookup.insertIdentifierNode(identifier, value);
//}
//
//void Parser::insertIdentifierNode(const IdentifierNode idNode) {
//
//}
//
//double Parser::findValue(const string &identifier) {
//	debug("findByValue() not implemented");
//	return this->lookup.getIdentifierValue(identifier);
//}
//
//void Parser::readLValue(string &lValue) {
//
//	int i = 0;
//	while(runner == spaceChar)
//		cin>>runner;
//
//	if(isAlphabet(runner)){
//		while(isAlphabet(runner) or isDigit(runner)){
//			lValue += runner;
//			cin.get(runner);	//	get next character from the console.
//		}
//	}
//	else{
//		issueError("Invalid lvalue identifier");
//	}
//}
//
//double Parser::factor() {
//	double var, minus = 1.0;
////	static string lValue;	//	Why like this.
//	string lValue = "";
//	cin >> runner;
//
//	while (runner == '+' or runner == '-') {
//		if (runner == '-') cin >> runner;
//	}
//
//	if ((runner >= '0' and runner <= '9') || runner == '.') {
//		cin.putback(runner);
//		cin >> var >> runner;
//	}
//	else if (runner == '(') {
//		var = expression();
//		if (runner == ')')
//			cin >> runner;
//		else issueError("Missing matching parenthesis");
//	}
//	else {
//		lValue = "";
//		readLValue(lValue);
//		while (runner == spaceChar) cin >> runner;
//		var = findValue(lValue);
//	}
//
//	return minus*var;
//}
//
//double Parser::term() {
//	debug("Inside term");
//	double fVal = factor();
//	while (1) {
//		switch (runner) {
//		case '*':
//			fVal *= factor();
//			break;
//
//		case '/':
//			fVal /= factor();
//			break;
//
//		default:
//			return fVal;
//		}
//	}
//}
//
//double Parser::expression() {
//	debug("Inside expression");
//	double termVal = term();
//	while (1) {
//		switch (runner) {
//		case '+':
//			termVal += term();
//			break;
//
//		case '-':
//			termVal -= term();
//			break;
//
//		default:
//			return termVal;
//		}
//	}
//}
//
//void Parser::parseStatement() {
//	debug("parsing the statement");
//	string lValue = "";
//	double expVal;
//	cout << "$: ";
//	cin >> runner;
//	readLValue(lValue);
//	debug("lValue: " + lValue);
//
//	if (lValue == "status") {
//		cout << *this;
//	}
//	else if (lValue == "print") {
//		lValue = "";	//	This might solve the problem
//		readLValue(lValue);	//	print the variable after the print command.
//		cout << lValue << ": " << findValue(lValue) << ln;
//	}
//	else if (lValue == "exit") {
//		exit(1);
//	}
//	else {
//		while (runner == spaceChar){
//			cin >> runner;
//			cout<<"runner: "<<runner<<ln;
//		}
//
//		if (runner == '=') {
//			expVal = expression();
//			if (runner != endOfStatement) {
//				issueError("Expected ';' at the end of the statement");
//			}
//			else insertIdentifierNode(lValue, expVal);
//		}
//		else {
//			issueError("Invalid statement");
//		}
//	}
//}
//

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



