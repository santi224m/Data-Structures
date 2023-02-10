## Feb 9, 2023 In-Class Notes

* Use gdb command-line tool to debug
* to connect binary file to dgb use command ```file main```
  * for binary file named ```main```
* gdb allows you to see how your code works step by step
* When you get an error, you can take a look at the call stack when the error was thrown and see what caused the error
* run ```info locals``` to see state of variables
* When you create pointers, you should initialize them even if it's just to ```nullptr``` because otherwise it will be assigned to a random memory address
* after you delete a pointer, you should set the location to ```nullptr```
  * Otherwise, if you try to assign a value to the object the pointer points to, you won't get an error, you just write to a location that you shouldn't access
  
```cpp
int* p = nulltpr;
p = new int;

*p = 5;
std::cout << "p is " << *p << std::endl;

delete p;
p = nulltpr;  // if you don't include this line, you won't get an error if you
              // try to reassign *p

*p = 5;
std::cout << "p is " << *p << std::endl;

return 0;
```

* You can create a ```.txt``` file to save commands that you want to execut in gdb so that you don't have to mannualy type them in gdb each time
  * to use: ```gdb -X file-name.txt```
