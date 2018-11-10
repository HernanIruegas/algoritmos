#include <vector>
#include <map>
#include <iostream>
#include <climits>
using namespace std;

//Escribe el código en C++ del algoritmo que obtenga la suma de los elementos impares, 
//desde 1 hasta un número n. (1+3+5+7+9+…+n), donde n puede o no ser impar.

int main(){

	vector<int> arr = { 1, 4, 7, 15};

	int sum = 0, aux;

	aux = (arr.size() % 2 != 0) ? arr.size() - 1 : arr.size(); 

	for(int i = 1; i <= aux; i+=2){
		//cout<<i<<endl;
		//cout<<arr[i]<<endl;
		sum += arr[i];
	}

	cout<<sum<<endl;

	return 0;
}






