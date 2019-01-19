class KthLargest {
public:
    vector<int> ARRAY;
    int KTH{};
    KthLargest(int k, vector<int> nums) {
        ARRAY = nums;
        std::sort(ARRAY.begin(), ARRAY.end());
        KTH = k;
    }
    
    int add(int val) {
        ARRAY.push_back(INT_MAX);
        for (int i = 0; i < ARRAY.size(); i++) {
            if (ARRAY[i] < val)
                continue;
            else {
                for (int j = ARRAY.size() - 1; j > i; j--) {
                    swap(ARRAY[j], ARRAY[j-1]);
                }
                ARRAY[i] = val;
                break;
            }
        }
        return ARRAY[ARRAY.size()-KTH];
    }
};