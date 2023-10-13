//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> m, int n, int row, int col, vector<vector<int>>& visited){
        if(row >=n || col >= n || row < 0 || col < 0){
            return false;
        }
        else if(visited[row][col] == 1){
            return false;
        }
        else if(m[row][col] == 0){
            return false;
        }
        return true;
    }
    
    void Soln(vector<vector<int>> m, int n, vector<string>& res, string temp, int row, int col, vector<vector<int>>& visited){
        if(row == n-1 && col == n-1){
            res.push_back(temp);
            return;
        }
        
        visited[row][col] = 1;
        
        if(isSafe(m, n, row+1, col, visited)){
            temp.push_back('D');
            Soln(m, n, res, temp, row+1, col, visited);
            temp.pop_back();
        }
        
        if(isSafe(m, n, row, col+1, visited)){
            temp.push_back('R');
            Soln(m, n, res, temp, row, col+1, visited);
            temp.pop_back();
        }
        
        if(isSafe(m, n, row-1, col, visited)){
            temp.push_back('U');
            Soln(m, n, res, temp, row-1, col, visited);
            temp.pop_back();
        }
        
        if(isSafe(m, n, row, col-1, visited)){
            temp.push_back('L');
            Soln(m, n, res, temp, row, col-1, visited);
            temp.pop_back();
        }
        
        visited[row][col] = 0;
    }
        
        
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return res;
        }
        string temp = "";
        
        vector<vector<int>> visited = m;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        Soln(m, n, res, temp, 0, 0, visited);
        
        sort(res.begin(), res.end());
        
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends