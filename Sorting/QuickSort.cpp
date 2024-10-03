#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start , int end){
    int pivot = arr[start];
    int i = start+1;
    int j = end;
    while(i<=j){
        while(i<=end && arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[start],arr[j]);
    return j;
}

void quickSort(int arr[] , int start , int end){
    if(start < end){
        int pi = partition(arr,start,end);
        quickSort(arr,start,pi-1);
        quickSort(arr,pi+1,end);
    }
}

int main(){
    int arr[] = {27,23,1,54,23,43,21,45,63};
    int n = 9;

    quickSort(arr,0,n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}