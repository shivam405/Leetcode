class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int nums1=-1,nums2=-1,count1=0,count2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums1==nums[i])
                count1++;
            else if(nums2==nums[i])
            count2++;
            else if(count1==0)
            {
                nums1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                nums2=nums[i];
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }
                
        }
        count1=0,count2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums1)
                count1++;
            else if(nums[i]==nums2)
                count2++;
        }
        if(count1>nums.size()/3)
        {
            ans.push_back(nums1);
        }    
        if(count2>nums.size()/3)
        {
            ans.push_back(nums2);
        }    
        
        return ans;
    }
};