#include<bits/stdc++.h>
using namespace std;


class Solution {
    //难点在于t的意义和   cubs的确定
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty())return true;
        const int n=board.size();
        const int m=board[0].size();
        vector<vector<bool>>rows(n,vector<bool>(m,false));
        vector<vector<bool>>cols(n,vector<bool>(m,false));
        vector<vector<bool>>cubs(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')continue;
                int t=board[i][j]-'1';//这个表示的是数字的对应索引 0---8； 
                if(rows[i][t]||cols[t][j]||cubs[3*(i/3)+j/3][t])return false;//在行、列、方格、中查看这个位置是否已经存在；
                rows[i][t]=cols[t][j]=cubs[3*(i/3)+j/3][t]=true;//将行、列、方格中的这个位置为true；
            }
        }
        return true;
    }
};
void test000(){
    vector<vector<char>>board=
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','.','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool res=Solution().isValidSudoku(board);
    cout<<res<<endl;
}
int main(){
    test000();
    cout<<"hello world"<<endl;
    return 0;
}