```cpp
#include <iostream>
#include <vector>

int main()
{
    const size_t C = 10;
    int a[C];  // Valid indexes are 0-9
    int index = 0;
    
    index = (index + 1) % C;  // 1
    index = (index + 1) % C;  // 2
    index = (index + 1) % C;  // 3
    index = (index + 1) % C;  // 4
    index = (index + 1) % C;  // 5
    index = (index + 1) % C;  // 6
    index = (index + 1) % C;  // 7
    index = (index + 1) % C;  // 8
    index = (index + 1) % C;  // 9
    index = (index + 1) % C;  // 0
    index = (index + 1) % C;  // 1
    index = (index + 1) % C;  // 2
    index = (index + 1) % C;  // 3

    std::cout << "Index: " << index << std::endl;
    return 0;
}
```
