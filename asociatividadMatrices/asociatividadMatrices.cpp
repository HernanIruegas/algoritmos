#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int sum(int a, int b, vector<int> d) {
    int acum = 0;
    for(int i = a; i <= b; i++)
        acum+=d[i];
    return acum;
}

int main() {

	// l = length
	// N = cuts

    int l, N, j, k, min, aux, x, previous;
    cin >> l;
    while(l != 0) {
        previous = 0;
        cin >> N;
        vector<int> d;
        d.push_back(1);
        int D[N+1][N+1];
        for(int i = 1; i <= N+1; i++) {
            if(i <= N) 
            	cin >> x;
            (i != N+1)? d.push_back(x-previous) : d.push_back(l-x);
            previous = x;
            D[i][i] = 0;
        }
        
        for(int diag = 1; diag <= N; diag++) {
            for(int i = 1; i <= N+1-diag; i++) {
                j = i+diag;
                k = i;
                min = INT_MAX;
                while(k < j) {
                    aux = D[i][k] + D[k+1][j];
                    if(aux < min) min = aux;
                    k++;
                }
                D[i][j] = min + sum(i,j,d);
            }
        }
        cout << "The minimum cutting is " << D[1][N+1] << "." << endl;
        cin >> l;
    }

    return 0;
}