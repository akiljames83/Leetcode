class Solution {
public:
    unordered_map<int,string> base{
        {0, ""},
        {1, " Thousand"},
        {2, " Million"},
        {3, " Billion"}
    };
    unordered_map<int,string> numbers {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"}
    };
    unordered_map<int,string> ten2teen{
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"}
    };
    unordered_map<int,string> ofTens{
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };
    string lessThanHundred(int cur) {
        if (cur < 10)
            return numbers[cur];
        if (cur < 20)
            return ten2teen[cur];
        
        string temp = ofTens[cur - cur % 10];
        if (cur % 10)
            return temp + " " + numbers[cur % 10];
        else
            return temp;
    }
    string helper(int pos, int num, string res) {
        if (!num) {
            while (res.back() == ' ') {
                res = res.substr(0,res.length()-1);
            }
            return res;
        }
            
        int cur = num % 1000;
        num /= 1000;
        
        if (!cur)
            return helper(pos+1, num, res);
        else if (cur < 100) {
            return helper(pos+1, num, lessThanHundred(cur) + base[pos] + " " + res);
        }
        string temp = numbers[cur / 100] + " Hundred";
        if (!(cur % 100)) {
            return helper(pos + 1, num, temp + base[pos] + " "+ res);
        } 
        return helper(pos + 1, num, temp + " " + lessThanHundred(cur % 100) + base[pos] + " " + res);

    }
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        return helper(0, num, "");
        
    }
};