// Eduardo de la Garza A01380293
// Hernan Iruegas A00817021
#include <iostream>
#include <climits>
#include <vector>
using namespace std;


void partTwo(int &N, int &min, int &min2, int &max, int &max2, int L[N+1], bool boo[N+1], int &w, int m[N+1]){

    for(int y = 0; y < N-1; y++) {
        min = INT_MAX;
        for(int i = 2; i <= N; i++) {
            if(boo[i] && L[i]<=min) {
                min = L[i];
                min2 = i;
            }
        }
        for(int i = 2; i <=N; i++)
            if(L[min2] + m[min2][i] < L[i]) L[i] = L[min2] + m[min2][i];
        
        boo[min2] = false;
    }
    
    max = 0;
    for(int i = 2; i <=N; i++) {
        if(max < L[i]) {
            max = L[i];
            max2 = i;
        }
    }
    cout << "Case " << w+1 << ": " << char(max2+64) << endl;
}

void partOne(int &N, int &M, int &c, char &a, char &b, int &w, int &min, int &min2, int &max, int &max2){

    int m[N+1][N+1], L[N+1];
    bool boo[N+1];

    for(int i = 1; i <= N; i++) {
        boo[i] = true;
        for(int j = 1; j <=N; j++) m[i][j] = (i==j)? 0: INT_MAX;
    }
    
    for(int i = 0; i < M;i++) {
        cin >> a >> b >> c;
        m[a-64][b-64] = m[b-64][a-64] = c;
    }
    
    for(int i = 2; i <= N; i++) L[i] = m[1][i];

    partTwo(N, min, min2, max, max2, L, boo, w, m);

}

int main() {
    
    int N, M, c, X;
    char a, b;
    int min, min2, max, max2;
    cin >> X;

    for(int w = 0; w < X; w++) {
        cin >> N >> M;
        partOne(N, M, c, a, b, w, min, min2, max, max2);
    }

    return 0;
}