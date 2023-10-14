#include<vector>
#define M 1000000007
long long int countDerangementsMem(int n, vector<int> dp){
    if(n == 2){
        return 1;
    }
    if(n < 2){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = ((n-1)*(countDerangementsMem(n-1, dp) + countDerangementsMem(n-2, dp)))%M;
}

long long int countDerangementsTab(int n){
    long long int fir = 0;
    long long int sec = 1;

    for(int i = 3; i <= n; i++){
        long long int temp = sec;
        sec = ((i-1)*(sec%M + fir%M)%M)%M;
        fir = temp;
    }

    return sec;
}

long long int countDerangements(int n) {
    // Write your code here.
    // if(n == 2){
    //     return 1;
    // }
    // if(n < 2){
    //     return 0;
    // }

    // return (n-1)*(countDerangements(n-1) + countDerangements(n-2));

    // vector<int> dp(n+1, -1);
    // return countDerangementsMem(n, dp);
    return countDerangementsTab(n);
}