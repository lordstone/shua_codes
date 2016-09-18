#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
public:

	MaxStack() {
		mymax = -1;
	}

	void push(int val){
		if(mainStk.empty() || (!mainStk.empty() && mymax < val))
			mymax = val;
		mainStk.push(val);
	}

	void pop(){
		if(mainStk.empty()) return;
		dumpDrop(mainStk, auxStk, mymax);
		mymax = auxStk.empty() ? -1 : dumpMax(auxStk, mainStk);
	}

	int top(){	
		return mymax;
	}

	bool isEmpty(){
		return mainStk.empty();
	}

private:
	stack<int> mainStk;
	stack<int> auxStk;
	int mymax;
	void dumpDrop(stack<int> &from, stack<int> &to, int target){
		bool dropped = false;
		while(!from.empty()){
			int tmp = from.top();
			if(tmp == target && !dropped){
				dropped = true;
			}else{
				to.push(from.top());
			}
			from.pop();
		}
	}

	int dumpMax(stack<int> &from, stack<int> &to){
		int max = from.top();
		while(!from.empty()){
			if(from.top() > max) max = from.top();
			to.push(from.top());
			from.pop();
		}
		return max;
	}

};

int main(){
	srand(10);
	int push_times = 25; //rand() % 15 + 5;

	MaxStack ms;

	for(int i = 0; i < push_times; i ++){
		// int push_int = rand() % 50;
		ms.push(i);
		cout << "push: " << i << ". " << endl;
	}
	cout << endl;

	for(int i = 0; i < push_times / 2; i ++){
		int poped = ms.top();
		ms.pop();
		cout << "poped " << poped << "." << endl;
	}
	cout << endl;

	for(int i = 0; i < push_times; i ++){
		// int push_int = rand() % 50;
		ms.push(i);
		cout << "push: " << i << ". " << endl;
	}

	cout << endl;
	for(int i = 0; i < push_times / 2 * 3; i ++){
		int poped = ms.top();
		ms.pop();
		cout << "poped " << poped << "." << endl;
	}
	cout << endl;

	return 0;
}
