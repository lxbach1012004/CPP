#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int value){
	int midIndex = (end + start) / 2;
	if(value == arr[midIndex]) return midIndex;
	if(value < arr[midIndex]) return binarySearch(arr, start, midIndex - 1, value);
	if(value > arr[midIndex]) return binarySearch(arr, midIndex + 1, end, value);
}

int main(){
	int arr[100] = {1, 3, 5, 10, 29, 30, 44, 77, 345, 435, 999};
	cout << binarySearch(arr, 0, 10, 999);
}

