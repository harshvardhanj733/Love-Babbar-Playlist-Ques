#include <bits/stdc++.h> 
#define MOD 1000000007

int soln(int nStairs, int * dp){
    if(dp[nStairs] != -1){
        return dp[nStairs];
    }

    if(nStairs == 0){
        return 1;
    }
    if(nStairs <= 2){
        return nStairs;
    }

    dp[nStairs] = (soln(nStairs-1, dp) + soln(nStairs-2, dp))%MOD;
    return dp[nStairs];
}

int countDistinctWays(int nStairs) {
    //  Write your code here.
    
    //Base Case
    // if(nStairs == 0){
    //     return 1;
    // }
    // if(nStairs <= 2){
    //     return nStairs;
    // }

    // //Recurrence Relation
    // return countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);

    int * dp = new int[nStairs + 1];
    for(int i = 0; i<=nStairs; i++){
        dp[i] = -1;
    }
    
    return soln(nStairs, dp);
}