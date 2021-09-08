class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> ourmap;
        
        for(int i=0;i<nums.size();i++)
        {
            pair<int,int> p(nums[i],i);
            int x=target-nums[i];
            if(ourmap.count(x)>0)
            {
                result.push_back(ourmap[x]);
                result.push_back(i);
                return result;
            }
            ourmap.insert(p);
        }
        
        return {};
    }
};