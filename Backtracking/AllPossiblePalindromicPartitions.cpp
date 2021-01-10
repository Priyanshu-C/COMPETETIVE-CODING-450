class Solution {
public:
    //to check palim
    #define d(x) cout<<#x<<" "<<x<<endl;
    bool palim(string x)
    {
        int low=0;int high=x.size()-1;
        while(low<high)
        {
            if(x[low]!=x[high])
                return false;
            low++;high--;
        }
        return true;
    }
    
    void partitionUtil(vector<vector<string>> &RES,string &S,int start,int &len,vector<string> &Curr)
    {
        if(start>=len)
        {
            RES.push_back(Curr);
            return;
        }
        for(int i=start;i<len;i++)
        {
          //whhen we get a palimdrome substring we simply append it to a vector and pass the remaining string
            if(palim(S.substr(start,i-start+1)))
            {
              //basic backtracking
                Curr.push_back(S.substr(start,i-start+1));
                partitionUtil(RES,S,i+1,len,Curr);
                Curr.pop_back();
            }
        }
            
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> RES;
        
        vector<string> Curr;
        int len = s.size();
        partitionUtil(RES,s,0,len,Curr);
 
        return RES;
        
        
    }
};