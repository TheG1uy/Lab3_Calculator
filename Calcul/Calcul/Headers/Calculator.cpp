#include "Calculator.h"
#include <cmath>
bool TCalculator::checkInfix(){
	int Rbracket=0,Lbracket=0;
	for(int i=0;i<infix.size();i++)
        if (infix[i]=='(') Rbracket++;
		else if (infix[i]==')') Lbracket++;
		else if (i && isZnak(i) && isZnak(i-1) ) return false;
	if (Rbracket!=Lbracket) return false;
	return true;
}
bool TCalculator::isZnak(int i){
	if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' ||  infix[i] == '^') return true;
	else return false;
}
bool TCalculator::GoToPostfix(){
 postfix="";
 stc.clear();
 string tmp="("+infix+")";
 if (!checkInfix()) return false;
 for(int i=0;i<tmp.size();i++){
	 if(tmp[i]>='0' && tmp[i]<='9' || tmp[i]=='.' || tmp[i]=='e' || (tmp[i]=='p' && tmp[i+1]=='i')) postfix+=tmp[i];
	 else if (tmp[i]=='(') stc.push('('); 
	 else if (tmp[i]=='-' && tmp[i-1]=='('){postfix+=tmp[i];  continue ;}
	 else if (tmp[i]=='s' && tmp[i+1]=='i' && tmp[i+2]=='n' )  { i+=3; stc.push('s');}
	 else if (tmp[i]=='c' && tmp[i+1]=='o' && tmp[i+2]=='s' )  { i+=3; stc.push('c');}
	 else if (tmp[i]==')') {
		 while (stc.top() != '(' && stc.top() !='s' && stc.top() !='c' && stc.top() !='e') {
			 postfix += " ";
			 postfix += stc.pop();

		 }
		 if (stc.top()=='(')
		 stc.pop();
		 else { 
			 postfix+=" ";
			 postfix += stc.pop();
		 }
	 }
	 else if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '!' || tmp[i] == '^') {
		 postfix += " ";
		 while (priority(stc.top()) >= priority(tmp[i])) 
		    postfix += stc.pop();
	
		 stc.push(tmp[i]);
		 postfix += " ";
	 }
	 }
 return true;
 }
double TCalculator::GoToCalculate() {
	std.clear();
	double Result=0;
	string tmp="";
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i]=='e') std.push(exp(1.0));
		if (postfix[i]=='p') std.push(atan(1.0)*4);
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.' || (postfix[i]=='-' && postfix[i+1]!=' ') ) {
		 	tmp += postfix[i];
		}
		if (postfix[i] == ' ' && tmp.size()){
			std.push(atof(tmp.c_str()));
			tmp = "";
		}
		
		if (postfix[i] == '+' || (postfix[i]=='-' && postfix[i+1]==' ') || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '!' || postfix[i] == '^' || postfix[i] == 's' || postfix[i] == 'c' ) {
			switch (postfix[i]) {
			case 's':
				Result = sin(std.pop());				
				break;
			case 'c':
				Result = cos(std.pop());				
				break;
			case '+':
				Result = std.pop() + std.pop();
				break;
			case '-':
				Result = -std.pop() + std.pop();
				break;
			case '*':
				Result = std.pop() * std.pop();
				break;
			case '/':
				Result = (1/std.pop()) * std.pop();
				break;
			case '!': {
				Result = std.pop();
				int b = Result;
				for (int i = 1; i < b; i++)
					Result *= i;
			}
				break;
			case '^':
				int a= std.pop();
				Result = std.pop();
				double osn = Result;
				for (int i = 1; i < a; i++)
					Result *= osn;
				break;
			}

			std.push(Result);
		}
           
	}
	
	return Result;
}