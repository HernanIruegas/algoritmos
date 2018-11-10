#include <iostream>

using namespace std;

bool isItPrime(int n){
	bool isPrime = true;

	for(int i = 2; i <= n / 2; i++){
		if(n % i == 0){
        	isPrime = false;
        	break;
    	}
	}
	return isPrime;
}

void rangeOfPrimes(int n){
	
	if(isItPrime(n)){
		cout<<n<<" "<<n<<endl;
	}
	else{
		int j = n + 1;
		n-=1;
		while(!isItPrime(n)){
			n-=1;
		}
		while(!isItPrime(j)){
			j+=1;
		}
		cout<<n<<" "<<j<<endl;
	}			
}

int main(){

	int m, n;
	cin >> m; //la cantidad de números que quieres checar
	while(m>0){
		cin >> n;
		rangeOfPrimes(n);
		m--;
	}

	return 0;
}