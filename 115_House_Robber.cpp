#include <bits/stdc++.h> 

// long long int solveRec(vector<int> valueInHouse, int n, int index, int check){
//     if(index > check){
//         return 0;
//     }

//     if(index == 0){
//         return max(solveRec(valueInHouse, n, index+1, n-1), solveRec(valueInHouse, n, index+2, n-2) + valueInHouse[index]);
//     }

//     return max(solveRec(valueInHouse, n, index+1, check), solveRec(valueInHouse, n, index+2, check)+valueInHouse[index]);
// }

// long long int solveMem(vector<int> valueInHouse, vector<int>& dp, int n, int index, int& check){
//     if(index > check){
//         return 0;
//     }
//     if(index == 0){
//         check = n-1;
//         long long int val1 = solveMem(valueInHouse, dp, n, index+1, check);
//         for(int i = 0; i<n; i++){
//             dp[i] = -1;
//         }
//         check = n-2;
//         long long int val2 = solveMem(valueInHouse, dp, n, index+2, check);

//         dp[index] = max(val1, val2 + valueInHouse[index]);
//         return dp[index];
//     }
//     if(dp[index] != -1){
//         return dp[index];
//     }

//     return dp[index] = max(solveMem(valueInHouse, dp, n, index+1, check), solveMem(valueInHouse, dp, n, index+2, check) + valueInHouse[index]);
// }

long long int solveTab(vector<int> valueInHouse, int n){
    long long int fir = 0, sec = valueInHouse[0];
    for(int i = 1; i<n-1; i++){
        long long int temp = sec;
        sec = max(sec, fir + valueInHouse[i]);
        fir = temp;
    }
    long long int ans1 = sec;

    fir = 0, sec = valueInHouse[1];
    for(int i = 2; i<n; i++){
        long long int temp = sec;
        sec = max(sec, fir + valueInHouse[i]);
        fir = temp;
    }
    long long int ans2 = sec;

    return max(ans1, ans2);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    // vector<int> dp(n, -1);
    // return solveRec(valueInHouse, n, 0, n-1);
    // int check = n-1;
    // return solveMem(valueInHouse, dp, n, 0, check);

    return solveTab(valueInHouse, n);
}