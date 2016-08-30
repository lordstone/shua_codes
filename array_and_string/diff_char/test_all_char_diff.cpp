/*
	lordstone:
*/

#include <iostream>

using namespace std;


bool isDupChar(string s1, string s2){
	if(s1 == s2){
		return s1.size() == 0 ? false : true;
	}else{

		bool charMap [255];		
		for(int i = 0; i < s1.size(); ++ i )
		{
			charMap[static_cast<int>(s1[i])] = true;
		}
		for(int i = 0; i < s2.size(); ++ i){
			if(charMap[static_cast<int>(s2[i])])
			{
				return true;
			}
		}
		return false;
	}
}

int main(){

	string v1 = "";
	string v2 = "abcdefg";

	cin >> v1;

	cout << ("Your input:" + v1) << endl;

	cout << (isDupChar(v1, v2) ? 
	"duplicate Char detected" : "No duplicate char..")
	 << endl;	


	return 0;
}
