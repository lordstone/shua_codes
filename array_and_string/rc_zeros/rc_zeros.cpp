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

void rcZerosMat(vector<vector<int>> * mat){

	int n = (*mat).size();

	vector<bool> row_map;
	vector<bool> col_map;

	row_map.assign(n, false);
	col_map.assign(n, false);

	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < n; ++ j){
			if((*mat)[i][j] == 0){
				row_map[i] = true;
				col_map[j] = true;
			}
		}
	}

	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < n; ++ j){
			if(row_map[i] || col_map[j]){
				(*mat)[i][j] = 0;
			}
		}
	}

}



int main(){
	int dim = 0;
	cout << "input dimension:";
	cin >> dim;
	vector<vector<int>> inputMatrix = generateInputMatrix(dim);	
	outputMat(inputMatrix);
	rcZerosMat(&inputMatrix);
	cout << "Zeroed:" << endl;
	outputMat(inputMatrix);
	return 0;
}
