// BFS iS the solution

class Solution {
public:
    #define d(x) cout<<#x<<" "<<x<<" "<<endl;
    string pushDominoes(string D) {
        
        
        string temp = D;
        int n = D.size();
        queue<int> Q1,Q2;
        
        for(int i=0;i<n;i++)
        {
            if(D[i]=='L' or D[i]=='R')
                Q1.push(i);
        }
        while(!Q1.empty())
        {
            string temp = D;
            while(!Q1.empty())
            {
                int pos = Q1.front();
                Q1.pop();
                
                if(D[pos]=='L')
                {
                    if(pos-1>=0 and temp[pos-1]=='.')
                    {
                        if(pos-2>=0 and D[pos-2]!='R')
                        {
                            temp[pos-1]='L';
                            Q2.push(pos-1);
                        }
                        if(pos-2<0)
                        {
                            temp[pos-1]='L';
                            Q2.push(pos-1);
                        }
                            
                    }
                }
                  if(D[pos]=='R')
                {
                    if(pos+1<n and temp[pos+1]=='.')
                    {
                        if(pos+2<n and D[pos+2]!='L')
                        {
                            temp[pos+1]='R';
                            Q2.push(pos+1);
                        }
                        if(pos+2>=n)
                        {
                            temp[pos+1]='R';
                            Q2.push(pos+1);
                        }
                    }
                }
               
                 // d(pos);d(D);
            }
            D = temp;
            
            swap(Q1,Q2);
            
        }
        return D;
    }
};