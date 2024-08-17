#include <iostream>
using namespace std;

/*bool palindrome(string s){
	while(i < j){
		if(!(s[i]==s[j]))
			return false;
		i++;
        j--;
	}
    return true;
}
 bool isPalindrome(int x) {
        int num = x;
        int reverse = 0;

        while(num>0){
            int unit = num % 10;
            reverse = reverse * 10 + unit;
            num = num/10;
        }

        cout << reverse;

        if(x == reverse){
            return true;
        }else{
            return false;
        }
            
    }

int main()
{
	/*string s = "12345";
	if(palindrome(s))
		cout << "palindrome";
	else
		cout << "Not palindrome";

	int num=123;
	if(isPalindrome(num))
		cout << "palindrome";
	else
		cout << "Not palindrome";

	return 0;
}*/

bool isPalindrome(int n) {
    int num = n;
    int reversed = 0;
    
    // Reverse the number
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    // Check if the original and reversed numbers are equal
    if (n == reversed) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (isPalindrome(num)) {
        std::cout << num << " is a palindrome" << std::endl;
    } else {
        std::cout << num << " is not a palindrome" << std::endl;
    }

    return 0;
}
