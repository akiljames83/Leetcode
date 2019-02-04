class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = nums1.size() - 1;
        int i = m - 1;
        int j = n - 1;
        while(pos > -1) {
            if (i == -1 || j == -1) {
                if (i == -1) nums1[pos--] = nums2[j--];
                else nums1[pos--] = nums1[i--];
                continue;
            }
            if (nums1[i] > nums2[j]) {
                nums1[pos--] = nums1[i--];
            } else {
                nums1[pos--] = nums2[j--];
            }
        }
    }
};