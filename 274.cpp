class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        // for(int i = 0; i < n; i++){
        //     if(citations[i] >= n - i){
        //         return n - i;
        //     }
        // }
        int l = 0, r = n-1, ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(citations[mid] >= n - mid){
                ans = n - mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

//TC: O(nlogn);
//SC: O(1);