class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N=1e5+10;
        vector<int> global(N,0);
        for(int i=0;i<nums.size();i++)
        {
            global[nums[i]]++;
        }
        for(int i=1;i<nums.size()+1;i++)
        {
            if(global[i]>1)
            {
                return i;
            }
        }
        return -1;
    }
};