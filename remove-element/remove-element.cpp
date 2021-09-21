class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int i=0;
        int j=nums.size()-1;
        while(j>=i)
        {
           if(nums[i]==val)
           {
             count++;
             swap(nums[i],nums[j]);
             j--;
           }
           if(nums[i]!=val)
           {
               i++;
           }
        }
        if(count==nums.size())
        {
            return 0;
        }
        
        return i;
    }
};