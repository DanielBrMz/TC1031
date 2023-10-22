#include <iostream>
#include <vector>

#include "priority_queue.h"

priority_queue::priority_queue()
{
    this->heap_size = -1;
}

priority_queue::priority_queue(int value)
{
    this->heap_size = -1;
    this->push(value);
}

void priority_queue::push(int value)
{   
    // Insertar valor
    data.push_back(value);
    this->heap_size += 1;

    // Restructuracion del heap para que nuestro elemento mas grande sea el root
    int tsize = this->heap_size;
    while (tsize > 0) {
        int pi = (tsize - 1) / 2;
        if (data[tsize] <= data[pi])
            break;
        int tmp = data[tsize];
        data[tsize] = data[pi];
        data[pi] = tmp;
        tsize = pi;
    }
}

void priority_queue::pop()
{
    // Checar si el heap esta vacio
    if (this->empty()) {
        std::cout << "La queue esta vacia" << std::endl;
        return;
    }

    // Borrar el valor mas alto del heap
    int li = this->heap_size; // last_index
    std::swap(data[0], data[li]); // Reemplazar el valor mas alto del heap por el ultimo4
    data.pop_back();

    // Actualizar el valor del heap_size y el temp_size
    --this->heap_size;
    --li;

    // parent_index
    int pi = 0;
    // Restructuracion del heap para que nuestro elemento mas grande sea el root
    while (true)
    {
        int ci = pi * 2 + 1;
        if (ci > li)
            break;
        int rc = ci + 1;
        if (rc <= li && data[rc] > data[ci])
            ci = rc;
        if (data[pi] >= data[ci])
            break;
        int tmp = data[pi];
        data[pi] = data[ci];
        data[ci] = tmp;
        pi = ci;
    }

    return;
}

int priority_queue::top()
{
    // Checar si el heap esta vacio
    if (this->empty())
    {
        std::cout << "La queue esta vacia" << std::endl;
        return 0;
    }

    return data[0];
}

bool priority_queue::empty()
{
    return (this->heap_size == -1);
}

int priority_queue::size()
{
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