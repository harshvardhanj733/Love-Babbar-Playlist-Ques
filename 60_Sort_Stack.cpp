#include <bits/stdc++.h> 

void sort(stack<int> &stack, int top){
	if(stack.empty() || stack.top() < top){
		stack.push(top);
		return;
	}
	int element = stack.top();
	stack.pop();
	sort(stack, top);
	stack.push(element);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}

	int top = stack.top();
	stack.pop();
	sortStack(stack);
	sort(stack, top);
}