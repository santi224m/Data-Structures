## March 21, 2023 In-Class Notes

# Midterm Review

```cpp
template <class T>
class MyLinkedList {
 public:
   bool exists(T value) {
     return exists(this->begin(), value);
   }
 
 private:
  bool exists(Iterator startPos, T value) {  // helper function for exists(T value)
    // Base Case
    if (this->empty()) {
      return false;
    } else if (startPos == this->end()) {
      return false;
    } else if (*itr == value) {
      return true;
    }
    
    // Recursive Case
    return this->exists(++itr, value);
  }
}
```

* ```push``` and ```pop``` on a vector have linear time complexity, but constant time complexity when amortized/averaged
