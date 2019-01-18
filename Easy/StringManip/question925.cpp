class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.length() == typed.length() and !strcmp(name.c_str(), typed.c_str()))
            return true;
        int pos{};
        int t_len = typed.length();
        int n_len = name.length();
        for (int i = 0; i < name.length(); i++){
            if (pos >= t_len)
                return false;
            if (name[i] == typed[pos]){
                pos++;
                if (i + 1 < n_len) {
                    if (name[i+1] == name[i]) {
                        continue;
                    }
                }
                // else
                while (pos < t_len) {
                    if (name[i] == typed[pos]){
                        pos++;
                    } else {
                        break;
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
};