//Basically the same concept like top view manitining the level and depth and only taking the nodes which are at the last level of the particular branch 

void bottomViewUtil(struct Node *root,int d,int l,map<int,pair<int,int>> &mp)
{
    
    if(!root)
    return;
    if(mp.count(d)==0)
    {
        mp[d]={root->data,l};
    }
    else if(mp[d].second<l)
    {
        mp[d]={root->data,l};
    }
    
    bottomViewUtil(root->left,d-1,l+1,mp);
    bottomViewUtil(root->right,d+1,l+1,mp);
    return;
}


void BottomView(struct Node *root)
{
    map<int,pair<int,int>> mp;
    bottomViewUtil(root,0,0,mp);
    for(auto i:mp)
    {
        cout<<i.second.first<<" ";
    }
    
}