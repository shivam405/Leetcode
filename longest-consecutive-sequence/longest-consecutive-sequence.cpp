class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> s;
        for(auto element:nums)
        {
            s.insert(element);
        }
        for(auto element:s)
        {
            int parent=element-1;
            if(s.find(parent)==s.end())
            {
                int next_no=element+1;
                int count=1;
                while(s.find(next_no)!=s.end())
                {
                    count++;
                    next_no++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};