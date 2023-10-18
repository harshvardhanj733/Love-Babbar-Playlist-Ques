//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
        int solveTab(int n){
            vector<int> dp(n+1, INT_MAX);
            dp[0] = 0;
            
            for(int i = 1; i <= n; i++){
                for(int j = 1; j*j <= i; j++){
                    if(i - j*j >= 0){
                        dp[i] = min(dp[i], 1 + dp[i - j*j]);
                    }
                }
            }
            
            return dp[n];
        }
        
        int solveRec(int n){
            if(n == 0){
                return 0;
            }
            
            int ans = INT_MAX;
            for(int i = 1; i*i <= n; i++){
                if(n - i*i >= 0){
                    ans = min(ans, 1 + solveRec(n - i*i));
                }
            }
            
            return ans;
        }
        
        int solveMem(int n, vector<int>& dp){
            if(n == 0){
                return 0;
            }
            if(dp[n] != INT_MAX){
                return dp[n];
            }
            
            int ans = INT_MAX;
            for(int i = 1; i*i <= n; i++){
                if(n - i*i >= 0){
                    ans = min(ans, 1 + solveMem(n - i*i, dp));
                }
            }
            
            return dp[n] = ans;
        }
        
	public:
	int MinSquares(int n)
	{
	    // Code here
	   // return solveTab(n);
	   //return solveRec(n);
	   vector<int> dp(n+1, INT_MAX);
	   dp[0] = 0;
	   return solveMem(n, dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends