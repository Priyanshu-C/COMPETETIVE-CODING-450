
//Anticlockwise hehe

//Traverse for only left from top to bottom
//Traverse for leaves left to right
//Traverse for only right from bottom to top


void TraverseBottom(Node *root,vector <int> &ar)
{
    if(!root)
    return;
    if(!root->left and !root->right)
    {
        ar.push_back(root->data);
        return;
    }
    TraverseBottom(root->left,ar);
    TraverseBottom(root->right,ar);
    return;
}

void TraverseRight(Node *root,vector <int> &ar)
{
    if(!root)
    return;
    if(root->right)
    {
        TraverseRight(root->right,ar);
        ar.push_back(root->data);
    }
    else if(root->left)
    {
        TraverseRight(root->left,ar);
        ar.push_back(root->data);
    }
    return;
}

void TraverseLeft(Node *root,vector <int> &ar)
{
    if(!root)
    return;
    if(root->left)
    {
        ar.push_back(root->data);
        TraverseLeft(root->left,ar);
    }
    else if(root->right)
    {
        ar.push_back(root->data);
        TraverseLeft(root->right,ar);
    }
    return;
}

vector <int> printBoundary(Node *root)
{
    vector <int> ar;
    if(!root)
    return ar;
    
    ar.push_back(root->data);
    TraverseLeft(root->left,ar);
    TraverseBottom(root->left,ar);
    TraverseBottom(root->right,ar);
    TraverseRight(root->right,ar);
    return ar;
     //Your code here
}