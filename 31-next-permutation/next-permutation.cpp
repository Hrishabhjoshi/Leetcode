class Solution {
public:
    void nextPermutation(vector<int>& nums) {
  //finding breaking point
        int n= nums.size();
        int index=-1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        //if(there is no breaking point that is (nums is already sorted) )
        if(index==-1){
            reverse(nums.begin(), nums.end());
        }else{
        //find the smallest num from breaking point to end
        for(int i=n-1; i>index; i--)
        {
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        }
    }
};