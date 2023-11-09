//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool solve(int N, int arr[], int sum){
        if(N < 0){
            return false;
        }
        if(sum < 0){
            return false;
        }
        if(sum == 0){
            return true;
        }
        
        bool incl = solve(N-1, arr, sum - arr[N]);
        bool excl = solve(N-1, arr, sum);
        
        return incl | excl;
    }
    
    bool solveMem(int N, int arr[], int sum, vector<vector<int>> & dp){
        if(N < 0){
            return false;
        }
        if(sum < 0){
            return false;
        }
        if(sum == 0){
            return true;
        }
        if(dp[N][sum] != -1){
            return dp[N][sum];
        }
        
        bool incl = solveMem(N-1, arr, sum - arr[N], dp);
        bool excl = solveMem(N-1, arr, sum, dp);
        
        return dp[N][sum] = incl | excl;
    }
    
    bool solveTab(int N, int arr[], int sum){
        vector<vector<int>> dp(N, vector<int> (sum+1, 0));
        for(int i = 0; i < N; i++){
            dp[i][0] = true;
        }
        
        for(int i = 1; i < N; i++){
            for(int j = 1; j <= sum; j++){
                bool incl = false;
                if(j - arr[i] >= 0){
                    incl = dp[i-1][j-arr[i]];
                }
                bool excl = dp[i-1][j];
                
                dp[i][j] = incl | excl;
            }
        }
        
        return dp[N-1][sum];
    }
    
    bool spaceOpti(int N, int arr[], int sum){
        vector<int> prev (sum+1, 0);
        vector<int> next (sum+1, 0);
        
        prev[0] = 1; next[0] = 1;
        
        for(int i = 1; i < N; i++){
            for(int j = 1; j <= sum; j++){
                bool incl = false;
                if(j - arr[i] >= 0){
                    incl = prev[j-arr[i]];
                }
                bool excl = prev[j];
                
                next[j] = incl | excl;
            }
            prev = next;
        }
        
        return next[sum];
    }
    
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += arr[i];
        }
        if(sum % 2 == 1){
            return false;
        }
        
        // return solve(N-1, arr, sum/2);
        // vector<vector<int>> dp(N, vector<int> (sum/2 + 1, -1));
        // return solveMem(N-1, arr, sum/2, dp);
        // return solveTab(N, arr, sum/2);
        return spaceOpti(N, arr, sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends

//TC: O(n*sum);
//SC: O(sum);