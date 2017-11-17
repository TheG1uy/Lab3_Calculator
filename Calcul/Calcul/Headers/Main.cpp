#include "Calculator.h"
int main(){
	TCalculator a;
	string tmp;
	cin >> tmp;
	a.setInfix(tmp);
	a.GoToPostfix();
	cout<< a.GoToCalculate()<<endl;
}