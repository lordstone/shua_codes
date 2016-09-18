#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
public:

	void push(int n){
		mystk.push(n);
		if(minstk.size() == 0 || n <= minstk.top()){
			minstk.push(n);
		}
	}

	int pop(){
		if(mystk.empty()) return -1;
		int retint = mystk.top();
		mystk.pop();
		if((!minstk.empty()) && (retint == minstk.top())){
			minstk.pop();
		}
		return retint;
	}

	int min(){
		return minstk.empty() ? -1 : minstk.top();
	}

private:
	stack<int> mystk;
	stack<int> minstk;
};

int main(){
	srand(19);
	int push_times = 5; //rand() % 15 + 5;

	MinStack ms;

	cout << "Pushing: " ;
	for(int i = 0; i < push_times; i ++){
		int push_int = rand() % 50;
		ms.push(push_int);
		cout << "push: " << push_int << ". ";
		cout << "min: " << ms.min() << ". ";
	}
	cout << endl;
	cout << "Poping: " ;
	for(int i = 0; i < push_times; i ++){
		int pv = ms.pop(); 
		cout << "pop: " << pv << ". ";
		cout << "min: " << ms.min() << ". ";
	}
	cout << endl;

	return 0;
}
