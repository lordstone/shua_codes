#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct node {
	int val;
	node * next;
	node(int v) : val(v), next(nullptr) {}
};

vector<node*> generateLinkedList(int units, int length=10){
	vector<node*> mylist;
	for(int i = 0; i < units; ++ i){
		node * head = new node(0);
		node * cur = head;
		for(int j = 0; j < length - 1; ++ j){
			int random_int = rand() % 10 ;
			cur -> next = new node(random_int);
			cur = cur -> next;
		}
		mylist.push_back(head);
	}
	return mylist;
}

void displayLinkedList(node * head){
	cout << "New linked List:";
	while(head){
		cout << (head->val);
		if (head -> next) cout << "->";
		head = head -> next;
	}
	cout << endl;
}

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
