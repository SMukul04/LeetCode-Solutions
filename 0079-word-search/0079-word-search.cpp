class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
        int row = board.size();
        int col = board[0].size();

        if(k == (int)word.size()) return true;
        
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k]) return false;

        char temp = board[i][j];
        board[i][j] = '#'; //Mark visited

        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i -1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);

            board[i][j] = temp; //Backtrack

        return found;             
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty()){
            return false;
        }

        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};