#include<bits/stdc++.h>
using namespace std;

int fib(int n, int * arr){
        if(arr[n] != -1){
                return arr[n];
        }

        if(n == 1 || n == 0){
                arr[n] = n;
                return n;
        }

        arr[n] = fib(n-1, arr) + fib(n-2, arr);
        return arr[n];
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        // int * arr = new int[n+1];
        // for(int i = 0; i<n+1; i++){
        //         arr[i] = -1;
        // }
        // arr[0] = 0;
        // arr[1] = 1;
        int first = 0;
        int second = 1;

        for(int i = 2; i<=n; i++){
                int temp = second;
                second = second + first;
                first = temp;
        }

        // int ans = fib(n, arr);
        // int ans = arr[n];

        cout<<second;
        return 0;
}