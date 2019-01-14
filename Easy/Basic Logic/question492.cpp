class Solution {
public:
    vector<int> constructRectangle(int area) {
        int left = pow(area, 0.5);
        int right = left;
        while (true){
            if (left * right == area){
                vector<int> res = {right, left};
                if (left > right)
                    res = {left, right};
                return res;
            }
            if (left * right > area)
                left--;
            else
                right++;
        }
    }
};