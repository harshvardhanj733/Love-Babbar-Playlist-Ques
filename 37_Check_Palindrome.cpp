#include <bits/stdc++.h> 

long long check(long long N, long long copy, long long ans){
	if(copy <= 0){
		return ans;
	}
	ans = ans*2 + (copy&1);
	copy >>= 1;
	return check(N, copy, ans);
}

bool checkPalindrome(long long N)
{
	// Write your code here.
	long long copy = N;
	long long ans = 0;

	// while(copy > 0){
	// 	ans = ans*2 + (copy&1);
	// 	copy >>= 1;
	// }

	ans = check(N, copy, ans);

	return ans==N;
}