#include <stack>
#include <algorithm>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> check;
    check.push(-1);

    vector<int> res;

    for(int i = n-1; i>=0; i--){
        if(arr[i] > check.top()){
            res.push_back(check.top());
            check.push(arr[i]);
        }
        else{
            while(arr[i] <= check.top()){
                check.pop();
            }
            res.push_back(check.top());
            check.push(arr[i]);
        }
    }

    for(int i = 0; i<res.size()/2; i++){
        swap(res[i], res[n-i-1]);
    }

    return res;
}