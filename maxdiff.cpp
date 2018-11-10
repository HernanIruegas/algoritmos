#include <vector>
#include <map>
#include <iostream>
#include <climits>
using namespace std;


int main(){

	vector<int> arr = { 1, 4, 7, 15 };

	int max = INT_MIN, min = INT_MAX;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] > max) max = arr[i];
		if(arr[i] < min) min = arr[i];
	}

	cout<<max-min<<endl;

	return 0;
}



