class Solution {
    bool subsetSum(vector<int> arr,int sum,int n)
    {
    	bool t[n+1][sum+1];
    
        	for (int i = 0; i<n+1; i++)
        	{
        		for(int j=0;j<sum+1;j++)
        		{
        			//initialisation
        			if(i==0)
        			{
        				t[i][j]=false;
        			}
        			if(j==0)
        			{
        				t[i][j]=true;
        			}
        		}
        	    
        	}
        	//replace wt[]=arr and W=sum
           for(int i=1;i<n+1;i++)
           {
               for(int j=1;j<sum+1;j++)
               {
                    if(j>=arr[i-1])
        			{
        				t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
        			}
        			else
        			{
        				t[i][j]=t[i-1][j];
        			}
               }
           }
        	return t[n][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int N=nums.size();
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
         sum=sum/2;
        return subsetSum(nums,sum,N);
    }
};