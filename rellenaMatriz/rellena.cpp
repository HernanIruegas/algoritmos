#include <iostream>
using namespace std;

void rellenaMatriz(){

	int arr[4] = {1,3,5,7};
	int mat[4][4];

	for(int i=0; i<4; i++){
		mat[i][i] = arr[i];
		for(int j=i+1; j<4; j++){
			mat[i][j] = mat[j][i] = mat[i][j-1] + arr[j];
		}
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}



int main(){

	rellenaMatriz();

	return 0;
}