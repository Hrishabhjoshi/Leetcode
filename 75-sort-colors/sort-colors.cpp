class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes=0, twos= nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)zeroes++;
            else if(nums[i]==2)twos--;
        }
        int i=0;
        while(i!=nums.size() && i<zeroes)
        {
            nums[i]=0;
            i++;
        }
        while(i!=nums.size() && i<twos)
        {
            nums[i]=1;
            i++;
        }
        while(i!=nums.size())
        {
            nums[i]=2;
            i++;
        }
    }
};