class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int>mp;
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n; i++)
        {
            mp[nums[i]]++;
        }
        int toch= n/3;
        for(auto it: mp)
        {
            if(it.second>toch)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};