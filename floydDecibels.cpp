#include <iostream>
#include <queue>
using namespace std;

int validaDecibeles(int actual, int first, int second){ 

    int aux;
    if(first != INT_MAX && second != INT_MAX){
        if(actual == INT_MAX){
            return (first > second) ? first : second;
        }else{
            aux = (first > second) ? first : second;
            return (actual < aux) ? actual : aux;
        }
    }else{
        return actual;
    }
}

int main() {
    
    int cases, c, s, q, a, b, decibeles, aux, counter;
    queue<int> qu;
    cin >> cases;
    counter = 1;
    
    for(int z = 0; z < cases; z++) {
        for(int n = 0; n < cases; n++) {
            cin >> c >> s >> q;
            int mat[c][c];

            // Inicializar matriz de adyacencias con ceros en diagonal principal y lo demás en infinito
            for(int i = 0; i < c; i ++){
                for(int j = 0; j < c; j++){
                    mat[i][j] = (i==j) ? 0 : INT_MAX;
                }   
            }
                
            // Modificar matriz de adyacencias con decibeles de nodos pegados directamente
            for(int i = 0; i < s; i++) {
                cin >> a >> b >> decibeles;
                mat[a-1][b-1] = mat[b-1][a-1] = decibeles;
            }
            
            for(int i = 0; i < q; i++) {
                cin >> a >> b;
                qu.push(a);
                qu.push(b);
            }
        
            // Modififcar matriz de adyacencias con algoritmo de floyd
            for(int k = 0; k < c; k++){
                for(int i = 0; i < c; i++){
                     for(int j = 0; j < c; j++){
                         if(i!=j)
                            mat[j][i] = validaDecibeles(mat[i][j], mat[i][k], mat[k][j]);
                     }   
                }
            }
                
            //Desplegar resultados
            cout << endl << "Case " << counter << ":" << endl;
            counter++;
            for(int i = 0; i < q; i++) {
                a = qu.front(); 
                qu.pop();
                b = qu.front(); 
                qu.pop();
                aux = mat[a-1][b-1];
                (aux == INT_MAX)? cout << "no path" << endl : cout << aux << endl;
            }
        }
    }
    return 0;
}