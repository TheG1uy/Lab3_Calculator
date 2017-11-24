#pragma once
#include "TStack.h"
#include <string>
#include <iostream>
using namespace std;
class TCalculator{
private :
	string infix;
	string postfix;
	TStack<char> stc;
	TStack<double> std;
	int priority(char zn){
		switch (zn){
		    case '(':
			    return 0;
			case 's':
			    return 0;
			case 'c':
			    return 0;
			case '+':
				return 1;
			case '-':
				return 1;
			case '*':
				return 2;
			case '/':
				return 2;
			case '!':
				return 3;
			case '^':
				return 4;
				
		}
	}
	bool checkInfix();
	bool isZnak(int );
public:
	string getInfix() { return infix; }
	string getPostfix() { return postfix; }
	void setInfix(string _infix) { infix = _infix; }
	bool GoToPostfix();
	double GoToCalculate();
};