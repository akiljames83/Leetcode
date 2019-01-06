class Solution {
public:
    static bool empSort(Employee * first, Employee * second) {
        return (first->id < second->id);
    }
    int getImportance(vector<Employee*> employees, int id) {
        std::sort(employees.begin(), employees.end(), empSort);
        int importance{0};
        queue<int> subordinates;
        for (int i{0};i < employees.size(); i++){
            if (employees[i]->id == id) {
                importance += employees[i]->importance;
                for (auto e : employees[i]->subordinates){
                    subordinates.push(e);
                }
                break;
            }
        }
        while(!subordinates.empty()){
            int sub = subordinates.front();
            subordinates.pop();
            for (int i = 0 ;i < employees.size(); i++){
                if (employees[i]->id == sub) {
                    importance += employees[i]->importance;
                    for (auto e : employees[i]->subordinates){
                        subordinates.push(e);
                    }
                    break;
                }
            }
        }
        return importance;
    }
};