#include<iostream>
using namespace std;

int maxElement(int arr[], int n){
	if(n<=0)
		return -1;
	int currMax = arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]>currMax){
			currMax = arr[i];
		}
	}
	return currMax;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Maximum value in the array is "<<maxElement(arr, n);
}
