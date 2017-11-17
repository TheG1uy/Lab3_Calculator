#include "Calculator.h"
void TCalculator::GoToPostfix(){
 postfix="";
 stc.clear();
 string tmp="("+infix+")";
 for(int i=0;i<tmp.size();i++){
	 if(tmp[i]>='0' && tmp[i]<='9' || tmp[i]=='.') postfix+=tmp[i];
	 else if (tmp[i]=='(') stc.push('('); 
	 else if (tmp[i]==')') {
		 while (stc.top() != '(') {
			 postfix += " ";
			 postfix += stc.pop();

		 }
		 stc.pop();
	 }
	 else if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '!' || tmp[i] == '^') {
		 postfix += " ";
		 while (priority(stc.top()) >= priority(tmp[i])) 
		    postfix += stc.pop();
	
		 stc.push(tmp[i]);
		 postfix += " ";
	 }
	 }
 }
double TCalculator::GoToCalculate() {
	std.clear();
	char tmpC[10];
	double Result=0;
	string tmp="";
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
		 	tmp += postfix[i];
		}
		if (postfix[i] == ' ' && tmp.size()){
			std.push(atof(strcpy(tmpC,tmp.c_str())));
			tmp = "";
		}
		
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '!' || postfix[i] == '^') {
			switch (postfix[i]) {
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
				int osn = Result;
				for (int i = 1; i < a; i++)
					Result *= osn;
				break;
			}

			std.push(Result);
		}
           
	}
	
	return Result;
}