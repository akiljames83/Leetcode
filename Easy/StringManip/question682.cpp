class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector <int> vec;
        for (auto str: ops) {
            int num{31000};
            std::sscanf(str.c_str(), "%d", &num);
            if (num == 31000) {
                if (str[0] == 'C') 
                    vec.erase(vec.end() - 1);
                else if (str[0] == 'D') 
                    vec.push_back(2*vec.back());
                else 
                    vec.push_back(*(vec.end() - 2) + vec.back());
            }
            else
                vec.push_back(num);
            
        }
        int sum{};
        for (auto n: vec)
            sum += n;
        return sum;
    }
};