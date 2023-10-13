void merge(vector<int> &arr, int l, int mid, int r){
    int i = l, j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=r){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int k = 0; k < temp.size(); k++){
        arr[l+k] = temp[k];
    }
}

void divide(vector<int> &arr, int l, int r){
    int mid = l + (r-l)/2;
    if(l<r){
        divide(arr, l, mid);
        divide(arr, mid+1, r);
    }
    merge(arr, l, mid, r);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    divide(arr, 0, n-1);
}