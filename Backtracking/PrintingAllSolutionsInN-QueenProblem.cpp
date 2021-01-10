class Solution {
public:
    
//Solved in leetcode eventually

bool safe(vector<vector<int>> &Q,int row,int col,int N)
{
    //Col Check
    int CC=0;
    for(int i=0;i<N;i++)
    {
    if(Q[i][col]==1)
    CC++;
    if(CC>0)
    return false;
    }
    //Diagonal Checks left top
    int i=row,j=col;
    int DC=0;
    while(i>=0 and j>=0)
    {
      if(Q[i][j]==1)
      DC++;
      if(DC>0)
      return false;
      i--;j--;
    }
    //Diagonal Checks bottom right
    i=row,j=col;
    DC=0;
    while(i<N and j>=0)
    {
      if(Q[i][j]==1)
      DC++;
      if(DC>0)
      return false;
      i++;j--;
    }
    //Diagonal Checks top right
    i=row,j=col;
    DC=0;
    while(i>=0 and j<N)
    {
      if(Q[i][j]==1)
      DC++;
      if(DC>0)
      return false;
      i--;j++;
    }
    return true;
}
    
vector<string> serialize(vector<vector<int>> &Q,int N)
{
    vector<string> S;
    for(int i=0;i<N;i++)
    {
        string x="";
       for(int j=0;j<N;j++)
            {
                if(Q[i][j]==1)
                    x=x+'Q';
                else
                    x=x+'.';
            } 
        S.push_back(x);
    }
    return S;
}
    
vector<vector<string>> ANS;
void solveQueenUtil(vector<vector<int>> &Q,int row,int N)
{

    if(row==N)
    {
    ANS.push_back(serialize(Q,N));
    return;
    }
    for(int i=0;i<N;i++)
    {
      if(safe(Q,row,i,N))
      {
        Q[row][i]=1;
        solveQueenUtil(Q,row+1,N);
        Q[row][i]=0;
      }
    }
    return;
}
    
    
vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> Q(n,vector<int> (n,0));
        solveQueenUtil(Q,0,n);
        return ANS;
    }
};