class Solution {
public:
    int getSum(vector<int> & A) {
        int sum = 0;
        for (auto a: A)
            sum += (a%2) ? 0 : a;
        return sum;
    }
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& q) {
        vector<int> R(q.size(), 0);
        int sum = getSum(A);
        for (int i = 0; i < q.size(); i++) {
            if (!(A[q[i][1]] % 2)) {
                sum -= A[q[i][1]];
                A[q[i][1]] += q[i][0];
                if (!(A[q[i][1]] % 2)) 
                    sum += A[q[i][1]];
            } else {
                A[q[i][1]] += q[i][0];
                if (!(A[q[i][1]] % 2)) 
                    sum += A[q[i][1]];
            }
            R[i] = sum;
        }
        return R;
    }
};