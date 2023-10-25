#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i])
				swap(arr[j], arr[i]);
		}
	}
}

int main(){
	int arr[10001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    	cin >> arr[i];
    selectionSort(arr, n);
    for(int i = 0; i < n; i++)
    	cout << arr[i] << " ";
}
