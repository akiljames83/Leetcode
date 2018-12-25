class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // Can also use a set instead of hashtable, but hash appears to be faster
        map<string, int> uniqueEmails;
        vector<string>::iterator it = emails.begin();
        
        size_t posAt, posDot, posPlus;
        int count = 0;
        
        while(it != emails.end()){
            string email = *it;
            //cout << "Before: " << email << endl;
            posAt = email.find("@");
            posDot = email.find(".");
            while(posDot != string::npos && posDot < posAt) { // string::npos when the character is not found
                email.erase(posDot, 1);
                posDot = email.find(".");
                posAt = email.find("@");
            }
            posPlus = email.find("+");
            //cout << "Middle: " << email << endl;
            if (posPlus != string::npos && posPlus < posAt) {
                email.erase(posPlus, posAt-posPlus);
            }
            //cout << "After: " << email << endl;
            if (uniqueEmails.find(email) == uniqueEmails.end()){
                uniqueEmails.insert(make_pair(email,1));
                count += 1;
            }
            it++;
        }
        
        return count;
    }
};

// Version 2:
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> uniqueEmails;
        vector<string>::iterator it = emails.begin();
        
        size_t posAt, posDot, posPlus;
        int count = 0;
        
        while(it != emails.end()){
            string email = *it;
            //cout << "Before: "<< email << endl;

            posAt = email.find("@");
            posDot = email.find(".");
            while(posDot != string::npos && posDot < posAt) {
                email.erase(posDot, 1);
                posDot = email.find(".");
                posAt--;
            }
            posPlus = email.find("+");
            //cout << "Middle: "<< email << endl;
            if (posPlus != string::npos && posPlus < posAt) {
                email.erase(posPlus, posAt-posPlus);
            }
            //cout << "After: "<< email << endl;
            if (uniqueEmails.find(email) == uniqueEmails.end()){
                uniqueEmails.insert(make_pair(email,1));
                count += 1;
            }
            
            
            it++;
        }
        
        return count;
    }
};
