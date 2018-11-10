#include <iostream>
using namespace std;

int find(){

	int n, zeroes=0, ones=0;
	string str;
	cin>>n;
	while(n<1 || n>200000) cin>>n;
	cin>>str;

	for(int i=0; i<=n; i++){
		if(str[i] == '0') zeroes++;
		if(str[i] == '1') ones++;
	}

	return abs(zeroes - ones);
}

int main(){
	cout<<find()<<endl;
	return 0;
}