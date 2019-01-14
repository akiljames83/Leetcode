class MyHashSet {
public:
    /** Initialize your data structure here. */
    int map[1000000]{};
    MyHashSet() {
        
    }
    
    void add(int key) {
        map[key] = 1;
    }
    
    void remove(int key) {
        map[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return (bool)map[key];
    }
};