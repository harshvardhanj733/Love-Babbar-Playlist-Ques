//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    int* nextMin(int arr[], int n){
        stack<pair<int, int>> st;
        pair<int, int> temp;
        temp.first = -1;
        temp.second = n;
        st.push(temp);
        
        int* next = new int[n];
        
        for(int i = n-1; i>=0; i--){
            while(arr[i] <= st.top().first){
                st.pop();
            }
            next[i] = st.top().second;
            temp.first = arr[i];
            temp.second = i;
            st.push(temp);
        }
        
        return next;
    }
    
    int* prevMin(int arr[], int n){
        stack<pair<int, int>> st;
        pair<int, int> temp;
        temp.first = -1;
        temp.second = -1;
        st.push(temp);
        
        int* prev = new int[n];
        
        for(int i = 0; i<n; i++){
            while(arr[i] <= st.top().first){
                st.pop();
            }
            prev[i] = st.top().second;
            temp.first = arr[i];
            temp.second = i;
            st.push(temp);
        }
        
        return prev;
    }
  
    int getAreaOfHistogram(int arr[], int n){
        int* next = nextMin(arr, n);
        int* prev = prevMin(arr, n);
        
        int maxArea = 0;
        
        for(int i = 0; i<n; i++){
            int area = arr[i]*(next[i]-prev[i]-1);
            maxArea = max(area, maxArea);
        }
        
        delete next;
        delete prev;
        
        return maxArea;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int * arr = new int[m];
        int maxArea = 0;
        for(int i = 0; i<m; i++){
            arr[i] = M[0][i];
        }
        maxArea = max(maxArea, getAreaOfHistogram(arr, m));
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(M[i][j] == 0){
                    arr[j] = 0;
                }
                else{
                    arr[j] += M[i][j];
                }
            }
            maxArea = max(maxArea, getAreaOfHistogram(arr, m));
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends