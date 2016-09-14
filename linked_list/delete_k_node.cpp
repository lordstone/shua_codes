#include "linked_list.h"

using namespace std;

void deleteKthNode(node * target){
	node * cur = target;
	node * prev = nullptr;
	do{
		if(cur -> next){
			cur -> val = cur -> next -> val;
			prev = cur;
			cur = cur -> next;
		}else{
			if(prev){
				delete prev -> next;
				prev -> next = nullptr;
				return;
			}else{
				delete target;
				return;
			}
		}
	}while(cur);
}

int main(){
	vector<node*> container = generateLinkedList(5, 25);
	for(auto i : container){
		displayLinkedList(i);
		int deleteK = rand() % 24 + 1;
		node * cur = i;
		cout << "delete:" << deleteK  << endl;
		for(int j = 0; j < deleteK; ++j) cur = cur -> next; 
		deleteKthNode(cur);
		displayLinkedList(i);
	}
	return 0;
}

