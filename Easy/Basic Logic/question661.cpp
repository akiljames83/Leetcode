class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res(M.size(), vector<int>(M[0].size(),0));
        for (int i = 0; i < M.size(); i++){
            for (int j = 0; j < M[0].size(); j++){
                bool left = j - 1 >= 0;
                bool right = j + 1 < M[0].size();
                int count{1};
                int sum{M[i][j]};
                if (i - 1 >= 0) {
                    count++;
                    sum += M[i-1][j];
                    if (left) {
                        sum += M[i-1][j-1];
                        count++;
                    }
                    if (right){
                        sum += M[i-1][j + 1];
                        count++;
                    }
                }
                if (i + 1 < M.size()){
                    sum += M[i+1][j];
                    count++;
                    if (left){
                        sum += M[i+1][j-1];
                        count++;
                    }  
                    if (right) {
                        sum += M[i+1][j+1];
                        count++;
                    }
                        
                }
                if (left) {
                    sum += M[i][j-1];
                    count++;
                }
                    
                if (right) {
                    sum += M[i][j+1];
                    count++;
                }
                res[i][j] = sum/count;   
            }
        }
        return res;
    }
};