#include <iostream>
#include <vector>
using namespace std;

void rellena(int i, int j, int n, int m, int veces, vector<vector <int> > &matAux){

	int x = i+veces;
	int z = j+veces;

	for(int a = i; a < x; a++){
		for(int b = j; b < z; b++){
			if(a < n && b < m && a > -1 && b > -1){
				matAux[a][b] = 1;
			}
		}
	}
}

int main(){

	int n,m;
	cin>>n>>m;
	int cont=0;

	vector<vector <int> > mat(n,vector<int>(m,0));
	vector<vector <int> > matAux(n,vector<int>(m,0));

	//inicializar matriz
	for(int i = 0; i < n; i++){
		for(int j=0; j < m; j++){
			cin>>mat[i][j];
		}
	}

	//procecedimiento de explosiones
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] != 0){
				if(mat[i][j] == 1) rellena((i-1), (j-1), n, m, 3, matAux );
				if(mat[i][j] == 2) rellena((i-2), (j-2), n, m, 5, matAux );
				if(mat[i][j] == 3) rellena((i-3), (j-3), n, m, 7, matAux );
			} 
		}
	}
	
	//contar 0's
	for(int i = 0; i < n; i++){
		for(int j=0; j < m; j++){
			if(matAux[i][j] == 0) cont++;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j=0; j < m; j++){
			cout<<matAux[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<cont<<endl;

	return 0;
}