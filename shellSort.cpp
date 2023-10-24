#include<bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int n){
    int k = n / 2;
    int temp;
    while(k > 0){
        for(int i = 0; i < n - k; i++){
            if(arr[i] > arr[i + k]){
                swap(arr[i], arr[i + k]);
                temp = i;
                while(temp >= k && arr[temp] < arr[temp - k]){
                    swap(arr[temp], arr[temp - k]);
                    temp -= k;
                }
            }
        }
        k /= 2;
    }
}

int main(){
    int n, arr[100001];
    cin >> n;
    for(int i = 0; i < n; i++)
    	cin >> arr[i];
    shellSort(arr, n);
    for(int i = 0; i < n; i++)
    	cout << arr[i] << " ";
}
