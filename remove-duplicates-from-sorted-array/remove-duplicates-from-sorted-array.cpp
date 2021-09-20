class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int i=0;
        int j=1;
        while(j<=nums.size()-1)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j]; 
            }
            j++;
        }
        return i+1;
        
    }
};