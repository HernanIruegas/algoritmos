#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void salvadora(int left, int right, vector<string> &res, vector<vector<int> > &tieneK){

    if(right - left != 0){
        string aux = res[left-1];
        res[left-1] = "(";
        res[left-1] += aux;
        res[right-1] += ")";
        int mult = tieneK[left][right];
        salvadora(left, mult, res, tieneK);
        salvadora(mult+1, right, res, tieneK);
    }
}

int main() {

    
    int N, min, aux, j, k, dim, posMin; // numero de matrices
    cin >> N;
    vector<int> dimensiones;
    vector<string> res;
    for(int i=0; i < N; i++){
        string b = "a";
        b[0] = char(i+65);
        res.push_back(b);
    }

    int D[N+2][N+2];
    vector<vector<int> > tieneK (N+2,vector<int>(N+2));


    for(int i=0; i < N+1; i++){
        cin>>dim;
        dimensiones.push_back(dim);
    }

    int a = N+2;
    for(int i=0; i<a; i++ ){
        for(int j=0; j<a; j++){
            D[i][i] = 0; 
            tieneK[i][j] = 0; 
        }
    }

    for(int diag = 1; diag <= N-1; diag++) {
        for(int i = 1; i <= N-diag; i++) {
            j = i+diag;
            k = i;
            min = INT_MAX;
            while(k < j) {
                aux = D[i][k] + D[k+1][j] + (dimensiones[i-1] * dimensiones[k] * dimensiones[j]);
                if(aux < min){
                    min = aux;
                    posMin = k;
                }
                k++;
            }
            D[i][j] = min;
            tieneK[i][j] = posMin;
        }
    }

    salvadora(1, N, res, tieneK);

    for(int i=0; i<res.size(); i++){
        cout<<res[i];
        if(i<res.size()-1){
            cout<<" X ";
        }
    }

    return 0;
}