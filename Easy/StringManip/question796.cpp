class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) return false;
        if (!A.length() and !B.length()) return true;
        char start{B[0]};
        if (A.find(start) == std::string::npos)
            return false;
        else {
            string C = A;
            unordered_set<string> past;
            for(int i = 0; i < 10; i++){
                int pos = C.find(start);
                string tmp = C.substr(pos) + C.substr(0,pos);
                
                if (past.find(tmp) != past.end())
                    return false;
                if (!strcmp(B.c_str(), tmp.c_str()))
                    return true;
                past.insert(C);
                C = tmp.substr(1) + tmp.substr(0,1);
                
            }
            
        }
        return false;
    }
};