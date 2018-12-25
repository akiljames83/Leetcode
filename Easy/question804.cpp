class Solution {
public:
    vector<string> ALPH = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>::iterator it = words.begin();
        std::set<string> uniqueCodes;
        string morse = "";
        for(it; it != words.end(); it++) {
            for (char &ch: *it){
                morse += ALPH[int(ch) - (int)'a'];
            }
            uniqueCodes.insert(morse);
            //cout << morse << endl;
            morse = "";
        }
        return uniqueCodes.size();
    }
};