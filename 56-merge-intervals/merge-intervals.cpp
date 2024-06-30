class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        if(n==1)return intervals;
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++)
        {
            vector<int>temp= intervals[i];
            if(ans.back()[1]>=temp[0])
            {
                ans.back()[1]=max(ans.back()[1], temp[1]);
            }
            else{
                ans.push_back(temp);
            }
        }
        return ans;
    }
};