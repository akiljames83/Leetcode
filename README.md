## Leetcode Submissions  
The goal is to solve 365 questions by end of 2019.

## IO Optimization  
This optimization trick allows the speeds of c and c++ io to be comparable by disabling the synchronization.
```c++
auto fast_io =[]()
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

## String functions C++11
- Some helpful c++ string methods:
	- `index = str.find('c')` - Returns index of first occurence of `c`, if not found returns <strong><em>std::string::npos</em></strong>
	- `str.substr(5)` - Returns a substring of the original string str from index 5 to the end  
- sstream library is also useful, some methods:
	- Use `<<` to append values to string
	- Convert variable to string use `.str()` method
	- Clear contents through using `.str("")`

## Using sscanf in C++11
- To use sscanf, you <em><strong>cannot</strong></em> use C++ classes like the string class.
- To make use of the string class, you need to convert it into a c_str(), then it can be modified.

```c++
#include <cstdio>

using namespace std;
int main() {
	string str = "Akil is 50 years old.";
	int age{};
	std::sscanf(str.c_str(), "%d", &age);
	cout << age << endl; // prints 50
	return 0;
}
```
## TODO
- Figure out iterative approach for question 590 and lookover iterative approach for 589