/*
	lordstone:
*/

#include <iostream>

using namespace std;


string replace(string s1){
	
	string s2 = "";

	for(int i = 0; i < s1.size(); ++ i ){
		
		if(s1[i] == ' '){

			s2 += "%20";

		}else{
			s2 += s1[i];
		}

	}

	return s2;
}

int main(){

	string v1 = "jiji bibi igigi wqe";

	// cin >> v1;

	cout << ("Your input:" + v1) << endl;

	cout << replace(v1) << endl;	

	return 0;
}
