//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(vector<vector<int>> mat, int row, int col, int& maxi){
        if(row >= mat.size() || col >= mat[0].size()){
            return 0;
        }
        
        int right = solve(mat, row, col+1, maxi);
        int down = solve(mat, row+1, col, maxi);
        int diag = solve(mat, row+1, col+1, maxi);
        
        if(mat[row][col] == 0){
            return 0;
        }
        
        int ans = min(right, min(down, diag)) + 1;
        maxi = max(ans, maxi);
        return ans;
    }
    
    int solveMem(vector<vector<int>>& mat, vector<vector<int>>& dp, int row, int col, int& maxi){
        if(row >= mat.size() || col >= mat[0].size()){
            return 0;
        }
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        int right = solveMem(mat, dp, row, col+1, maxi);
        int down = solveMem(mat, dp, row+1, col, maxi);
        int diag = solveMem(mat, dp, row+1, col+1, maxi);
        
        if(mat[row][col] == 0){
            return dp[row][col] = 0;
        }
        
        int ans = min(right, min(down, diag)) + 1;
        maxi = max(ans, maxi);
        return dp[row][col] = ans;
    }
    
    int solveTab(vector<vector<int>> mat){
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        int maxi = 0, row = n-1, col = m-1;
        
        dp[row][col] = mat[row][col];
        for(int row = n-1; row >= 0; row--){
            for(int col = m-1; col >= 0; col--){
                int down = dp[row+1][col];
                int right = dp[row][col+1];
                int diag = dp[row+1][col+1];
                
                if(mat[row][col] == 0){
                    dp[row][col] = 0;
                }
                else{
                    dp[row][col] = min(down, min(right, diag)) + 1;
                    maxi = max(dp[row][col], maxi);
                }
            }
        }
        
        return maxi;
    }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi = 0, ans = 0;
        // ans = solve(mat, 0, 0, maxi);
        // vector<vector<int>> dp(mat.size(), vector<int> (mat[0].size(), -1));
        // ans = solveMem(mat, dp, 0, 0, maxi);
        // return maxi;
        return solveTab(mat);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends