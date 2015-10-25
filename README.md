# range
C++ range library

Let you iterate integer range in python style.

```c++
#include <iostream>

#include "include/range.hh"
#include "include/iota_range.hh"

int main()
{
    using range::xrange;

    for(auto i : xrange(10))
        std::cout << i << " ";

    // print 0 1 2 3 4 5 6 7 8 9

    for(auto i : xrange(5, 10))
        std::cout << i << " ";

    // print 5 6 7 8 9

    for(auto i : xrange(4, 10, 2))
        std::cout << i << " ";

    // print 4 6 8
}
```
