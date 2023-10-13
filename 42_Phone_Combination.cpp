class Solution {
public:

    void recursiveSolution(string & digits, vector<string> & res, string temp, int index, string arr[]){
        if(index >= digits.size()){
            if(temp.size() > 0)
                res.push_back(temp);

            return;
        }

        int digit = (int)(digits[index] - '0');
        for(int j = 0; j<arr[digit].size(); j++){
            temp.push_back(arr[digit][j]);
            recursiveSolution(digits, res, temp, index+1, arr);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        string temp = "";

        recursiveSolution(digits, res, temp, 0, arr);

        return res;
    }
};