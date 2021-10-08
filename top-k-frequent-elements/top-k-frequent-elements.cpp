class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto &pr:mp)
        {
            minh.push({pr.second,pr.first});
            if(minh.size()>k)
            {
                minh.pop();
            }  
        }
        while(minh.size()!=0)
        {
            res.push_back(minh.top().second);
            minh.pop();
        }
        return res;  
    }
};