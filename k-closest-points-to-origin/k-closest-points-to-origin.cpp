typedef pair<int,pair<int,int>> ppi;
typedef vector<vector<int>>     vvi; 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vvi res;
        priority_queue<ppi> maxh;
        int n=points.size();

        for(int i=0;i<n;i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            maxh.push({(x*x+y*y),{x,y}});
            if(maxh.size()>k)
            maxh.pop();
        }
        while(maxh.size()!=0)
        {
            vector<int> temp;
            temp.push_back(maxh.top().second.first);
            temp.push_back(maxh.top().second.second);

            res.push_back(temp);
            maxh.pop();
        }
        return res; 
    }
};