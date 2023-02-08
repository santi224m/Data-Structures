class array {
 public:
  array(int len) {
    length_ = len;
    a = new T[length];
  }

 private:
  T* a;
  int length_;
};