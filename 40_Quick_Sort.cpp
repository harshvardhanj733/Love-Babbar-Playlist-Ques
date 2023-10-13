#include <bits/stdc++.h> 

int partition(vector<int> & arr, int l, int r){
    int pivot = arr[l], start = l+1, end = r;
    while(start <= end){
        while(arr[start] <= pivot && start<=end){
            start++;
        }
        while(arr[end] > pivot && start<=end){
            end--;
        }
        if(start<=end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[l], arr[end]);
    return end;
}

void quicksort(vector<int> & arr, int l, int r){
    if(l<r){
        int index = partition(arr, l, r);
        quicksort(arr, l, index-1);
        quicksort(arr, index+1, r);
    }
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    quicksort(arr, 0, arr.size()-1);
    return arr;
}
