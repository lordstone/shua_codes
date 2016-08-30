#include <iostream>

using namespace std;

string rev_str(string sin){

	string sout = "";
	
	for(int i = sin.size() - 1; i >=0; --i){

		sout += sin[i];

	}
	return sout;

}

int main(){

	string str_in = "";
	cin >> str_in;

	cout << rev_str(str_in) << endl;

	return 0;

}
