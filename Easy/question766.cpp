// Question766
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        if (!M or !N) return true;
        for(int i = 0; i < N; i++){
            int y{M - 1}; 
            int x{i};
            //cout << "Matrix[y][x]: " << y << " " << x << " " << matrix[y][x] << endl;
            int row_val{matrix[y][x]};
            while( (--x >= 0) and (--y >= 0)){
                //cout << "Matrix[y][x]: " << y << " " << x << " " << matrix[y][x] << endl;
                if (matrix[y][x] != row_val) 
                    return false;

            }
        }
        for(int i = M - 1; i >= 0; i--){
            int y{i};
            int x{N - 1};
            //cout << "Matrix[y][x]: " << y << " " << x << " " << matrix[y][x] << endl;
            int row_val{matrix[y][x]};
            while( (--x >= 0) and (--y >= 0)){
                //cout << "Matrix[y][x]: " << y << " " << x << " " << matrix[y][x] << endl;
                if (matrix[y][x] != row_val) 
                    return false;
            }
        }
        return true;
    }
};

