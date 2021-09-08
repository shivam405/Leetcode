class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        unordered_map<char,int> mp;
        int i=0,j=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
              res=max(res,j-i+1);    
            }
            else if(mp.size()<j-i+1)
            {
                 while(mp.size()<j-i+1)
                 {
                     if(mp.find(s[i])!=mp.end())
                     {
                         mp[s[i]]--;
                         if(mp[s[i]]==0)
                             mp.erase(s[i]);
                     }
                     i++;
                 }
                
            }
            j++;
        }
        return res;
        
    }
};