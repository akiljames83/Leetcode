#include <cstdio>
#include <sstream>
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> dcount;
        vector<string> result;
        int occ;
        string s;
        for (auto domain: cpdomains){
            
            std::sscanf(domain.c_str(), "%d", &occ);
            
            int index = domain.find(' ');
            domain = domain.substr(index+1);
            index = domain.find('.');
            int last{0};
            while(domain.size()){
                
                if (dcount.find(domain) != dcount.end())
                    dcount[domain] += occ;
                else 
                    dcount[domain] = occ;
            
                domain = domain.substr(index+1);
                index = domain.find('.');
                if (last) 
                    break;
                if (index==std::string::npos) 
                    last = !last;
            }
        }
        stringstream ss;
        for (auto itr: dcount){
            ss << itr.second;
            ss << " ";
            ss << itr.first;
            result.push_back(ss.str());
            ss.str("");
        }
        return result;
    }
};