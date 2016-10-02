#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> ext;

long long countPath(string f, vector<string>& dir){
	long long count = 0;
	count += static_cast<int>(f.length());
	for (auto item : dir){
		count += static_cast<int>(item.length());
	}
	return count + 1;
}

int solution(string s, unordered_set<string> exts){
	int p = 0;
	string word = "";
	bool isExt = false;
	string myExt = "";
	long long count = 0;
	int lastLvl = 0;
	int curLvl = 0;
	vector<string> dir;
	while(p < static_cast<int>(s.length())){
		if(s[p] == '\n' || s[p] == '\0'){
			while(lastLvl > curLvl){
				dir.pop_back();
				lastLvl --;
			}	
			if (isExt == true) {
				if(exts.find(myExt) != exts.end()){
					word += myExt;
					count += countPath(word, dir);
				}
			}else{
				if (curLvl == lastLvl && !dir.empty())
					dir[dir.size() - 1] = word;
				else
					dir.push_back(word);
			}
			word = "";
			myExt = "";
			curLvl = 0;
			isExt = false;
		}else if (s[p] == ' '){
			curLvl += 1;
		}else if (s[p] == '.'){
			isExt = true;
		}else{
			if (!isExt){
				word += s[p];
			}else{
				myExt += s[p];
			}
		}
		p ++;
	}
	return static_cast<int>(count % 1000000007);
}

int main(){
	string ins = "";
	char c;
	while (cin.get(c)) ins += c;
	cout << "Your inputs: " << ins << endl;
	// inserting exts
	ext.insert("jpeg");
	ext.insert("gif");
	cout << "Solution: " << solution(ins, ext) << endl;
	return 0;
}

