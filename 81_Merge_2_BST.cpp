//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    void heapify(vector<int>& v, int i){
        int n = v.size();
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && v[left] > v[largest]){
            largest = left;
        }
        if(right < n && v[right] > v[largest]){
            largest = right;
        }
        
        if(largest != i){
            swap(v[largest], v[i]);
            heapify(v, largest);
        }
    }
    void makeHeap(vector<int>& v){
        int n = v.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(v, i);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> comb;
        for(auto i: a){
            comb.push_back(i);
        }
        for(auto i: b){
            comb.push_back(i);
        }
        
        makeHeap(comb);
        return comb;
    }
};

//TC: O(n+m*log(n+m))
//SC: O(n+m);

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends