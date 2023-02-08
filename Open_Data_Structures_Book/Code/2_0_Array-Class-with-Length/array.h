template <class T> 
class Array {
 public:
  Array(int len) {
    length_ = len;
    a = new T[len];  // create an array of type T with a size of length
  }
  int GetSize() const {
    return length_;
  }
  T& operator[](int i) {  // elements can be indexed
    if (i >= 0 && i < length_) {
      return a[i];
    }
  }

 private:
  T* a;
  int length_;
};