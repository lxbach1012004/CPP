#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int high) {
	static int b[10005];
	int mid = (low + high) / 2;
	int i = low, j = mid + 1, k = 0;
	
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			b[k++] = arr[i];
			i++;
		} else {
			b[k++] = arr[j];
			j++;
		}
	}
	
	for (; i <= mid; i++) {
		b[k++] = arr[i];
	}
	
	for (; j <= high; j++) {
		b[k++] = arr[j];
	}
	
	for (int x = low; x <= high; x++) 
		arr[x] = b[x - low];
}

void mergeSort(int arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, high);
	}
}

int main(){
    int n, arr[10005];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
