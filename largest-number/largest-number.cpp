class Solution {
    static bool cmp(string A,string B)
    {
        return A+B>B+A;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> mynum;
        for(int i:nums)
        {
            mynum.push_back(to_string(i));
        }
        
        sort(mynum.begin(),mynum.end(),cmp);
        
        string ans="";
        for(auto str:mynum)
        {
            ans+=str;
        }
        
        while(ans[0]=='0' && ans.size()>1)
            ans.erase(0,1);
        return ans;
        
    }
};