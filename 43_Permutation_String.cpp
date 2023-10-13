#include<algorithm>

void solve(string str, vector<string> & res, int index){
    if(index >= str.size()-1){
        res.push_back(str);
        return;
    }
    for(int i = index; i<str.size(); i++){
        string temp = str;
        swap(temp[index], temp[i]);
        solve(temp, res, index+1);
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string> res;
    // string temp = str;

    solve(str, res, 0);
    sort(res.begin(), res.end());

    return res;
}