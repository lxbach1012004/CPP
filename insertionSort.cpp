#include<bits/stdc++.h>
using namespace std;
//
//void insertionSort(int arr[], int n){
//	for(int i = 1; i < n; i++){
//		while(arr[i] < arr[i - 1] && i > 0){
//			swap(arr[i], arr[i - 1]);
//			i--;
//		}
//	}
//	
//}

void insertionSort(int arr[], int n){
	for (int sortedSize = 1; sortedSize < n; sortedSize++) {
		for (int i = sortedSize; i > 0; i--) {
			if (arr[i] < arr[i - 1])
				swap(arr[i], arr[i - 1]);
			else break;
		}
	}
}

int main(){
	int n, arr[1000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	insertionSort(arr, n);
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
