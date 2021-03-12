class Solution {
public:
    int minDeletionSize(vector<string>& S) {
        int n = S.size();
        int l = S[0].size();
        int k=0;
        int count =0;
        while(k<l)
           {
            for(int i=0;i<n-1;i++)
            {
                if(S[i][k]>S[i+1][k])
                {
                 count++;
                 break;
                }
            }
            k++;
        }
        return count;
    }
};