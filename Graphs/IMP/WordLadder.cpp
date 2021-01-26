class Solution {
public:
    
    //STACK

#define fo(i,n) for(int i=0;i<n;i++)

void debstack(queue<string> s)
{
  cout<<endl<<"..........."<<endl;
  while(!s.empty())
  {
    cout<<s.front()<<" ";
    s.pop();
  }
  cout<<endl<<"..........."<<endl;
}
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> S;
        set<string> usedS;
        
        for(string x:wordList)
        S.insert(x);
        
        queue<string> Q;
        Q.push(beginWord);
        
        int count=1;
        while(!Q.empty())
        {   
            //debstack(Q);
            count++;
            int n=Q.size();
            while(n--)
            {
                
                string tmp = Q.front();
                Q.pop();
                int ren = tmp.size();
                for(int i=0;i<ren;i++)
                {
                    int lol =26;
                    while(lol--)
                    {
                        string word = tmp.substr(0,i) + char(97+lol) + tmp.substr(i+1,ren-i);  
                        if(S.find(word)!=S.end() and usedS.find(word)==usedS.end())
                            {
                                if(word == endWord)
                                return count;
                                // cout<<word<<endl;
                                Q.push(word);
                                usedS.insert(word);
                            }
                    }
                }
            }
           
        }
        return 0;
        
    }
};