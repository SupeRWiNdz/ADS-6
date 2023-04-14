// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

class TPQueue {
 private:
    T arr[size];
    int first, last, count;

 public:
    TPQueue() : first(0), last(0), count(0) {
        arr = new T[size];
    }
    ~TPQueue() {
        delete[] arr;
    }
    bool isEmpty() const {
        return 0 == count;
    }
    bool isFull() const {
        return size == count;
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full!");
        }
        else {
            int search = first;
            while (search != last && value.prior <= arr[search].prior)
                ++search;
            for (int i = size; i > search; i--)
                arr[i] = arr[i - 1];
            ++count;
            arr[search] = value;
        }
    }
    const T& pop() {
        if (isEmpty())
            throw std::string("empty");
        count--;
        return arr[first++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
