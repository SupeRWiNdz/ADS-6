// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
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
        } else {
            count++;
            int search = last;
            for (int i = first; i < last; i++) {
                if (arr[i].prior < value.prior) {
                    search = i;
                    break;
                }
            }
            for (int i = last; i > search; i--) {
                arr[i % size] = arr[(i - 1) % size];
            }
            arr[search % size] = value;
            last++;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("empty");
            }
        count--;
        return arr[first++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
