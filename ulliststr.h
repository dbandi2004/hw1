#ifndef ULLISTSTR_H
#define ULLISTSTR_H

#include <string>

#define ARRSIZE 10

class ULListStr {
 public:
  struct Item {
    std::string val[ARRSIZE];
    size_t first, last;
    Item *prev;
    Item *next;

    Item() {
      first = last = 0;
      prev = next = nullptr;
    }
  };

  ULListStr();
  ~ULListStr();

  size_t size() const;
  bool empty() const;
  void push_back(const std::string& val);
  void pop_back();
  void push_front(const std::string& val);
  void pop_front();
  std::string const & back() const;
  std::string const & front() const;
  void set(size_t pos, const std::string& val);
  std::string& get(size_t pos);
  std::string const & get(size_t pos) const;
  void clear();

 private:
  // Helper function to create a new Item node and link it to the list
  Item* createItem();

  // New functions added based on ulliststr.cpp
  std::string* getValAtLoc(size_t loc) const;

  // Data members
  Item* head_;
  Item* tail_;
  size_t size_;
};

#endif
