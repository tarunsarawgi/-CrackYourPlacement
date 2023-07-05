class Solution {
public:
    bool f(vector<vector<char>>& board, string word, int i,int j, int l)
    {
        if(word.size()==l)
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()
           || board[i][j]!=word[l])
            return false;
        char c=board[i][j];
        board[i][j]='*';
        bool ret=f(board,word,i+1,j,l+1)
                ||f(board,word,i-1,j,l+1)
                ||f(board,word,i,j+1,l+1)
                ||f(board,word,i,j-1,l+1);
        board[i][j]=c;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(f(board,word,i,j,0))
                    return true;
        return false;
    }
};
