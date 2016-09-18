#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Hanoi{
public:
	Hanoi(int input){
		n_pieces = input > 0 ? input : 3;
	}
	
	void result(){
		// init();
		HanoiExpress(n_pieces, 0, 1, 2);
	}

	void HanoiExpress(int n, int from, int buffer, int to){
		if(n == 1){
			cout << "Move " << n << " from " << from << " to " << to << " ." << endl;
		}else{
			HanoiExpress(n-1, from, to, buffer);
			cout << "Move " << n << " from " << from << " to " << to << " ." << endl;
			HanoiExpress(n-1, buffer, from, to);
		}
	}

private:
	int n_pieces;
	stack<int> mystk [3];

	void init(){
		for(int i = n_pieces; i > 0; --i){
			mystk[0].push(i);
		}
	}
};

int main(int argc, char* argv []){
	
	int n = 3;
	if(argc > 1){
		try{
			n = stoi(argv[1]);
		}catch(int e){
			n = 3;
		}
	}	
	Hanoi h (n);
	h.result();
	return 0;
}
