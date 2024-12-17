#pragma once
#include <iostream>
#include <vector>

template <typename T>
class PriorityQueue
{
    static size_t leftChild(size_t i);
    static size_t rightChild(size_t i);
    static int parent(int i);

    void heapify(size_t ind);
    std::vector<T> data;

public:
    PriorityQueue() = default;
    PriorityQueue(const std::vector<T>& v);

    bool isEmpty() const;
    const T& peek() const;
    void pop();
    void insert(const T& el);
    size_t size() const;
};

template <typename T>
size_t PriorityQueue<T>::leftChild(size_t i)
{
    return 2 * i + 1;
}

template <typename T>
size_t PriorityQueue<T>::rightChild(size_t i)
{
    return 2 * i + 2;
}

template <typename T>
int PriorityQueue<T>::parent(int i)
{
    return (i - 1) / 2;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
    return data.empty();
}

template <typename T>
void PriorityQueue<T>::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Empty queue");
    }

    data[0] = data[data.size() - 1];
    data.pop_back();

    if (data.size() != 0)
    {
        heapify(0);
    }
}

template <typename T>
const T& PriorityQueue<T>::peek() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Empty queue");
    }

    return data[0];
}

template <typename T>
void PriorityQueue<T>::heapify(size_t currentElementIndex)
{
    size_t leftChildIndex = leftChild(currentElementIndex);
    size_t rightChildIndex = rightChild(currentElementIndex);

    bool shouldGoLeft = leftChildIndex < data.size() && data[leftChildIndex] > data[currentElementIndex];
    bool shouldGoRight = rightChildIndex < data.size() && data[rightChildIndex] > data[currentElementIndex];

    if (shouldGoLeft && shouldGoRight)
    {
        if (data[leftChildIndex] > data[rightChildIndex])
        {
            std::swap(data[currentElementIndex], data[leftChildIndex]);
            heapify(leftChildIndex)
        }
        else
        {
            std::swap(data[currentElementIndex], data[rightChildIndex]);
            heapify(rightChildIndex);
        }
    }
    else if (shouldGoLeft)
    {
        std::swap(data[currentElementIndex], data[leftChildIndex]);
        heapify(leftChildIndex);
    }
    else if (shouldGoRight)
    {
        std::swap(data[currentElementIndex], data[rightChildIndex]);
        heapify(rightChildIndex);
    }
}

template <typename T>
void PriorityQueue<T>::insert(const T& el)
{
    data.push_back(el);
    int ind = data.size() - 1;
    int parentIndex = parent(ind);

    while (ind > 0 && data[ind] > data[parentIndex])
    {
        std::swap(data[ind], data[parentIndex]);
        ind = parentIndex;
        parentIndex = parent(ind);
    }
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const std::vector<T>& data)
{
    this->data = data;

    for (int i = data.size() / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

template <typename T>
size_t PriorityQueue<T>::size() const
{
    return data.size();
}
