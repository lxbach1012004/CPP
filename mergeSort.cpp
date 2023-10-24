#include<bits/stdc++.h>
using namespace std;

void merge(int left[], int right[], int big[], int nL, int nR){
    int i = 0, j = 0, k = 0;
    while(i < nL && j < nR){
        if(left[i] <= right[j]){
            big[k] = left[i];
            i++;
            k++;
        }
        else{
            big[k] = right[j];
            j++;
            k++;
        }
    }
    while(i < nL){
        big[k] = left[i];
        i++;
        k++;
    }
    while(j < nR){
        big[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n){
    if(n < 2) return;
    int mid = n / 2;
    int left[100005], right[100005];
    for(int i = 0; i < mid; i++){
        left[i] = arr[i];
    }
    for(int i = mid; i < n; i++){
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, right, arr, mid, n - mid);
}

int main(){
    int n, arr[100005];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
