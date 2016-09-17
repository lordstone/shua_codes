#include "linked_list.h"

using namespace std;

int findCircle(node * head){
	unordered_set<node*> myset;
	while(head){
		if(myset.find(&*head) == myset.end()){
			myset.insert(&*head);
			head = head -> next;
		}else{
			return head -> val;
		}
	}
	return -1;
}

int main(int argc, char* argv[]){
	string s = "abcdefghic";
	if(argc > 1){
		s = argv[1];
	}
	node * testList = createListWithLetters(s);
	cout << "The input is: " << s << endl;
	displayLinkedList(testList);
	cout << "The circle cross is the " << findCircle(testList) << "th node." << endl;
	deleteList(testList);
	return 0;
}
