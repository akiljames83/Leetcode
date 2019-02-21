class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool was_one{false};
        for (int i = 0; i < bits.size(); i++) {
            if (!was_one and !(bits[i]))
                continue;
            if (was_one and i == bits.size() - 1)
                return false;
            if (bits[i])
                was_one = not was_one;
            else
                was_one = false;
        }
        return true;
    }
};