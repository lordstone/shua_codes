/*
	lordstone:
*/

#include <iostream>

using namespace std;

string num2str(int num){
	
	string s = "";
	if(num == 0 || num == 1)return "";
	while (num != 0){
		s += ('0' + static_cast<char>(num % 10));
		num /= 10;
	}
	string s1 = "";
	for(int i = s.size(); i >= 0 ; --i){
		s1 += s[i];
	}
	return s1;
}

string zipStr(string s1){
	string s2;
	int count = 1;
	for(int i = 1; i < s1.size(); ++ i){
		if(s1[i] == s1[i-1]){
			count += 1;
		}else{
			s2 += s1[i-1];
			s2 += num2str(count);
			count = 0;
		}
	}
	s2 += s1[s1.size() - 1];
	s2 += num2str(count);
	return s1.size() > s2.size() ? s2 : s2;
}

int main(){

	string v1 = "";

	cin >> v1;

	cout << ("Your input:" + v1) << endl;

	cout << zipStr(v1) << endl;

	return 0;
}
