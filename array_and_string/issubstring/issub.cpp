/*
	lordstone:
*/

#include <iostream>

using namespace std;

bool isSubString(string s1, string s2){
	if(s1.size() !=  s2.size()){
		return false;
	}else{
		int n = s1.size();
		for(int offset = 0; offset < n; ++ offset){
			bool flag = true;
			for(int i = 0; i < n; ++ i){
				if(s1[(i + offset) % n] != s2[i]){
					flag = false;
					break;
				}
			}
			if(flag){
				return true;
			}
		}
		return false;
	}
}

int main(){

	string s1 = "";
	string s2 = "";

	cout << "String 1:" ;
	cin >> s1;
	cout << "String 2:" ;
	cin >> s2;

	cout << (isSubString(s1, s2) ? 
	"Yes, is sub string" : "No, is not sub string")
	 << endl;	

	return 0;
}
