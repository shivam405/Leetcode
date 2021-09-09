class Solution {
public:
    bool checkRecord(string s) {
        int i=0;
        int acount=0,lcount=0;
        while(i<s.size())
        {
            if(s[i]=='A')
                acount++;
            else if(s[i]=='L'&& s[i+1]=='L' && s[i+2]=='L' && i+2<s.size())
                lcount++;
                i++;
        }
        if(acount<2 && lcount==0)
            return true;
        return false;
        
    }
};