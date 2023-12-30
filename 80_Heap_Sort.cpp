#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void putInCorrectPlace(int arr[], int n, int i){ //heapify function
    int curr = i, left = 2*i + 1, right = 2*i + 2;
    if(left < n && arr[left] > arr[curr]){
        curr = left;
    }
    if(right < n && arr[right] > arr[curr]){
        curr = right;
    }

    if(curr != i){
        swap(arr[curr], arr[i]);
        putInCorrectPlace(arr, n, curr);
    }
}

void heapSort(int arr[], int n){

    if(n == 1){
        return;
    }

    putInCorrectPlace(arr, n, 0);
    swap(arr[0], arr[n-1]);
    heapSort(arr, n-1);

}

int main(){

    int arr[] = {70, 60, 55, 45, 50};
    swap(arr[0], arr[4]);
    heapSort(arr, 4);

    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}