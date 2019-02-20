class Logger {
private:
    unordered_map<string,int> map;
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (this->map.find(message) != this->map.end()){
            if (this->map[message] + 10 <= timestamp){
                this->map[message] = timestamp;
                return true;
            } else {
                return false;
            }
        } 
        this->map[message] = timestamp;
        return true;
    }
};