class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minm=INT_MAX;
        int maxDiff=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            minm=min(minm,nums[i]);
            maxDiff=max(maxDiff,nums[i]-minm);
            
        }
        if(maxDiff==0)
            return -1;
        return maxDiff;
        
    }
};