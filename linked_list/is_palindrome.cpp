#include "linked_list.h"

using namespace std;

int findLength(lnode * head){
	int count = 0;
	while(head){
		count ++;
		head = head -> next;
	}
	return count;
}

bool isPalindrome(lnode * head){
	int length = findLength(head);
	vector<lnode*> q;
	if(length < 2) return true;
	for(int i = 0; i < length / 2; ++i){
		q.push_back(head);
		head = head -> next;
	}
	if(length % 2 == 1){
		head = head -> next;
	}
	while(!q.empty()){
		char chr = q[q.size() - 1]->val;
		q.pop_back();
		if(chr == head -> val){
			head = head -> next;
		}else{
			return false;
		}
	}
	return true;
}




int main(int argc, char* argv[]){
	string s = "abcdefghic";
	if(argc > 1){
		s = argv[1];
	}
	lnode * testList = createLList(s);
	cout << "The input is: " << s << endl;
	displayLList(testList);
	if(isPalindrome(testList))
		cout << "This is a palindrome list" << endl;
	else
		cout << "This is NOT a palindrome list" << endl;
	deleteLList(testList);
	return 0;
}
