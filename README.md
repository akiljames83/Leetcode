## Leetcode Submissions  
The goal is to solve 365 questions by end of 2019.

## IO Optimization  
This optimization trick allows the speeds of c and c++ io to be comparable by disabling the synchronization.
```c++
auto __=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
```