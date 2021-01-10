//https://www.youtube.com/watch?v=9-grHHGUVls&t=903s
// Refer that

class Solution {
public:
    #define d(x) cout<<#x<<" "<<x<<endl; 
    map<string,vector<string>> DP;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(DP.find(s)!=DP.end())
                    return DP[s];
        vector<string> RES;
        for(string word : wordDict)
        {
            //d(s.substr(0,word.size()));
            if(word==s.substr(0,word.size()))
            {
                
                if(word.size()==s.size())
                {
                    RES.push_back(s);
                }
                else
                {
                    vector<string> temp = wordBreak(s.substr(word.size()),wordDict);
                    for(string x:temp)
                    {
                        RES.push_back(word+" "+x);
                    }
                    
                }
                
            }
        }
        DP[s]=RES;
        return RES;
        
    }
};