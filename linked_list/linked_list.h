#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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
	unordered_set<node*> mySet;
	while(head){
		cout << (head->val);
		if (head -> next) cout << "->";
		if(mySet.find(&*head) != mySet.end()){
			cout << "(circle detected, end)";
			break;
		}
		mySet.insert(&*head);
		head = head -> next;
	}
	cout << endl;
}

void deleteList(node *head){
	while(head){
		node * todelete = head;
		head = head -> next;
		todelete -> next = nullptr;
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

node * createListWithLetters(string s){
	node * head = nullptr;
	node * cur = nullptr;
	unordered_map<char, node*> mymap;
	for(auto i = 0; i < static_cast<int>(s.length()); ++i){
		char chr = s[i];
		if(!head){
			head = new node(i);
			cur = head;
			mymap[chr] = head;
		}else if(mymap.find(chr) == mymap.end()){
			node * newNode = new node(i);
			cur -> next = newNode;
			cur = cur -> next;
			mymap[chr] = cur;
		}else{
			cur -> next = mymap[chr];
			break;
		}
	}
	return head;
}
