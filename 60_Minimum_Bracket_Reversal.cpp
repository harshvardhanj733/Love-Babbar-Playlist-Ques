#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here
  int reversals = 0;
  int lCount = 0, rCount = 0;
  stack<char> st;
  for(int i = 0; i<str.size(); i++){
      if(str[i] == '{'){
        st.push('{');
        lCount++;
      } 
      else if (str[i] == '}'){
          if(!st.empty() && st.top()=='{'){
            st.pop();
            lCount--;
          } else {
            st.push('}');
            rCount++;
          }
      }
  }

  if(abs(lCount-rCount)%2 & 1){
    return -1;
  }

  int check = 0;
  while(!st.empty()){
      if(st.top() == '{'){
        if(check == 0){
          reversals++;
          check = 1;
        }
        else{
          check = 0;
        }
        st.pop();
      }
      else{
        if(check == 1){
          reversals++;
          check = 0;
        }
        else{
          check = 1;
        }
        st.pop();
      }
  }
  
  return reversals;

}