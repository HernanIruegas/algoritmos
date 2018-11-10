// Eduardo de la Garza A01380293
// Hernan Iruegas A00817021
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void res(int &max, int &N, int L[N+1], int &max2, int &w){

    max = 0;
    for(int i = 2; i <=N; i++) {
        if(max < L[i]) {
            max = L[i];
            max2 = i;
        }
    }
    cout << "Case " << w+1 << ": " << char(max2+64) << endl; 
}

int main() {
    
    char a, b;
    int N, M, c, X;

    cin >> X;

    int min, min2, max, max2;

    for(int w = 0; w < X; w++) {
        cin >> N >> M;
        
        bool boo[N+1];
        
        for(int i = 1; i <= N; i++) {
            boo[i] = true;
        }

        int m[N+1][N+1];

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <=N; j++){
                m[i][j] = (i==j)? 0: 99999;
            } 
        }
        
        for(int i = 0; i < M; i++) {
            cin>>a>>b>>c;
            m[a-64][b-64] = m[b-64][a-64] = c;
        }
        
        int L[N+1];

        for(int i = 2; i <= N; i++){
           L[i] = m[1][i]; 
        } 
        
        for(int y = 0; y < N-1; y++) {
            min = 99999;
            for(int i = 2; i <= N; i++) {
                if(boo[i] && L[i]<=min) {
                    min = L[i];
                    min2 = i;
                }
            }

            for(int i = 2; i <=N; i++){
                if(L[min2] + m[min2][i] < L[i]) 
                    L[i] = L[min2] + m[min2][i];
            }

            boo[min2] = false;
        }
        
        res(max, N, L, max2, w);
    }
    
    return 0;
}