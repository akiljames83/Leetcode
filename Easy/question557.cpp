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