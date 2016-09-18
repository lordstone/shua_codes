#include <iostream>
#include <vector>

using namespace std;

class ThreeStacks{
public:

	ThreeStacks(){
		for(int i = 0; i < 3; ++i)
			pt[i] = 0;
	}

	void clear(int index){
		while(isLargest(index)){
			for(int i = 0; i < 3; ++i)
				array.pop_back();
			pt[index] --;
		}
		pt[index] = 0;
	}

	void clearAll(int index){
		for(int i = 0; i < 3; ++i){
			pt[index] = 0;
		}
		array.clear();
	}

	void push(int item, int index=0){
		if(index < 0 || index > 2) return;
		int insert_pt = pt[index]++ * 3 + index;
		if(insert_pt >= static_cast<int>(array.size())){
			array.push_back(0);
			array.push_back(0);
			array.push_back(0);
		}
		array[insert_pt] = item;
	}

	int pop(int index=0){
		if(index < 0 || index > 2) return -1;
		if(pt[index] == 0) return -1;
		int pop_pt = --pt[index] * 3 + index;
		int retval = array[pop_pt];
		if(isLargest(index)){
			for(int i = 0; i < 3; ++i)
				array.pop_back();
		}
		return retval;
	}

private:
	vector<int> array;
	int pt[3];
	
	bool isLargest(int index){
		for(int i = 0; i < 3; ++i){
			if(i != index){
				if(pt[index] <= pt[i])
					return false;
			}
		}
		return true;
	}
};

int main(){
	ThreeStacks s;
	cout << "Test three stack " << endl;
	for(int i = 0; i < 3; ++ i){
		for(int j = 0; j < 5; ++j){
			int ins = rand() % 100;
			cout << "Push " << ins << " into the " << i << "th stack." << endl;
			s.push(ins, i); 
		}
	}
	for(int i = 0; i < 3; ++ i){
		for(int j = 0; j < 5; ++j){
			int ins = s.pop(i);
			cout << "Pop from the " << i << "th stack: " << ins << endl;
		}
	}	
	for(int i = 0; i < 4; ++ i){
		for(int j = 0; j < 3; ++j){
			int ins = rand() % 100;
			cout << "Push " << ins << " into the " << j << "th stack." << endl;
			s.push(ins, j); 
		}
	}
	for(int i = 0; i < 4; ++ i){
		for(int j = 0; j < 3; ++j){
			int ins = s.pop(j);
			cout << "Pop from the " << j << "th stack: " << ins << endl;
		}
	}

	return 0;
}
