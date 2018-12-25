class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<string> TA; // transposed A Matrix
        int num_words = A[0].length();
        int pos = 0;
        while(TA.size() != num_words){
            string new_word;
            for(auto word: A){
                new_word += word[pos];
            }
            pos++;
            TA.push_back(new_word);
        }
        int count = 0;
        for(auto word: TA){
            for(int i = 1; i < word.length(); i++){
                if(word[i] < word[i - 1]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};