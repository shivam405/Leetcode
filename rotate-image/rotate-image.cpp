class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=i;j<mat[0].size();j++)
                swap(mat[i][j],mat[j][i]);
        }
        for(int i=0;i<mat.size();i++)
        {
            int j=0;
            int ri=mat[0].size()-1;
            while(j<ri)
            {
                swap(mat[i][j],mat[i][ri]);
                j++;
                ri--;
            }
            
        }
        
        
    }
};