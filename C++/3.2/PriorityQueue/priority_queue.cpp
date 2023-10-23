#include <iostream>
#include <vector>

#include "priority_queue.h"

priority_queue::priority_queue() {
    this->heap_size = -1;
}

priority_queue::priority_queue(int value){
    this->heap_size = -1;
    this->push(value);
}

void priority_queue::push(int value) {
    // Insertar valor
    data.push_back(value);
    this->heap_size += 1;

    // Restructuracion del heap para que nuestro elemento mas grande sea el root
    int tsize = this->heap_size;
    int pi = (tsize - 1) / 2;
    while (tsize > 0 && data[tsize] > data[pi]) {
        int tmp = data[tsize];
        data[tsize] = data[pi];
        data[pi] = tmp;
        tsize = pi;
        pi = (tsize - 1) / 2;
    }
}


void priority_queue::pop() {
    if (this->empty()) {
        std::cout << "La queue esta vacia" << std::endl;
        return;
    }

    int li = this->heap_size;
    data[0] = data[li];
    data.pop_back();

    --this->heap_size;
    --li;

    int pi = 0;
    while (2 * pi + 1 <= li && data[pi] < data[2 * pi + 1]) {

        int ci = 2 * pi + 1;
        
        if (ci < li && data[ci] < data[ci + 1])
            ci++;

        std::swap(data[pi], data[ci]);

        pi = ci;
    }

    return;
}



int priority_queue::top() {
    // Checar si el heap esta vacio
    if (this->empty()) {
        std::cout << "La queue esta vacia" << std::endl;
        return 0;
    }

    return data[0];
}

bool priority_queue::empty() {
    return (this->heap_size == -1);
}

int priority_queue::size() {
    return this->heap_size+1;
}

void priority_queue::print()
{
    for (int i = 0; i <= this->heap_size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}