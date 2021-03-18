class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int> mp1,mp2;
        for(char i:S)
            mp2[i]++;
        int n = S.size();
        vector<int> RES;
        int len=0;
        for(int i=0;i<n;i++)
        {
            len++;
            if(mp1.count(S[i])==0)
            {
                mp1[S[i]]=mp2[S[i]];
            }
            mp1[S[i]]--;
            if(mp1[S[i]]==0)
                mp1.erase(S[i]);
            if(mp1.empty())
            {
 
                RES.push_back(len);
                    // cout<<S[i];
                len=0;
            }
        }
        return RES;
    }
};