class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
    priority_queue<int,vector<int>,greater<int>> minh;
    
    for(int j=0;j<n;j++)
    {
        minh.push(nums[j]);
    }
    while(minh.size()!=0)
    {
        res.push_back(minh.top());
        minh.pop();
    }
        return res;
    }
};