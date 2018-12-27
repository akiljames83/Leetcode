class Solution {
public:
    int binarySearch(vector<int>&A, int bottom, int top){
        int mid = (bottom + top)/2;
        
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1] ) 
            return mid;
        if (A[mid] > A[mid - 1]) 
            return binarySearch(A, mid + 1, top);
        
        return binarySearch(A, bottom, mid - 1);
    }
    int peakIndexInMountainArray(vector<int>& A) { 
        return binarySearch(A, 0, A.size() - 1);
    }
};

// Old version O(n) runtime
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) { 
        int result{};
        for(int i = 1; i < A.size() - 1; i++){
            if (A[i] > A[i-1] && A[i] > A[i + 1]) result = i;
        }
        return result;
    }
};