void topViewUtil(struct Node *root,int d,int l,map<int,pair<int,int>> &mp)
{
    
    if(!root)
    return;
    if(mp.count(d)==0)
    {
        mp[d]={root->data,l};
    }
    else if(mp[d].second>l)
    {
        mp[d]={root->data,l};
    }
    
    topViewUtil(root->left,d-1,l+1,mp);
    topViewUtil(root->right,d+1,l+1,mp);
    return;
}


void topView(struct Node *root)
{
    map<int,pair<int,int>> mp;
    topViewUtil(root,0,0,mp);
    for(auto i:mp)
    {
        cout<<i.second.first<<" ";
    }
    
}
