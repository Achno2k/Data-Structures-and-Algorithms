#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isBalanced(char* exp){
	stack<char> stk;
	int i;
	for(i=0; i<strlen(exp); i++){
		if(exp[i] == '(')
			stk.push(exp[i]);
		else if(exp[i]==')'){
			if(stk.empty())
				return false;
			else
				stk.pop();
		}
	}
	return stk.empty()? true : false;
}

int main()
{
	char A[] = "((a+b)*(c+d))";
	cout << "Valid: " << isBalanced(A) << endl;

	char B[] = "((a+b)*(c+d)))";
	cout << "Valid: " << isBalanced(B) << endl;

	return 0;
} 