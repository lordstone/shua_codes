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

vector<node*> generateLinkedList(int units, int length=10, int range=100){
	vector<node*> mylist;
	srand(length);
	if(length <= 0) return mylist;
	for(int i = 0; i < units; ++ i){
		node * head = new node(rand() % range) ;
		node * cur = head;
		for(int j = 0; j < length - 1; ++ j){
			int random_int = rand() % range ;
			cur -> next = new node(random_int);
			cur = cur -> next;
		}
		mylist.push_back(head);
	}
	return mylist;
}

void displayLinkedList(node * head, string lname="New"){
	cout << "linked List " << lname << ": ";
	while(head){
		cout << (head->val);
		if (head -> next) cout << "->";
		head = head -> next;
	}
	cout << endl;
}

void deleteList(node *head){
	while(head){
		node * todelete = head;
		head = head -> next;
		delete todelete;
	}
}

vector<node*> generateRandomLengthLinkedList(int units, int length=10, int range=100){
	vector<node*> mylist;
	srand(length);
	if(length <= 0) return mylist;
	for(int i = 0; i < units; ++ i){
		node * head = new node(rand() % range);
		node * cur = head;
		for(int j = 0; j < (rand() % (length-1)) + 1; ++ j){
			int random_int = rand() % range ;
			cur -> next = new node(random_int);
			cur = cur -> next;
		}
		mylist.push_back(head);
	}
	return mylist;
}
