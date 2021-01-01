//Simply calculate the sum and length till last roots and calculate max value

void sumOfLongRootToLeafPathUtil(Node* root,int sum,int level,int &maxval,int &maxlen)
{
    if(!root)
    {   
        if(maxlen<level)
        {
            maxlen=level;
            maxval = sum;
        }
        else if(maxlen==level)
        {
            maxval=max(sum,maxval);
        }
        return;
    }
    
    //cout<<sum<<" "<<endl;
    
    sumOfLongRootToLeafPathUtil(root->left,root->data+sum,level+1,maxval,maxlen);
    sumOfLongRootToLeafPathUtil(root->right,root->data+sum,level+1,maxval,maxlen);
	// Code here
}

int sumOfLongRootToLeafPath(Node* root)
{
    int maxval = INT_MIN;
    int maxlen = 0;
    
    if(!root)
    return 0;
    
    sumOfLongRootToLeafPathUtil(root,0,0,maxval,maxlen);
    
    return maxval;
	// Code here
}