#include <iostream>
#include <stack>

using namespace std;

class TwoStackQueue {
public:

	void push(int val){
		mainStk.push(val);
	}

	void pop(){
		dump(mainStk, tmpStk);
 		if(!tmpStk.empty()) tmpStk.pop();
		dump(tmpStk, mainStk);	
	}

	int front(){
		dump(mainStk, tmpStk); 	
		int retint = tmpStk.empty() ? -1 : tmpStk.top();
		dump(tmpStk, mainStk);
		return retint;
	}

private:
	stack<int> mainStk;
	stack<int> tmpStk;

	void dump(stack<int> &from, stack<int> &to){
		while(!from.empty()){
			to.push(from.top());
			from.pop();
		}
	}
};

int main(){
	srand(10);
	int push_times = 25; //rand() % 15 + 5;

	TwoStackQueue tsq;

	for(int i = 0; i < push_times; i ++){
		// int push_int = rand() % 50;
		tsq.push(i);
		cout << "push: " << i << ". " << endl;
	}
	cout << endl;

	for(int i = 0; i < push_times / 2; i ++){
		int poped = tsq.front();
		tsq.pop();
		cout << "poped " << poped << "." << endl;
	}
	cout << endl;

	for(int i = 0; i < push_times; i ++){
		// int push_int = rand() % 50;
		tsq.push(i);
		cout << "push: " << i << ". " << endl;
	}

	cout << endl;
	for(int i = 0; i < push_times / 2 * 3; i ++){
		int poped = tsq.front();
		tsq.pop();
		cout << "poped " << poped << "." << endl;
	}
	cout << endl;

	return 0;
}
