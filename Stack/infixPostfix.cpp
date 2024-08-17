#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool isOperand(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return false;
	else
		return true;
}

int precendence(char ch){
	if(ch == '+' || ch == '-')
		return 1;
	else if(ch == '*' || ch == '/')
		return 2;
	return 0;
}

char* convert(char* infix){
	stack<char> stk;
	char* postfix = new char[strlen(infix)+1];
	int i=0, j=0;

	while(infix[i] != '\0'){
		if(isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else{
			if(precendence(infix[i]) > precendence(stk.top())){
				stk.push(infix[i]);
				i++;
			}
			else
				postfix[j++] = stk.pop();
		}
	}
	while(!stk.empty())
		postfix[j++] = stk.pop();
	postfix[j] = '\0';

	return postfix;
}

int main()
{
	char A[] = "a+b*c-d/e";
	char* B = convert(A); 
	cout << "Postfix: " << B << endl;

	return 0;
}