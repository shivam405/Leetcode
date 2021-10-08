class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n=arr.size();
        priority_queue<pair<int,int>> maxh;
        for(int i=0;i<n;i++)
        {
            maxh.push({abs(arr[i]-x),arr[i]});
            if(maxh.size()>k)
            maxh.pop();

        }
        while(maxh.size()!=0)
        {
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};