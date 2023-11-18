class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        int i = 0, j = 1;
        int freq = 1, maxFreq = 1;

        while(j < n){
            if(sum + 1LL*(j-i)*(nums[j] - nums[j-1]) <= k){
                sum += (j-i)*(nums[j] - nums[j-1]);
                freq++;
                maxFreq = max(maxFreq, freq);
                j++;
            }
            else{
                if(i == j-1){
                    i++;
                    j++;
                    freq = 1;
                    sum = 0;
                }
                else{
                    sum -= nums[j-1] - nums[i];
                    freq--;
                    i++;
                }
            }
        }

        return maxFreq;
    }
};

//TC: O(nlogn);
//SC: O(1);