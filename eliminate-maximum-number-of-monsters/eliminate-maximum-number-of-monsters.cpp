class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        for(int i=0;i<dist.size();i++)
        {
            time.push_back((double)dist[i]/(double)speed[i]);
        }
        
        sort(time.begin(),time.end());
        int ans=0;
        int clck=0;
        for(auto elem:time)
        {
            if(elem<=clck)
            {
                break;
            }
            else
            {
                ans++;
                clck++;
            }
        }
       return ans; 
    }
};