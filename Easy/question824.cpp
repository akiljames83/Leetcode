class Solution {
public:
    string VOWELS = "aeiouAEIOU";
    string toGoatLatin(string S) {
        string gl{""};
        int count = 1;
        while(S.find(' ') != std::string::npos){
            int index = S.find(' ');
            string first = S.substr(0,index);
            S = S.substr(index+1);
            if (VOWELS.find(first[0]) == std::string::npos) {
                first = first.substr(1) + first[0] + "ma";
                for (int i = 0; i < count; i++)
                    first += 'a';
                gl += first + " ";
            } else {
                first += "ma";
                for (int i = 0; i < count; i++)
                    first += 'a';
                gl += first + " ";
            }
            count++;
        }
        string first = S;
        if (VOWELS.find(first[0]) == std::string::npos) {
            first = first.substr(1) + first[0] + "ma";
            for (int i = 0; i < count; i++)
                first += 'a';
            gl += first;
        } else {
            first += "ma";
            for (int i = 0; i < count; i++)
                first += 'a';
            gl += first;
        }
        return gl;
        
    }
};