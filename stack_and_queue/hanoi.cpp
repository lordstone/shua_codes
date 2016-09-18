#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hanoi{
public:

	Hanoi(int input){
		n_pieces = input > 0 ? input : 3;
		init();
	}
	
	void result(){
		HanoiExpress(n_pieces, 0, 1, 2);
	}

	void HanoiExpress(int n, int from, int buffer, int to){
		if(n == 1){
			cout << "Move " << n << " from " << from << " to " << to << " ." << endl;
			move(from, to);
		}else{
			HanoiExpress(n-1, from, to, buffer);
			cout << "Move " << n << " from " << from << " to " << to << " ." << endl;
			move(from, to);
			HanoiExpress(n-1, buffer, from, to);
		}
	}

	void display(){
		for(int j = 0; j < 3; ++j){
			cout << "Number " << j+1 << " Tower" << endl;
			cout << "|-" ;
			for(auto i = mystk[j].begin(); i != mystk[j].end(); ++i){
				cout << *i << "-";
			}
			cout << "|" << endl;
		}
	}

private:
	int n_pieces;
	vector<int> mystk [3];

	void move(int from, int to){
		if(!mystk[from].empty()){
			if(mystk[to].empty() or mystk[from].back() < mystk[to].back()){
				mystk[to].push_back(mystk[from].back());
				mystk[from].pop_back();
			}
		}
	}

	void init(){
		for(int i = n_pieces; i > 0; --i){
			mystk[0].push_back(i);
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
	h.display();
	h.result();
	h.display();
	return 0;
}
