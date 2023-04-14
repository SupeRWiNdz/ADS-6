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
        if (count > size) {
            throw std::string("Full!");
        } else {
            int search = first;
            while (search != last) {
                if (value.prior <= arr[(search - 1 + size) % size].prior) {
                    arr[search] = arr[search + 1 + size) % size];
                    search = (search - 1 + size) % size
                } else {
                break; }
            }
            for (int i = last; i != search; (i - 1 + size) % size) {
                arr[i] = arr[(i - 1 + size) % size];
            }
            count++;
            arr[search] = value;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("empty");
            }
        T value = arr[first];
        first = (first + 1) % size;
        count--;
        return value;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
