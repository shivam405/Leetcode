class Solution {
public:
    int countSubsets(vector<int> arr,int sum,int n)
    {
        int dp[n+1][sum+1];

        //initialisation
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {

                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1; 
                }
            }
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
         int n = nums.size();
         int sum = 0;
         for(int i = 0; i < n; i++)
             sum += nums[i];
         
        int M = (sum + target)/2;
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
         return countSubsets(nums,M,n);
    }
};