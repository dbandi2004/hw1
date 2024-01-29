#include <cstddef>
#include <stdexcept>
#include <string>

#define ARRSIZE 10   

class ULListStr {
 public:
  struct Item {
    std::string val[ARRSIZE];
    size_t first, last;
    Item *prev;
    Item *next;

    Item() : first(0), last(0), prev(nullptr), next(nullptr) {}
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
  Item* createItem();
  std::string* getValAtLoc(size_t loc) const;

  Item* head_;
  Item* tail_;
  size_t size_;
};

ULListStr::ULListStr() : head_(nullptr), tail_(nullptr), size_(0) {}

ULListStr::~ULListStr() {
  clear();
}

bool ULListStr::empty() const {
  return size_ == 0;
}

size_t ULListStr::size() const {
  return size_;
}

void ULListStr::clear() {
  while (head_ != nullptr) {
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
  }
  tail_ = nullptr;
  size_ = 0;
}

ULListStr::Item* ULListStr::createItem() {
  Item* newItem = new Item();
  if (tail_ == nullptr) {  
    head_ = newItem;
  } else {  
    tail_->next = newItem;
    newItem->prev = tail_;
  }
  tail_ = newItem;  
  return newItem;
}

void ULListStr::push_back(const std::string& val) {
  if (tail_ == nullptr || tail_->last == ARRSIZE) 
  {
    Item* newItem = createItem();
    newItem->val[newItem->last] = val;   
    newItem->last++;   
  } 
  else
   {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  if (head_ == nullptr || head_->first == 0) {
    Item* newItem = createItem();
    newItem->first = ARRSIZE;  
    newItem->last = ARRSIZE;   
    newItem->val[--newItem->first] = val;
    if (newItem->next != nullptr) {  
      newItem->next->prev = newItem;
    }
  } else {
    head_->val[--head_->first] = val;
  }
  size_++;
}


void ULListStr::pop_back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  tail_->last--;
  if (tail_->last == tail_->first) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;  
    }
    delete temp;
  }
  size_--;
}

void ULListStr::pop_front() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  head_->first++;
  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;  
    delete temp;
  }
  size_--;
}

std::string const & ULListStr::back() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  return head_->val[head_->first];
}


void ULListStr::set(size_t loc, const std::string& val) {
  std::string& item_ref = get(loc);
  item_ref = val;
}

std::string& ULListStr::get(size_t loc) {
  if (loc >= size_) {
    throw std::out_of_range("Index out of range");
  }
  Item* current = head_;
  while (current != nullptr) {
    size_t numItems = current->last - current->first;
    if (loc < numItems) {
      return current->val[current->first + loc];
    }
    loc -= numItems;
    current = current->next;
  }
  throw std::out_of_range("Index out of range");
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return nullptr;
  }
  Item* current = head_;
  while (current != nullptr) {
    size_t numItems = current->last - current->first;
    if (loc < numItems) {
      return &(current->val[current->first + loc]);
    }
    loc -= numItems;
    current = current->next;
  }
  return nullptr;
}
