//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    long long solve(int M, int N, int X){
        if(N == 0 && X == 0){
            return 1;
        }
        if(N <= 0 || X <= 0){
            return 0;
        }
        
        long long ans = 0;
        for(int i = 1; i <= M; i++){
            ans += solve(M, N-1, X-i);
        }
        
        return ans;
        
        
    }
    
    long long solveMem(int M, int N, int X, vector<vector<long long>>& dp){
        if(N == 0 && X == 0){
            return 1;
        }
        if(N == 0 || X <= 0){
            return 0;
        }
        if(dp[N][X] != -1){
            return dp[N][X];
        }
        
        long long ans = 0;
        for(int i = 1; i <= M; i++){
            ans += solveMem(M, N-1, X-i, dp);
        }
        
        return dp[N][X] = ans;
    }
    
    long long solveTab(int M, int N, int X){
        vector<vector<long long>> dp(N+1, vector<long long>(X+1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= X; j++){
                long long ans = 0;
                for(int k = 1; k <= M && k <= j; k++){
                    // if(j-k >= 0){
                    //     ans += dp[i-1][j-k];
                    // }
                    ans += dp[i-1][j-k];
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[N][X];
    }
    
  public:
    long long noOfWays(int M , int N , int X) {
        // code here
        // return solve(M, N, X);
        // vector<vector<long long>> dp(N+1, vector<long long> (X+1, -1));
        // return solveMem(M, N, X, dp);
        return solveTab(M, N, X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends

//TC: O(m*n*x);
//SC: O(n*x) => can be further optimised to O(x);