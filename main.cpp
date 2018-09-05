#include <iostream>

#include "slist.h"
#include "dlist.h"


template <typename T>
struct Greater {
    bool operator()(T a, T b) {
        return a >= b; // What would happend without the =?
    }
};

template <typename T>
struct Less {
    bool operator()(T a, T b) {
        return a <= b; // What would happend without the =?
    }
};

struct Integer {
    typedef int T;
    typedef Less<T> Operation;
};

struct Float {
    typedef float T;
    typedef Greater<T> Operation;
};

using namespace std;

int main(){
    DList<Integer> listadoble;
    listadoble.push_front(6);
    listadoble.push_front(8);
    listadoble.push_back(12);
    listadoble.pop_front();
    listadoble.print();
}