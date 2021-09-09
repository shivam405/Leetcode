class Solution {
public:
    void Solve(string ip,string op,vector<string>& res)
    {
        if(ip.size()==0)
        {
            res.push_back(op);
            return;
        }
        if(isalpha(ip[0]))
        {
            string op1=op;
            string op2=op;
            op1.push_back(toupper(ip[0]));
            op2.push_back(tolower(ip[0]));
            ip.erase(ip.begin()+0);
            
            Solve(ip,op1,res);
            Solve(ip,op2,res);
        }
        else
        {
            string op1=op+ip[0];
            ip.erase(ip.begin()+0);
            Solve(ip,op1,res);
        }
        return;
    }
    vector<string> letterCasePermutation(string s) {
        string ip=s;
        string op="";
        vector<string>res;
        Solve(ip,op,res);
        return res; 
    }
};