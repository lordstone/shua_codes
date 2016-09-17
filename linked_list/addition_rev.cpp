#include <stdio.h>
#include "linked_list.h"

using namespace std;

node * addTwoListsRev(node * l1, node * l2){
	node * result = nullptr;
	node * head = nullptr;
	bool one_digit = false;
	while(l1 || l2){
		int sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
		sum += one_digit ? 1 : 0;
		one_digit = sum > 9;
		sum %= 10;
		if(!head){
			result = new node(sum);
			head = result;
		}else{
			result -> next = new node(sum);
			result = result -> next;
		}
		if(l1) l1 = l1 -> next;
		if(l2) l2 = l2 -> next;
	}
	if(one_digit) result -> next = new node(1);
	return head;
}

int main(){
	vector<node*> container = generateRandomLengthLinkedList(4, 10, 10);
	for(int i = 0; i < static_cast<int>(container.size()); i += 2){
		displayLinkedList(container[i], "add1");
		displayLinkedList(container[i+1], "add2");
		node * res = addTwoListsRev(container[i], container[i+1]);
		displayLinkedList(res, "sum");
		deleteList(res);
	}
	return 0;
}
