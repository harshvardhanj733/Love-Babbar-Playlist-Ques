class Solution {
public:

    int solve(vector<int> cost, vector<int>& price, int n){
        if(price[n] != -1){
            return price[n];
        }
        if(n <= 1){
            return price[n] = cost[n];
        }

        return price[n] = min(solve(cost, price, n-1), solve(cost, price, n-2)) + cost[n];
    }

    int solveTabulation(vector<int> cost, int n){
        cost.push_back(0);
        // vector<int> dp(n+1);
        int fir = cost[0];
        int sec = cost[1];

        for(int i = 2; i<=n; i++){
            int temp = sec;
            sec = min(sec, fir) + cost[i];
            fir = temp;
        }

        return sec;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> price(n, -1);
        // return min(solve(cost, price, n-1), solve(cost, price, n-2));
        return solveTabulation(cost, n);
    }
};