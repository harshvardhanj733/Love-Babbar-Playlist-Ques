#include<limits.h>
int solve(int n, int x, int y, int z){
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return -1;
	}

	int ansX = -1, ansY = -1, ansZ = -1;

	if(solve(n-x, x, y, z) != -1)
		ansX = solve(n-x, x, y, z) + 1;
	if(solve(n-y, x, y, z) != -1)
		ansY = solve(n-y, x, y, z) + 1;
	if(solve(n-z, x, y, z) != -1)
		ansZ = solve(n-z, x, y, z) + 1;

	return max(ansX, max(ansY, ansZ));
	
}

int solveMem(int n, int x, int y, int z, vector<int>& dp){
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return -1;
	}

	if(dp[n] != -1){
		return dp[n];
	}

	int ansX = -1, ansY = -1, ansZ = -1;

	if(solveMem(n-x, x, y, z, dp) != -1)
		ansX = solveMem(n-x, x, y, z, dp) + 1;
	if(solveMem(n-y, x, y, z, dp) != -1)
		ansY = solveMem(n-y, x, y, z, dp) + 1;
	if(solveMem(n-z, x, y, z, dp) != -1)
		ansZ = solveMem(n-z, x, y, z, dp) + 1;

	return dp[n] = max(ansX, max(ansY, ansZ));
}

int solveTab(int n, int x, int y, int z){
	vector<int> dp(n+1, -1);

	dp[0] = 0;

	for(int i = 1; i<=n; i++){
		int ansX = -1, ansY = -1, ansZ = -1;
		if(i-x >= 0 && dp[i-x] != -1){
			ansX = dp[i-x] + 1;
		}
		if(i-y >= 0 && dp[i-y] != -1){
			ansY = dp[i-y] + 1;
		}
		if(i-z >= 0 && dp[i-z] != -1){
			ansZ = dp[i-z] + 1;
		}

		dp[i] = max(ansX, max(ansY, ansZ));
	}

	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// return (solve(n, x, y, z) != -1)?solve(n, x, y, z):0;
	// vector<int> dp(n+1, -1);
	// return (solveMem(n, x, y, z, dp) != -1)?solveMem(n, x, y, z, dp):0;
	return (solveTab(n, x, y, z)!=-1)?solveTab(n, x, y, z):0;
}