class Solution {
public:
    double AreaFormula(vector<int>& A, vector<int>& B, vector<int>& C){
        double area = A[0] * (B[1]- C[1]) - A[1] * (B[0] - C[0]) + (B[0] * C[1] - C[0] * B[1]);
        area/=2;
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double area{0};
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                for (int k = 0; k < points.size(); k++){
                    if (i != j and j != k and i != k){
                        area = max(area, AreaFormula(points[i],points[j],points[k]));
                    }
                }
            }
        }
        return area;
    }
};