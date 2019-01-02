## Leetcode Submissions  
The goal is to solve 365 questions by end of 2019.

## IO Optimization  
This optimization trick allows the speeds of c and c++ io to be comparable by disabling the synchronization.
```c++
auto fast_io =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
```

## Unordered Map vs Map 
- The main difference between these data structures is that map keeps the items in order, which can be beneficial if needed.
- Unordered Map takes up more memory generally as it stores a much larger array.
- However, it appears that unordered map is much more efficient for a pure look up table.
- To use it: `unordered_map <int> myMap;` 

## Initializer list Map
```c++
std::map<std::string, int> mapOfMarks = 
{
	{"Riti",2},
	{"Jack",4}
};
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
	- To reverse a string: `std::reverse(str.begin(), str.end());`
	- `str.find_first_of(C,P)` -> Finds first occurence of any character in C starting at position P
	- `str.find_last_of(C,P)` -> Similar function to previous but finds last occurence
- sstream library is also useful, some methods:
	- Use `<<` to append values to string
	- Convert variable to string use `.str()` method
	- Clear contents through using `.str("")`
- <em>Question811.cpp</em> goes over a lot of these functions!

## Special String Manipulaion
- Convert string to lowercase:
```c++
#include <algorithm>
#include <string>

std::string s = "ABC";
std::transform(s.begin(), s.end(), s.begin(), ::tolower);
```

## Using sscanf in C++11
- To use sscanf, you <em><strong>cannot</strong></em> use C++ classes like the string class.
- To make use of the string class, you need to convert it into a c_str(), then it can be modified.

```c++
#include <cstdio>
#include <iostream> // for string class

using namespace std;
int main() {
	string str = "50 years old.";
	int age{};
	std::sscanf(str.c_str(), "%d", &age);
	printf("%d\n", age); // prints 50
	return 0;
}
```

## Bit Manipulation
- Question476.cpp covers some good concepts, review it;
- `<<` that shifts bits to the left which <strong>increases</strong> the value of the integer.
- `>>` that shifts bits to the right which <strong>decreases</strong> the value of the integer.
- To flip a bit: `bit ^= 0x01`; XOR operation with a single bit will perform the operation on least significant bit.
- To retrieve the value from last bit: `bit &= 0x01` (in-place) or `bit = num & 0x01` (storing in new number). 

## TODO
- Figure out iterative approach for question 590 and lookover iterative approach for 589
- Inplace solution for question557.cpp
- Go over question821 elegant solution
- Iterative solution for question872
- Go over algorithm library
- Go over recursive solutions for Question 669; review YOUR iterative solution!

## Good Review Questions:
- Trimming Binary Tree : Question 669 
