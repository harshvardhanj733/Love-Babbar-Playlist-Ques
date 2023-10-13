//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    map<char, int> m;
		    string res;
		    for(int i = 0; i<A.size(); i++){
		        if(!m[A[i]]){
		            m[A[i]]++;
		            q.push(A[i]);
		        }
		        else{
		            m[A[i]]++;
		        }
		        while(!q.empty() && m[q.front()] != 1){
		            q.pop();
		        }
		        if(q.empty()){
		            res += '#';
		        }
		        else{
		            res += q.front();
		        }
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends