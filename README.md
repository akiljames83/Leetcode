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

## Input and Output in C++  
- Make use of cstdio library to use c features for printing to screen.
- The stdio.h library can also be used, but this can polute the global namespace.
- Important note: iostream is faster to run whereas stdio is faster to build.

```c++
#include <cstdio>

using namespace std;

int main() {
  printf("Hello World\n");
}
```