class Solution {
public:
    string interpret(string command) {
        string res="",temp="";
        for(int i=0;i<command.size();i++)
        {
            if(command[i]=='G')
                res+="G";
            else if(command[i]=='(' || command[i]==')' || command[i]=='a'  || command[i]=='l')
            {
                temp.push_back(command[i]);
                if(temp=="()")
                {
                   res+="o";
                    temp="";
                }
                    
                else if(temp=="(al)")
                {
                    res+="al";
                    temp="";
                }
                   
                else
                    continue;
                
            }
        }
        return res;
        
    }
};