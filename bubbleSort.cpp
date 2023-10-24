#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
	if(n == 0) return;
	for(int i = 0; i < n - 1; i++)
		if(arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);
	bubbleSort(arr, n - 1);
}

int main(){
	int n, arr[1000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	bubbleSort(arr, n);
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
