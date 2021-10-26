class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]>=nums[i])
                continue;
            else
            {
                idx=i-1;
                break;
            }
        }
        if(idx==-1)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int idx2=idx+1;
        for(int j=idx+1;j<n;j++)
        {
            if(nums[j]>nums[idx] && nums[idx2]>nums[j])
            {
                idx2=j;
            }
        }
        swap(nums[idx],nums[idx2]);
        sort(nums.begin()+idx+1,nums.end());
        
    }
};