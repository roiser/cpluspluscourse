#include <iostream>
#include <vector>
#include "NVector.hpp"

template<typename T>
void swap(std::vector<T> &v, int a, int b) {
    T mem = v[a];
    v[a] = v[b];
    v[b] = mem;
}

template<typename T>
void randomize(std::vector<T> &v) {
    // we randomize via len random inversions
    std::size_t len = v.size();
    for (std::size_t i = 0; i < len; i++) {
        int a = rand()%len;
        int b = rand()%len;
        swap(v, a, b);
    }
}

template<typename T>
std::vector<T> getRandomVector(int len) {
    // allocate vectors
    std::vector<T> v(len);
    // fill and randomize v
    for (int i = 0; i < len; i++) v[i] = T();
    randomize(v);
    return v;
}

int main() {
    std::vector<NVector<10000, int>> v = getRandomVector<NVector<10000,int> >(10000);
}
