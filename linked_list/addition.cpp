#include <stdio.h>
#include "linked_list.h"

using namespace std;

node * addTwoLists(node * l1, node * l2){
	node * cur = nullptr;
	int a = 0, b = 0, sum = 0;
	while(l1){
		a *= 10;
		a += l1 -> val;
		l1 = l1 -> next;
	}	
	while(l2){
		b *= 10;
		b += l2 -> val;
		l2 = l2 -> next;
	}
	sum = a + b;
	while(sum > 0){
		node * tmp = new node(sum % 10);
		tmp -> next = cur;
		cur = tmp;
		sum /= 10;
	}
	return cur;
}

int main(){
	vector<node*> container = generateRandomLengthLinkedList(4, 10, 10);
	for(int i = 0; i < static_cast<int>(container.size()); i += 2){
		displayLinkedList(container[i], "add1");
		displayLinkedList(container[i+1], "add2");
		node * res = addTwoLists(container[i], container[i+1]);
		displayLinkedList(res, "sum");
		deleteList(res);
	}
	return 0;
}
