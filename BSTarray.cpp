#include<bits/stdc++.h>
using namespace std;

int arrSize = 0;

void insert(int arr[], int value) {
	int index = 0;
	while (arr[index] != 0) {
		if (value <= arr[index])
			index = 2 * index + 1;
		else index = 2 * index + 2;
	}
	arr[index] = value;
	if (index > arrSize)
		arrSize = index;
}

void print(int arr[], int n) {
	for (int i = 0; i <= n; i++)
		cout << arr[i] << " ";
}

int main() {
	int arr[1000] = {0};
    int n, inp;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> inp;
    	insert(arr, inp);
	}
    
    print(arr, arrSize);
}
