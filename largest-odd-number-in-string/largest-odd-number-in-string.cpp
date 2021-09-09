class Solution {
public:
    string largestOddNumber(string num) {
        int l=num.length();
        for(int i=l-1;i>=0;i--)
        {
            if(int(num[i])%2==0)
            {
                num.pop_back();
            }
           else
               break;
            
        }
          return num;
    }
};