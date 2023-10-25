#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (i * 2 + 1 >= n)
			continue;
		int trace = i;
		while (trace * 2 + 1 < n) {
			int biggerChild;
			if ((arr[trace * 2 + 1] >= arr[trace * 2 + 2]) || (trace * 2 + 2 >= n))
				biggerChild = trace * 2 + 1;
			else biggerChild = trace * 2 + 2;
			if (arr[trace] <= arr[biggerChild])
				swap(arr[trace], arr[biggerChild]);
			trace = biggerChild;
		}
	}
}

void heapSort(int arr[], int n) {
	heapify(arr, n);
	for (int heapSize = n - 1; heapSize > 0; heapSize--) {
		swap(arr[0], arr[heapSize]);
		int trace = 0;
		while (trace * 2 + 1 < heapSize) {
			int biggerChild;
			if ((arr[trace * 2 + 1] >= arr[trace * 2 + 2]) || (trace * 2 + 2 >= heapSize))
				biggerChild = trace * 2 + 1;
			else biggerChild = trace * 2 + 2;
			if (arr[trace] < arr[biggerChild])
				swap(arr[trace], arr[biggerChild]);
			trace = biggerChild;
		}
	}
}

int main() {
	int n, arr[1000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	heapSort(arr, n);
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

