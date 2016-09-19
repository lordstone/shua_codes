#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct node {
	int val;
	vector<node*> children;
	node(int v) : val(v), children() {}
};

struct bnode {
	int val;
	bnode * left;
	bnode * right;
	bnode(int v) : val(v), left(nullptr), right(nullptr) {}
};

bnode * generateFullBinaryTree(int level=1){
	if(level < 1) return nullptr;
	bnode * root = new bnode (0);
	root -> left = generateFullBinaryTree(level - 1);
	root -> right = generateFullBinaryTree(level - 1);
	return root;
}

void deleteBinaryTree(bnode * root){
	if(!root) return;
	if(root -> left) deleteBinaryTree(root -> left);
	if(root -> right) deleteBinaryTree(root -> right);
	delete root;
}

bnode * generateRandomBinaryTree(int level=1, int range=50, int pnode=100){
	if(level < 1) return nullptr;
	bool hasPt = ((rand() % 99 + 1) <= pnode);
	if(hasPt){
		int n = rand() % range;
		bnode * root = new bnode (n);
		int npnode = pnode <= 50 ? 50 : pnode - 15;
		root -> left = generateRandomBinaryTree(level - 1, range, npnode);
		root -> right = generateRandomBinaryTree(level - 1, range, npnode);
		return root;
	}else{
		return nullptr;
	}	
}

bnode * generateRandomFullBinaryTree(int level=1, int range=50){
	if(level < 1) return nullptr;
	int n = rand() % range;
	bnode * root = new bnode (n);
	root -> left = generateRandomFullBinaryTree(level - 1, range);
	root -> right = generateRandomFullBinaryTree(level - 1, range);
	return root;
}

void displayBinaryTree(bnode * root){
	queue<pair<bnode*,int>> q;
	q.push(make_pair(root, 0));
	cout << "Binary Tree: " << endl;
	int cur_level = -1;
	while(!q.empty()){
		bnode * cur = q.front().first;
		int q_level = q.front().second;
		q.pop();
		if(cur_level < q_level){
			cur_level = q_level;
			cout << "|" << endl << "|-" ;
		}
		if(cur)
			cout << cur -> val << "-";
		else
			cout << "()-" ;
		if(cur){
			q.push(make_pair(cur -> left, q_level + 1));
			q.push(make_pair(cur -> right, q_level + 1));
		}
	}
	cout << "|" << endl;
}

