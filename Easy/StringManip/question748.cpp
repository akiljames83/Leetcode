#define isAlph(c) ((c >= 'a' and c <= 'z') || (c >= 'A' and c <= 'Z'))
class Solution {
public:
    struct Plate{
        int pos{0};
        int count{-1};
        int size{-1};
        Plate(int pos, int count, int size) : pos(pos), count(count), size(size) {}
    };
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        // find alph characters in licensePlate
        vector<char> letters;
        for (auto c: licensePlate){
            if (isAlph(c)){
                letters.push_back(std::tolower(c));
            }
        }
        int pos{0};
         
        
        Plate p(0,-1,-1);
        for (auto w : words){
            unordered_map<char,int> tmap;
            for (auto c : w){
                if (tmap.find(c) != tmap.end()){
                    tmap[c]++;
                } else{
                    tmap[c] = 1;
                }
            }
            
            int count{};
            for (auto c : letters){
                if (tmap.find(c) != tmap.end()){
                    tmap[c]--;
                    count++;
                    if (!tmap[c]){
                        tmap.erase(c);
                    }
                } 
            }
            Plate tmp(pos++,count,w.size());
            if (tmp.count > p.count) {
                p = tmp;
            } 
            else if ((tmp.count == p.count)) {
                if (tmp.size < p.size) {
                    p = tmp;
                }
            }

        }
        return words[p.pos];
    }
};