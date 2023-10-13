#include <bits/stdc++.h> 

void findSubsequences(string& str, vector<string>& res, string temp, int index){
	if(index >= str.size() && temp!=""){
		res.push_back(temp);
		return;
	}
	else if(index >= str.size()){
		return;
	}
	
	//Excluding index element
	findSubsequences(str, res, temp, index+1);

	//Including index element
	temp += str[index];
	findSubsequences(str, res, temp, index+1);
}

vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> res;
	string temp = "";

	findSubsequences(str, res, temp, 0);

	return res;
	
}
