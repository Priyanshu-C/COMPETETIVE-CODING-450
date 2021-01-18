#define deb(x) cout<<#x<<" "<<x<<endl;
class LRUCache {
private:
     vector<pair<int,int>> V;
    queue<pair<int,int>> Q;
    int time=0;
    int capacity=0;
    int initCap=0;
public:
    LRUCache(int x) {
        capacity=x;
        V.resize(3000,{-1,-1});
    }
    
    void debQueue(queue<pair<int,int>> Q)
    {
        cout<<".........."<<endl;
        while(!Q.empty())
        {
            cout<<Q.front().first<<" "<<Q.front().second<<endl;
            Q.pop();
        }
        cout<<".........."<<endl;
    }
    
    int get(int key) {
        
        // deb(initCap);
        // cout<<"Get"<<key<<endl;
        // debQueue(Q);
        
        int val;
        if(V[key].first==-1)
        {
            time++;
            return -1;
        }
        else
        {
            val=V[key].first;
            V[key]={val,time};
            Q.push({key,time});
        }
        time++;
        return val;
    }
    
    void put(int key, int value) {
        
        
        // deb(initCap);
        // cout<<"Put"<<key<<endl;
        // debQueue(Q);
        
        if(initCap<capacity)
        {
            if(V[key].first==-1)
            {
            Q.push({key,time});
            V[key]={value,time};
            initCap++;
            }
            else
            {
            V[key] = {value,time};
            Q.push({key,time});  
            }
        }
        else if(V[key].first!=-1)
        {
            V[key] = {value,time};
            Q.push({key,time});
        }
        else
        {
            while(Q.front().second!=V[Q.front().first].second)
            {
                Q.pop();
            }
            V[Q.front().first]={-1,-1};
            Q.pop();
            V[key]={value,time};
            Q.push({key,time});
        }
        time++;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */