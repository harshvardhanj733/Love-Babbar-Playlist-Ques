#include<queue>

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            if(q.size() < k){
                q.push(sum);
            }
            else if(q.top() < sum){
                q.pop();
                q.push(sum);
            }
        }
    }

    return q.top();
}

//TC: O(n^2);
//SC: O(K);