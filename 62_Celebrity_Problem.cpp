//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i = 0; i<n; i++){
            st.push(i);
        }
        
        int A, B;
        while(true){
            A = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            B = st.top();
            st.pop();
            
            if(M[B][A] == 0){
                st.push(B);
            }
            else if(M[A][B] == 0){
                st.push(A);
            }
        }
        
        for(int i = 0; i<n; i++){
            if(M[A][i] == 1){
                return -1;
            }
            else if(M[i][A] == 0 && i!=A){
                return -1;
            }
        }
        
        return A;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends