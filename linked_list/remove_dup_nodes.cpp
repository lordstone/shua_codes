#include <stdio.h>
#include "linked_list.h"

using namespace std;

void removeDuplicateNodes(node * head){
	unordered_set<int> myset;
	node * cur = head;
	myset.insert(cur -> val);
	while(cur -> next){
		if(myset.find(cur -> next -> val) != myset.end()){
			// delete it
			node * tmp = cur -> next;
			cur -> next = tmp -> next;
			delete tmp;
		}else{
			myset.insert(cur -> next -> val);
			cur = cur -> next;
		}
	}
}

int main(){
	vector<node*> container = generateLinkedList(1, 100);
	for(auto i : container){
		displayLinkedList(i);
		removeDuplicateNodes(i);
		displayLinkedList(i);
	}
	return 0;
}
