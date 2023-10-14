#include <bits/stdc++.h> 
#define M 1000000007

// void solve(int n, int k, int index, int& count, int check, vector<int>& color){
//     if(index == n){
//         count = (count+1)%M;
//         return;
//     }
    
//     for(int i = 0; i < k; i++){
//         if(index == 0){
//             color.push_back(i);
//             solve(n, k, index+1, count, check, color);
//             color.pop_back();
//         }
//         if(index > 0 && color[index - 1] == i && check == 0){
//             check = 1;
//             color.push_back(i);
//             solve(n, k, index+1, count, check, color);
//             color.pop_back();
//         }
//         if(index > 0 && color[index - 1] != i){
//             check = 0;
//             color.push_back(i);
//             solve(n, k, index+1, count, check, color);
//             color.pop_back();
//         }
//     }
// }

int solveTab(int n, int k){
    pair<int, int> fir;
    fir.first = 0;
    fir.second = k%M;
    
    for(int i = 2; i <= n; i++){
        pair<int, int> temp;
        temp.first = fir.first%M;
        temp.second = fir.second%M;

        fir.first = (temp.second)%M;
        fir.second = (1LL*(temp.first%M + temp.second%M)*(k-1)%M)%M;
    }

    return (fir.first%M + fir.second%M)%M;
}

int solveTab2(int n, int k){
    pair<int, int> fir;
    fir.first = 0;
    fir.second = k;
    
    for(int i = 2; i <= n; i++){
        pair<int, int> temp;
        temp.first = fir.first;
        temp.second = fir.second;

        fir.first = temp.second;
        fir.second = (temp.first + temp.second)*(k-1);
    }

    return 1LL*(fir.first + fir.second);
}

int numberOfWays(int n, int k) {
    // Write your code here.
    // vector<int> color(n);
    // int count = 0, check = 0, index = 0;
    // solve(n, k, index, count, check, color);

    // return count;

    return 1LL*solveTab(n, k);
}
