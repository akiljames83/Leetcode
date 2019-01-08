#include <sstream>
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        while(s.size()){
            int index = s.find(' ');
            if (index == std::string::npos) {
                std::reverse(s.begin(), s.end());
                ss << s;
                return ss.str();
            }
            string temp = s.substr(0, index);
            s = s.substr(index+1);
            std::reverse(temp.begin(), temp.end());
            ss << temp << " ";
            //cout <<"'"<< temp << "'"<<endl;
            //cout <<"'"<< s << "'"<<endl;
            //cout <<"'"<< ss.str() << "'"<<endl;
        }
        return "";
    }
};

// Inplace solution -> Beats 100%!
class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        if (size == 0 || size == 1) return s;
        int front{};
        for (int i = 0; i < size; i++){
            if ((s[i] == ' ') || (i == size - 1)){
                
                int back{i - 1};
                if (i == size - 1) back++;
                while(front <= back){
                    char tmp = s[front];
                    s[front++] = s[back];
                    s[back--] = tmp;
                }
                front = i+1;
            }
        }
        return s; 
    }
};