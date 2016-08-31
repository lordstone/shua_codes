#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<vector<int>> generateInputMatrix(int dim = 3){
	vector<vector<int>> mat;
	for(int i = 0; i < dim; ++ i ){
		vector<int> row;
		for(int j = 0; j < dim; ++ j ){
			int tmp = rand() % 10;
			row.push_back(tmp);
		}
		mat.push_back(row);
	}
	return mat;
}

void outputMat(vector<vector<int>> mat){
	cout << "Output a matrix:" << endl;
	for(vector<int> i : mat){

		for(int j : i){
			cout << j;
			cout << " ";
		}
		cout << endl;
	}
}

void flipMat(vector<vector<int>> * mat){
	int n = (*mat).size();
	for(int i = 0; i < n / 2 ; ++ i){
		int first = i;
		int last = n - 1 - i;
		for(int j = first; j < last; ++ j){
			int offset = j - first;
			int tmp = (*mat)[first][j];
			(*mat)[first][j] = (*mat)[last-offset][first];
			(*mat)[last-offset][first] = (*mat)[last][last - offset];
			(*mat)[last][last - offset] = (*mat)[j][last];
			(*mat)[j][last] = tmp;
		}//end for j
	} //end for i
}



int main(){
	
	int dim = 0;

	cin >> dim;

	vector<vector<int>> inputMatrix = generateInputMatrix(dim);	

	outputMat(inputMatrix);

	flipMat(&inputMatrix);

	cout << "Flipped:" << endl;

	outputMat(inputMatrix);

	return 0;

}
