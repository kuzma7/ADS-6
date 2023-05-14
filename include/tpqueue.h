// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int capacity>
class TPQueue {
 private:
    T* synonymous_array;
    int capacityMax;
    int first_index, last_index, count;

 public:
    TPQueue() : capacityMax(capacity), first_index(0), last_index(0), count(0) {
        synonymous_array = new T[capacityMax + 1];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::string("Sorry, Dude, but the queue is FULL!");
        }
        int currently = last_index;
        if (count) {
            for (int i = first_index; i < last_index; ++i) {
                if (synonymous_array[i].prior < value.prior) {
                    currently = i;
                    break;
                }
            }
        }
        if (count) {
            for (int i = last_index; i > currently; --i)
                synonymous_array[i] = synonymous_array[i - 1];
        }
        synonymous_array[currently] = value;
        count++;
        last_index++;
        last_index %= (capacityMax + 1);
    }

    const T& pop() {
        if (isEmpty()) {
            throw std::string("Sorry, Dude, but the queue is EMPTY!");
        }
        first_index %= (capacityMax + 1);
        count -= 1;
        return synonymous_array[first_index++];
    }

    void get() {
        if (isEmpty()) {
            throw std::string("Sorry, Dude, but the queue is EMPTY!");
        }
        return synonymous_array[first_index].ch;
    }

    ~TPQueue() {
        delete[] synonymous_array;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
