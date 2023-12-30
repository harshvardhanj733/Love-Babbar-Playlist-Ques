#include <bits/stdc++.h> 

void heapify(vector<int>& arr, int index){
    int smal = index;
    int left = 2*index, right = 2*index + 1;

    if(left < arr.size()+1 && arr[smal-1] > arr[left-1]){
        smal = left;
    }
    if(right < arr.size()+1 && arr[smal-1] > arr[right-1]){
        smal = right;
    }

    if(smal != index){
        swap(arr[index-1], arr[smal-1]);
        heapify(arr, smal);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    for(int i = arr.size()/2 - 1; i >= 0; i--){
        heapify(arr, i + 1);
    }

    return arr;
}


//TC: O(n logn);
//SC: O(1);