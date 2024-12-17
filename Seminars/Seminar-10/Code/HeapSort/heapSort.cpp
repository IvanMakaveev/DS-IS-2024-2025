#include <vector>

void heapify(size_t currentElementIndex, size_t size, std::vector<int>& data)
{
    int leftChildIndex = 2*currentElementIndex + 1;
    int rightChildIndex = 2*currentElementIndex + 2;

    bool shouldGoLeft = leftChildIndex < size && data[leftChildIndex] > data[currentElementIndex];
    bool shouldGoRight = rightChildIndex < size && data[rightChildIndex] > data[currentElementIndex];

    if (shouldGoLeft && shouldGoRight)
    {
        if (data[leftChildIndex] > data[rightChildIndex])
        {
            std::swap(data[currentElementIndex], data[leftChildIndex]);
            heapify(leftChildIndex, size, data);
        }
        else
        {
            std::swap(data[currentElementIndex], data[rightChildIndex]);
            heapify(rightChildIndex, size, data);
        }
    }
    else if (shouldGoLeft)
    {
        std::swap(data[currentElementIndex], data[leftChildIndex]);
        heapify(leftChildIndex, size, data);
    }
    else if (shouldGoRight)
    {
        std::swap(data[currentElementIndex], data[rightChildIndex]);
        heapify(rightChildIndex, size, data);
    }
}

void heapSort(std::vector<int>& data)
{
    for (int i = data.size() / 2 - 1; i >= 0; i--)
    {
        heapify(i, data.size(), data);
    }

    for (int i = data.size() - 1; i >= 0; i--)
    {
        std::swap(data[0], data[i]);
        heapify(0, i, data);
    }
}