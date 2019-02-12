## Good questions to go over
- cleaner solution to question 654 - (N-Ary Tree)

## IO Optimization
```c++
// One Liner:
auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
```

## Kadanes Algorithm:
- Good resource: https://afshinm.name/2018/06/24/why-kadane-algorithm-works/

## Min Heap and Max Heap Implementation:
```c++
#include <queue>

using namespace std;

int main() {
	// Max Heap Implementation:
	priority_queue<int> min_heap;
	for (int i = 0; i < 10; i++)
		min_heap.push(i);

	print_heap(min_heap); // 9 8 7 6 5 4 3 2 1 0

	// Max Heap Implementation:
	priority_queue<int, vector<int>, greater(int)> max_heap;
	for (int i = 0; i < 10; i++)
		max_heap.push(i);

	// 0 1 2 3 4 5 6 7 8 9

	return 0; 
}
```