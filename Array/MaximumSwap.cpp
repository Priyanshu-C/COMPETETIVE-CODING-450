class Solution {
public:
    
    #define fo(i,n) for(int i=0;i<n;i++)
    void debvec(vector<int> &ar)
    {
      int R=ar.size();
      int i;
      cout<<endl<<"////////////"<<endl;
      fo(i,R)
      {
        cout<<ar[i]<<"  ";
      }
      cout<<endl<<"////////////"<<endl;
    }
    
    int maximumSwap(int num) {
        int m = INT_MIN;

        vector<int> Ar;
        while(num)
        {
            Ar.insert(Ar.begin(),num%10);
            num/=10;
        }
        
        int len = Ar.size();
        vector<int> L(len,0);
        L[len-1]=Ar[len-1];
        for(int i=len-2;i>=0;i--)
        {
            L[i] = max(L[i+1],Ar[i]);
        }
        for(int i=0;i<len;i++)
        {
            if(L[i]!=Ar[i])
            {
              
                int j=len-1;
                while(j>=0 and Ar[j]!=L[i])
                    j--;
                if(j<len)
                swap(Ar[i],Ar[j]);
                break;
            }
        }
        int res=0;
        for(int i=0;i<len;i++)
        {
            res=res*10+Ar[i];
        }
        return res;
    }
};