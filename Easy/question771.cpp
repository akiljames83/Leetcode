class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> jmap;
        int count = 0, i;
        for (i = 0; i < J.length(); i++){
            jmap.insert(make_pair(J[i], 1));
        }
        for (i = 0; i < S.length(); i++) {
            if (jmap.find(S[i]) != jmap.end())
                count += 1;
        }
        return count;
    }
};
