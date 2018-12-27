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