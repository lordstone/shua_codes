#include <stdio.h>
#include "linked_list.h"

using namespace std;

void order_by_x(node*& head, int x){
	node * equal_bigger = nullptr;
	node * eb_cur = nullptr;
	node * smaller = nullptr;
	node * s_cur = nullptr;
	node * cur = head;
	while(cur){
		if(cur -> val >= x){
			if(eb_cur){
				eb_cur -> next = new node(cur -> val);
				eb_cur = eb_cur -> next;
			}else{
				equal_bigger = new node(cur -> val);
				eb_cur = equal_bigger;
			}
		}else{
			if(s_cur){
				s_cur -> next = new node(cur -> val);
				s_cur = s_cur -> next;
			}else{
				smaller = new node(cur -> val);
				s_cur = smaller;
			}
		}
		node * to_delete = cur;
		cur = cur -> next;
		delete to_delete;
	}
	if(smaller){
		head = smaller;
		s_cur -> next = equal_bigger;
	}else{
		head = equal_bigger;
	}
}

int main(){
	vector<node*> container = generateLinkedList(3, 100, 10);
	for(auto i : container){
		displayLinkedList(i, "Origin");
		order_by_x(i, 5);
		displayLinkedList(i, "New");
	}
	return 0;
}
