class Solution {
public:
    int coinChange(vector<int>& coins, int V) {
        int M=coins.size();
        int t[M+1][V+1];


	//initialisation
	for(int i=0;i<M+1;i++)
	{
		for(int j=0;j<V+1;j++)
		{
			if(j==0)
			{
				t[i][j]=0; 
			}
			if(i==0)
			{
				t[i][j]=INT_MAX-1; 
			}
			if(i==1&&j>0 && j<V+1)
			{
				if(j%coins[0]==0)
				{
					t[i][j]=j/coins[0];
				}
				else
					t[i][j]=INT_MAX-1;
			}

		}
	}

	//code variation
	for(int i=2;i<M+1;i++)
	{
		for(int j=1;j<V+1;j++)
		{
			if(coins[i-1]<=j)
			{
				t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]); 
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return (t[M][V]==INT_MAX-1)?-1:t[M][V];

    }
};