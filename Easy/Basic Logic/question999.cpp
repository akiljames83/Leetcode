class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        pair<int,int> pos;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R'){
                    pos = make_pair(i,j);
                    break;
                }
            }
        }
        int h = pos.first - 1;
        int w = pos.second;
        for(;;){
            // Check up
            if (h < 0)
                break;
            char cur = board[h--][w];
            if ( cur == 'p') {
                count++;
                break;
            } else if (cur == '.')
                continue;
            else if (cur == 'B')
                break;
                
        }
        h = pos.first + 1;
        for(;;){
            // Check down
            if (h >= board.size())
                break;
            char cur = board[h++][w];
            if ( cur == 'p') {
                count++;
                break;
            } else if (cur == '.')
                continue;
            else if (cur == 'B')
                break;    
        }
        h = pos.first;
        w -= 1;
        for(;;){
            // Check left
            if (w < 0)
                break;
            char cur = board[h][w--];
            if ( cur == 'p') {
                count++;
                break;
            } else if (cur == '.')
                continue;
            else if (cur == 'B')
                break;    
        }
        w = pos.second + 1;
        for (;;){
            // Check left
            if (w >= board[0].size())
                break;
            char cur = board[h][w++];
            if ( cur == 'p') {
                count++;
                break;
            } else if (cur == '.')
                continue;
            else if (cur == 'B')
                break;
        }
        return count;
    }
};