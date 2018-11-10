#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){

	pair<string, string> key;
	map<pair<string, string>, int> relaciones;
	map<string, int> parientes;
	map<int, vector<string>> resultado;
	priority_queue<int> orden;
	int n, edad;
	string padre, hijo;

	//numero de descendientes
	cin>>n;

	parientes["Berny"] = 100;

	for(int iA=0;iA < n ;iA++){
		cin >> padre >> hijo >> edad;
		relaciones[make_pair(padre,hijo)] = edad;
	}

    for(int i = 0; i < relaciones.size(); i++){
		for(std::map<pair<string, string>, int>::iterator it = relaciones.begin(); it != relaciones.end(); it++){
			// si existe
			if(parientes.find(it->first.first) != parientes.end()){
				parientes[it->first.second] = parientes[it->first.first] - it->second;
			}
		}
	}

	for(auto elem : parientes){
		resultado[elem.second].push_back(elem.first);
		orden.push(elem.second);
	}

	
	orden.pop();
	while(!orden.empty()){
		int aux = orden.top();
		orden.pop();
		for(int x = 0; x < resultado[aux].size(); x++){
			cout<<resultado[aux][x] << " " << aux;
		}
		cout<<endl;
	}

	return 0;
}
