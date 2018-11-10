#include <iostream>
using namespace std;

void Llena(int min1, int min2, int max1, int max2, int aux, int aux1, int &cont, int mat[4][4]) {
    if(min2 == min1)
        return;
    cont++;
    int jmitad = (min1 + min2) / 2;
    int imitad = (max1 + max2) / 2;
    int cont2 = cont;
    int cuadrante;
    
    if (aux <= jmitad) {
        if (aux1 <= imitad) cuadrante = 1;
        else cuadrante = 3;
    }
    else {
        if (aux1 <= imitad) cuadrante = 2;
        else cuadrante = 4;
    }
    
    if(cuadrante != 1) mat[jmitad][imitad] = cont2;
    if(cuadrante != 2) mat[jmitad+1][imitad] = cont2;
    if(cuadrante != 3) mat[jmitad][imitad+1] = cont2;
    if(cuadrante != 4) mat[jmitad+1][imitad+1] = cont2;

    if(cuadrante==1) Llena(min1, jmitad, max1, imitad, aux, aux1, cont, mat);
    else Llena(min1, jmitad, max1, imitad, jmitad, imitad, cont, mat);
    
    if(cuadrante==2) Llena(jmitad +1, min2, max1, imitad, aux, aux1, cont, mat);
    else Llena(jmitad + 1, min2, max1, imitad, jmitad+1, imitad, cont, mat);
    
    if(cuadrante ==3) Llena(min1, jmitad, imitad+1, max2, aux, aux1, cont, mat);
    else Llena(min1, jmitad, imitad+1, max2, jmitad, imitad+1, cont, mat);
    
    if(cuadrante ==4) Llena(jmitad + 1, min2, imitad+1, max2, aux, aux1, cont, mat);
    else Llena(jmitad + 1, min2, imitad+1, max2, jmitad+1, imitad+1, cont, mat);
}

int main(int argc, const char * argv[]) {
    
    int cont = 0, x=3, y=2;
    const int N=4;
    
    int mat[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mat[i][j] = 0;
        }
    }

    Llena(0, N-1, 0, N-1, x, y, cont, mat);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(mat[j][i] < 10) cout << " ";
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
