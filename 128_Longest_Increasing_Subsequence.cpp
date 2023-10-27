//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int solve(int a[], int n, int index, int prevElement){
        if(index == n){
            return 0;
        }
        
        int incl = 0, excl = 0;
        if(a[index] > prevElement){
            incl = 1 + solve(a, n, index+1, a[index]);
        }
        excl = solve(a, n, index+1, prevElement);
        
        return max(incl, excl);
    }
    
    int solveMem(int a[], int n, int index, int prev, vector<vector<int>>& dp){
        if(index == n){
            return 0;
        }
        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }
        
        int incl = 0, excl = 0;
        if(prev == -1 || a[index] > a[prev]){
            incl = 1 + solveMem(a, n, index+1, index, dp);
        }
        excl = solveMem(a, n, index+1, prev, dp);
        
        return dp[index][prev+1] = max(incl, excl);
    }
    
    int solveTab(int a[], int& n){
        vector<vector<int>> dp(n+1, vector<int> (n+2, 0));
        
        for(int index = n-1; index >= 0; index--){
            for(int prev = index - 1; prev >= -1; prev--){
                int incl = 0, excl = 0;
                if(prev == -1 || a[index] > a[prev]){
                    incl = 1 + dp[index+1][index+1];
                }
                excl = dp[index+1][prev+1];
                
                dp[index][prev+1] = max(incl, excl);
            }
        }
        
        return dp[0][0];
    }
    
    int binSearch(vector<int> a, int n, int el){
        int l = 0, r = n-1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(a[mid] == el){
                return mid;
            }
            else if(a[mid] < el){
                l = mid + 1;
            }
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        
        return ans;
    }
    
    int Optimal(int a[], int n){
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i = 1; i < n; i++){
            if(a[i] > ans[ans.size()-1]){
                ans.push_back(a[i]);
            }
            else{
                //apply binary search;
                int index = binSearch(ans, ans.size(), a[i]);
                ans[index] = a[i];
            }
        }
        
        return ans.size();
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   return solve(a, n, 0, INT_MIN);
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return solveMem(a, n, 0, -1, dp);
        // return solveTab(a, n);
        return Optimal(a, n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends

//TC: O(nlogn);
//SC: O(n);