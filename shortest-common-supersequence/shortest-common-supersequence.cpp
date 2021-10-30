class Solution {
    string printscs(string s1,string s2,int m,int n)
{
	int t[m+1][n+1];
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0)
			{
				t[i][j]=0;
			}
			if(j==0)
				t[i][j]=0;
		}
	}


	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]); 
		}
	}

	string ans="";

	int i=m,j=n; 

	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i-1][j]>t[i][j-1])
			{
                ans.push_back(s1[i-1]);
				i--;
			}
			else
            {
                ans.push_back(s2[j-1]);
                j--;
              
            }
				
		}
	}
    
    while(i>0)
    {
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0)
    {
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        return printscs(str1,str2,m,n);
    }
};