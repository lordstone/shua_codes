#include <iostream>
#include <string>

using namespace std;

int op(int n){
	int a = (n % 100) / 10;
	int b = n % 10;
	return a > b ? a : b;	
}

int op2(int n){
	// get avg and ceiling it
	int a = (n % 100) / 10;
	int b = n % 10;
	return (a + b + 1) / 2;
}


int procAndGetMin(int n){
	int res = -1;
	int bottom = 0;
	int mult = 1;
	while(n > 0){
		int tmp = ((n / 100) * mult * 10) + op2(n % 100) * mult + bottom;
		if (res == -1 || res > tmp){
			res = tmp;
		}
		bottom += n % 10 * mult;
		mult *= 10;
		n /= 10;
	}
	return res;
}

int main(int argc, char* argv []){
	string arg = argc > 1 ? argv[1] : "1234567890";
	int iin = stoi(arg);
	cout << "Proc Int to get min: input:" << arg << endl;
	cout << "Your result: " << procAndGetMin(iin) << endl;	
	return 0;
}
