#include "node.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int maxLevel(bnode * root){
	if(!root) return 0;
	return max(maxLevel(root -> left), maxLevel(root -> right)) + 1;
}

bool isBalanced(bnode * root){
	if(!root) return true;
	int leftLvl = maxLevel(root -> left);
	int rightLvl = maxLevel(root -> right);
	return abs(leftLvl - rightLvl) <= 1;
}

int main(int argc, char* argv []){
	int rseed = argc > 1 ? stoi(argv[1]) : 1;
	srand(rseed);
	for(int i = 0; i < 3; ++i){
		bnode * bt = generateRandomBinaryTree(5);
		displayBinaryTree(bt);
		cout << (isBalanced(bt) ? "Balanced" : "Unbalanced") << endl;
	}
	return 0;
}
