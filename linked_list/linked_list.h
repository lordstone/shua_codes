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

