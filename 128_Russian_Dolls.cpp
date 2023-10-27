class Solution {
public:

    static bool cmp(vector<int> env1, vector<int> env2){
        if(env1[0] != env2[0]){
            return env1[0] < env2[0];
        }
        return env1[1] > env2[1];
    }

    int binSearch(vector<int>& ans, int& x){
        int l = 0, r = ans.size()-1;
        int res = -1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(ans[mid] == x){
                return mid;
            }
            else if(ans[mid] < x){
                l = mid + 1;
            }
            else{
                res = mid;
                r = mid - 1;
            }
        }

        return res;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i = 1; i < envelopes.size(); i++){
            if(envelopes[i][1] > ans[ans.size() - 1]){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int index = binSearch(ans, envelopes[i][1]);
                ans[index] = envelopes[i][1];
            }
        }

        return ans.size();
    }
};

//TC: O(nlogn);
//SC: O(n);