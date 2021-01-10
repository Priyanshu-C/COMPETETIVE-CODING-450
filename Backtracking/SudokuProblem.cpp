class Solution {
public:
    
    #define d(x) cout<<#x<<" "<<x<<endl;
    #define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
    bool checkBox(vector<vector<char>>& board,int row,int col,int V)
    {
        char val = char(48+V);
        int StartRow = (row/3)*3;
        int StartCol = (col/3)*3;
        //d(StartRow);
        //d(StartCol);

        for(int i=StartRow;i<StartRow+3;i++)
           for(int j=StartCol;j<StartCol+3;j++)
               if(board[i][j]==val)
                   return false;
        return true;
    }
    
    bool checkRowAndColumn(vector<vector<char>>& board,int row,int col,int V)
    {
        char val = char(48+V);
        for(int i=0;i<9;i++)
            if(board[i][col]==val)
                return false;
        
        for(int i=0;i<9;i++)
            if(board[row][i]==val)
                return false;
        return true;
    }
    
    bool solveSudokuUtil(vector<vector<char>>& board,int row,int col)
    {
        if(row==9 and col==0)
            return true;
        if(row>=9)
            return false;
        
   //  d2(row,col);
        if(col<9)
        {
             if(board[row][col]=='.')
             for(int i=1;i<=9;i++)
            {
    
                 if(checkRowAndColumn(board,row,col,i) and checkBox(board,row,col,i))
                 {
                     board[row][col] = char(48+i);
                     if(solveSudokuUtil(board,row,col+1))
                         return true;
                     board[row][col] = '.';
                 }
             }
            else
            {
                if(solveSudokuUtil(board,row,col+1))
                         return true;
            }
            
        }
        else
        {
            if(solveSudokuUtil(board,row+1,0))
                return true;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuUtil(board,0,0);
        return;
    }
};