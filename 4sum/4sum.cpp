class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;
     int n= nums.size();
        
     sort(nums.begin(),nums.end());
    
        
     for(int i=0;i<n-3;i++)
     {
         for(int j=i+1;j<n-2;j++)
         {
             int newSum=target-nums[i]-nums[j];
             int left=j+1;
             int right=n-1;
             while(left<right)
             {
                 int currentSum=nums[left]+nums[right];
                 if(currentSum<newSum)
                     left++;
                 else if(currentSum>newSum)
                     right--;
                 else if(currentSum==newSum)
                 {
                     vector<int> quad={nums[i],nums[j],nums[left],nums[right]};
                     result.push_back(quad);
                     while(left<right and quad[3]==nums[right-1])--right;
                     while(left<right and quad[2]==nums[left+1])++left;
                     right--;
                     left++;
                 }
                 
             }
             while(j+1<n-2 && nums[j+1]==nums[j]) j++;
         }
         while(i+1<n-3 && nums[i+1]== nums[i]) i++;
     }
        return result;
        
    }
};