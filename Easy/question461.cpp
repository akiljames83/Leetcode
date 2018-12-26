class Solution {
public:
    int hammingDistance(int x, int y) {
        int tempx(x);
        int tempy(y);
        int count{};
        while (x or y) {
            tempx &= 0x01;
            tempy &= 0x01;
            //cout << tempx << " == " << tempy << endl;
            if (tempx != tempy) count++;
            x >>= 1;
            y >>= 1;
            tempx = x;
            tempy = y;
            //cout << "NEW: " << tempx << " & " << tempy << endl;
        }
        return count;
    }
};

