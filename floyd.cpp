#include <iostream>
#include <climits>
using namespace std;

int minimo(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    
    //n = #nodos Sirve para inicializar matriz de adyacencias
    //m = #arcos
    //q = #queries
    //a = Nodo Ini
    //b = Nodo Fin
    //c = Costo de Arco

    int n, m, q, a, b, c, aux;
    cin >> n >> m >> q;
    int iMatAd[n][n];
    
    //matriz de infinitos con ceros en diagonal principal
    //inicialización de la matriz de adyacencias
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) iMatAd[i][j] = 0;
            else iMatAd[i][j] = INT_MAX;
        }
    }
    
    //Nodo inicial -> Nodo final -> Costo de arco
    //construcción de la matriz de adyacencias
    //incluye costos para los nodos que están conectados
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        iMatAd[a][b] = c;
    }
    
    //construyes la matriz de adyacencias con el camino más corto usando el algortimo de floyd
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j++) {
                aux = (iMatAd[i][k] == INT_MAX || iMatAd[k][j] == INT_MAX) ? INT_MAX : iMatAd[i][k] + iMatAd[k][j];
                
                iMatAd[i][j] = minimo(iMatAd[i][j], aux);
            }
        }
    }
    
    //despliega matiz de adyacencias terminada
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(iMatAd[i][j] == INT_MAX) cout << -1 << "\t ";
            else cout << iMatAd[i][j] << " \t";
        }
        cout << endl;
    }
    
//    for(int y = 0; y < q; y++) {
//        cin >> a >> b;
//        cout << iMatAd[a][b];
//    }
    
    return 0;
}