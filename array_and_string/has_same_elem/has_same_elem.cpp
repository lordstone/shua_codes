/*
	lordstone:
*/

#include <iostream>

using namespace std;


bool isDupChar(string s1, string s2){
	if(s1 == s2){
		return true;
	}else{

		int charMap [255] = {0};		
		int counter = 0;
		for(int i = 0; i < s1.size(); ++ i )
		{
			charMap[static_cast<int>(s1[i])] += 1;
			counter += 1;
		}
		for(int i = 0; i < s2.size(); ++ i){
			if(charMap[static_cast<int>(s2[i])] >= 1)
			{
				charMap[static_cast<int>(s2[i])] -= 1;
				counter -= 1;
			}else{
				return false;
			}
		}
		
		return counter == 0 ? true : false;
	}
}

int main(){

	string v1 = "";
	string v2 = "abcdefg";

	cin >> v1;

	cout << ("Your input:" + v1) << endl;

	cout << (isDupChar(v1, v2) ? 
	"has same elem" : "has different elem")
	 << endl;	

	return 0;
}
