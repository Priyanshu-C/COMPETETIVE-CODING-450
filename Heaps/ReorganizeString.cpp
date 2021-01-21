class Solution {
public:
    
        #define deb(x) cout << #x << "=" << x << endl
        #define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
    
    string reorganizeString(string S) {
            map<char,int> mp;
        for(char i:S)
            mp[i]++;
        priority_queue<pair<int,char>> PQ;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            deb2(i->second,i->first);
            PQ.push({i->second,i->first});
        }
        string res="";
        int n=S.size();
        // deb(n);
        // deb(n/2+1);
        if(n%2==0)
            if(PQ.top().first>n/2)
                return "";
        if(n%2==1)
        if(PQ.top().first>((n/2)+1))
                return "";
        int pos=1;
        while(!PQ.empty())
        {
            pair<int,char> x = PQ.top();
            PQ.pop();
            if(res == "")
                for(int i=0;i<x.first;i++)
                    res+=x.second;
            else
            {
                int count = x.first;
                char alp = x.second;
                
              //  deb2(count,alp);
                
                while(count--)
                {
                    deb(pos);
                    pos = pos % res.size() ;
                    res = res.substr(0,pos) + alp + res.substr(pos);
                    pos+=2;
                    
                }
            }
        }
        return res;
    }
};  