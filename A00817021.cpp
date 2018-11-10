#include <iostream>
#include <climits>
#include <vector>
using namespace std;


void d(int N, int min, int min2, vector<bool> &boo, vector<int> &m2, vector<int> &m3, vector<vector<int> > &m){

    for(int y = 0; y < N-1; y++) {
        min = INT_MAX;
        for(int i = 2; i <= N; i++) {
            if(boo[i] && m2[i]<=min) {
                min = m2[i];  
                min2 = i;
            }
        }
        for(int i = 2; i <=N; i++) {
            if(m2[min2] + m[min2][i] < m2[i]) {
                m2[i] = m2[min2] + m[min2][i];
                m3[i] = min2;
            }
        }
        boo[min2] = false;
    }
}


int main() {

    int N, M, a, b, c, min = INT_MAX, min2, cont, aux;
    cin >> N >> M;
    vector<vector<int> > m (N+1,vector<int>(N+1));
    vector<int> m2;
    vector<int> m3;
    vector<bool> boo;

    m2.push_back(0);
    m2.push_back(0);
    m3.push_back(0);
    m3.push_back(0);
    boo.push_back(0);

    for(int i = 1; i <= N; i++) {
        boo[i] = true;
        for(int j = 1; j <=N; j++) {
            m[i][j] = (i==j)? 0: INT_MAX;
        }
    }
    
    for(int i = 0; i < M;i++) {
        cin >> a >> b >> c;
        m[a][b] = m[b][a] = c;
    }

    for(int i = 2; i <= N; i++) {
        m2.push_back(m[1][i]);
        m3.push_back(1);
    }

    d(N, min, min2, boo, m2, m3, m);
    
    for(int i = 2; i <=N; i++) {
        cont = 0; aux = m3[i];
        while(aux!=1) {
            aux = m3[aux];
            cont++;
        }
        cout<<i<<" "<<m2[i]<<" "<<cont<<endl;
    }

    return 0;
}