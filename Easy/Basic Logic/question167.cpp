class Solution {
public:
    int abinary_search(vector<int>& n, int low, int high,int t){
        if (low > high)
            return -1;
        if (low == high)
            if (n[low] == t)
                return low;
            else
                return -1;
        int mid = (low + high)/2;
        if (n[mid] == t)
            return mid;
        if (n[mid] > t)
            return abinary_search(n, low, mid - 1, t);
        else
            return abinary_search(n, mid + 1, high, t);
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++){
            if (binary_search(numbers.begin()+i+1, numbers.end(), target - numbers[i]))
                return {i+1, abinary_search(numbers, i+1, numbers.size() - 1, target - numbers[i]) + 1};
        }
    }
};