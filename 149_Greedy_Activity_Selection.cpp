//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int, int> fir, pair<int, int> sec){
        if(fir.first == sec.first){
            return fir.second < sec.second;
        }
        
        return fir.first < sec.first;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> schedule;
        for(int i = 0; i < n; i++){
            pair<int, int> meeting;
            meeting.first = end[i];
            meeting.second = start[i];
            schedule.push_back(meeting);
        }
        
        sort(schedule.begin(), schedule.end(), cmp);
        
        int count = 1;
        int endTime = schedule[0].first;
        for(int i = 1; i < schedule.size(); i++){
            if(schedule[i].second > endTime){
                count++;
                endTime = schedule[i].first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends