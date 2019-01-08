class Solution {
public:
    string NUMBERS = "0123456789";
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, string> logpairs;
        vector<string> result, numbers, letters;
        for (auto l: logs) {
            int index = l.find(' ');
            string value = l.substr(0, index);
            string key = l.substr(index+1);
            logpairs[key] = value;
            if (NUMBERS.find(key[0]) != std::string::npos){
                numbers.push_back(key);
            } else {
                letters.push_back(key);
            }
        }
        std::sort(letters.begin(), letters.end());
        for (auto l : letters){
            result.push_back(logpairs[l] + " " + l);
        }
        for (auto l : numbers){
            result.push_back(logpairs[l] + " " + l);
        }
        return result;
    }
};