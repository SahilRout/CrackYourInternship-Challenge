class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)return false;
            if(board[i][col]==c)return false;
        }
        row=row-row%3;
        col=col-col%3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i+row][col+j]==c)return false;
            }
        }
        
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                       if(isValid(board,i,j,c))
                       {
                        board[i][j]=c;
                        if(solve(board))return true;
                        board[i][j]='.';
                       }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};