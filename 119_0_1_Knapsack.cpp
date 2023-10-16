#include <bits/stdc++.h> 

int solveRec(vector<int> weight, vector<int> value, int n, int maxWeight){
	if(n < 0){
		return 0;
	}

	int exclude = solveRec(weight, value, n-1, maxWeight);
	int include = 0;
	if(weight[n] <= maxWeight){
		include = value[n] + solveRec(weight, value, n-1, maxWeight-weight[n]);
	}

	return max(include, exclude);
}

int solveMem(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>>& dp){
	if(n < 0){
		return 0;
	}
	if(dp[n][maxWeight] != -1){
		return dp[n][maxWeight];
	}

	int exclude = solveMem(weight, value, n-1, maxWeight, dp);
	int include = 0;
	if(weight[n] <= maxWeight){
		include = value[n] + solveMem(weight, value, n-1, maxWeight - weight[n], dp);
	}
	
	return dp[n][maxWeight] = max(include, exclude);
}

int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight){
	// vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

	// for(int w = 0; w <= maxWeight; w++){
	// 	if(weight[0] <= w){
	// 		dp[0][w] = value[0];
	// 	}
	// 	else{
	// 		dp[0][w] = 0;
	// 	}
	// }

	// for(int i = 1; i < n; i++){
	// 	for(int w = 0; w <= maxWeight; w++){
	// 		int include = 0;
	// 		if(weight[i] <= w){
	// 			include = value[i] + dp[i-1][w-weight[i]];
	// 		}
	// 		int exclude = dp[i-1][w];

	// 		dp[i][w] = max(include, exclude);
	// 	}
	// }

	// return dp[n-1][maxWeight];

	vector<int> fir(maxWeight+1, 0);
	// vector<int> sec(maxWeight+1, 0);

	for(int i = 0; i <= maxWeight; i++){
		if(i >= weight[0]){
			fir[i] = value[0];
		}
		else{
			fir[i] = 0;
		}
	}

	for(int i = 1; i < n; i++){
		for(int j = maxWeight; j >= 0; j--){
			int exclude = fir[j];
			int include = 0;
			if(weight[i] <= j){
				include = value[i] + fir[j-weight[i]];
			}

			fir[j] = max(include, exclude);
		}

		// fir = sec;
	}

	return fir[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// return solveRec(weight, value, n-1, maxWeight);
	// vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	// return solveMem(weight, value, n-1, maxWeight, dp);
	return solveTab(weight, value, n, maxWeight);
}