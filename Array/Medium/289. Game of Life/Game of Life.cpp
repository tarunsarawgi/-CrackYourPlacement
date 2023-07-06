class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();

        vector<vector<int>> newboard=board;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            int temp=0;//this contains count of nearby 1's

            //used for checking nearby elemts
            int dx[8]={0,0,1,1,1,-1,-1,-1}; 
            int dy[8]={1,-1,0,1,-1,0,1,-1};

                for(int k=0;k<8;k++){
                int newx=i+dx[k];
                int newy=j+dy[k];

                    //if indexes don't exist
                    if(newx<0 || newx>=r || newy<0 || newy>=c){continue;}

                    if(board[newx][newy]==1){
                        temp++;
                    }
                }
        
            //update values of newboard according to given conditions
            if(board[i][j]==1 && temp<2){newboard[i][j]=0;}
            if(board[i][j]==1 && temp>3){newboard[i][j]=0;}
            if(board[i][j]==0 && temp==3){newboard[i][j]=1;}    
        }
    } 
    board=newboard;   
    }
};
