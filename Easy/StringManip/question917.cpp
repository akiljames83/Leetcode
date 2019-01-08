public:
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHLIJKLMNOPQRSTUVWXYZ";
    string reverseOnlyLetters(string S) {
        int begin{0};
        int end{S.length() - 1};
        while(begin <= end){
            if (letters.find(S[begin]) == std::string::npos){
                begin++;
                continue;
            }
            if (letters.find(S[end]) == std::string::npos){
                end--;
                continue;
            }
            char tmp = S[begin];
            S[begin++] = S[end];
            S[end--] = tmp;
        }
        return S;
    }
};