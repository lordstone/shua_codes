#include "linked_list.h"

using namespace std;

node * findLastKNode(int k, node * head){
	node * fast_cur = head;
	node * slow_cur = nullptr;
	int slow_p = 0;
	while(fast_cur){
		fast_cur = fast_cur -> next;
		if(slow_p++ == k){
			slow_cur = head;
		}else if(slow_p > k){
			slow_cur = slow_cur -> next;
		}
	}
	return slow_cur;
}

int main(){

	vector<node*> container = generateLinkedList(2, 100);
	for( auto i : container){
		displayLinkedList(i);
		node * findK = findLastKNode(50, i);
		cout << "the 50th node is:" << findK -> val << endl;
	}
	return 0;

}

