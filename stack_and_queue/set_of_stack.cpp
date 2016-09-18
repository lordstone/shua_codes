#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks {
public:
	SetOfStacks(int b_size=10){
		bucket_size = b_size;
		stack<int> si;
		buckets.push_back(si);
	}

	void push(int n){
		if(static_cast<int>(buckets[buckets.size()-1].size()) < bucket_size){
			buckets[buckets.size()-1].push(n);
		}else{
			stack<int> si;
			buckets.push_back(si);
			buckets[buckets.size()-1].push(n);
		}
	}
	
	int pop(){
		while(buckets.size()-1 != 0 && buckets[buckets.size()-1].empty()){
			buckets.pop_back();
		}
		if(buckets.size()-1 == 0 && buckets[0].empty()){
			return -1;
		}
		int retint = buckets[buckets.size()-1].top();
		buckets[buckets.size()-1].pop();
		if(buckets.size()-1 > 0 && buckets[buckets.size()-1].empty()){
			buckets.pop_back();
		}
		return retint;
	}

	int popAt(int index){
		if((static_cast<int>(buckets.size())-1) < index) return -1;
		if(buckets[index].empty()) return -1;
		int retint = buckets[index].top();
		buckets[index].pop();
		if(buckets[index].empty()){
			buckets.erase(buckets.begin() + index);
		}
		return retint;
	}

private:
	vector<stack<int>> buckets;
	int bucket_size;
};

int main(){
	srand(10);
	int push_times = 25; //rand() % 15 + 5;

	SetOfStacks ss(5);

	cout << "Pushing: " ;
	for(int i = 0; i < push_times; i ++){
		// int push_int = rand() % 50;
		ss.push(i);
		cout << "push: " << i << ". " << endl;
	}
	cout << endl;

	for(int i = 0; i < push_times / 2; i ++){
		int push_int = rand() % 5;
		int poped = ss.popAt(push_int);
		cout << "poped at: " << push_int << " .Result: " <<  poped << ". " << endl;
	}
	cout << endl;

	cout << "Poping: " ;
	for(int i = 0; i < push_times / 2; i ++){
		int pv = ss.pop(); 
		cout << "pop: " << pv << ". " << endl;
	}
	cout << endl;

	return 0;
}
