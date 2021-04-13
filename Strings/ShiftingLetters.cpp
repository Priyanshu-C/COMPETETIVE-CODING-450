class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        
        int n = shifts.size();
        int ns = S.size();
        if(n==1)
        {
            S[0] = char(((int)S[0]+shifts[0]-97)%26+97); 
            return S.substr(0,n);
        }
        for(int i=n-1;i>0;i--)
            shifts[i-1] = (shifts[i-1] + shifts[i])%26;  
        for(int i=0;i<=ns;i++)
        {
           // cout<<(int)S[i]+shifts[i]<<" ";
            if(i<n)
            S[i] = char(((int)S[i]+shifts[i]-97)%26+97);   
        }
        return S.substr(0,n);
        
    }
};