#include <iostream>

using namespace std;


char seRepite2(string str, int inf, int sup){
	
	if(inf == sup) return str[inf];
	int mit = (inf + sup) / 2;

	if(str[mit] == str[mit-1]){
		if((mit-inf)%2==0)return seRepite2(str, inf, mit);
			return seRepite2(str,mit+1, sup);
		}
		if((sup-mit)%2==1) return seRepite2(str, inf, mit-1);
			return seRepite2(str,mit, sup);		
	}

char seRepite(string str){
	return seRepite2(str, 0, str.size()-1);
}

int main(){

	string str;
	cin >> str;
    cout << seRepite(str) <<endl;
    
	return 0;
}

