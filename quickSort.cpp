#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end){
	int pivotIndex = start;
	for(int i = start; i < end; i++){
		if(arr[i] < arr[end]){
			swap(arr[i], arr[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(arr[pivotIndex], arr[end]);
	return pivotIndex;
}

void quickSort(int arr[], int start, int end){
	if(start >= end) return;
	int pivot = partition(arr, start, end);
	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);
}

int arr[100001];

int main(){
    int n, 
    cin >> n;
    for(int i = 0; i < n; i++)
    	cin >> arr[i];
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
    	cout << arr[i] << " ";
}
