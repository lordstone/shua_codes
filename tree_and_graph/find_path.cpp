#include "node.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

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
