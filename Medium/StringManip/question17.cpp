class Solution {
private:
    unordered_map<int, vector<char>> map = {
        {1,{}},
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (!digits.size())
            return res;
        recurse(digits, "", res);
        return res;
    }
    void recurse(string digits,string tmp, vector<string> & res){
        if (digits.size() == 0){
            res.push_back(tmp);
            return;
        }

        string cur;
        if (digits.size() == 1)
            cur = "";
        else
            cur = digits.substr(1);
        for (auto c: map[digits.front() - '0']){
            recurse(cur, tmp + string(1, c), res);
        }
    }
};