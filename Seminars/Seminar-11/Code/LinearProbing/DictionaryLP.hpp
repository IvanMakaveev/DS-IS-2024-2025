#pragma once
 
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
 
static size_t getHash(const std::string& str)
{
    return str.size();
}
 
class DictionaryLP
{
    struct Node
    {
        std::string key = "";
        int value = 0;
        bool isDeleted = false;
        bool isTaken = false;
 
        Node() = default;
        Node(std::string key, int value, bool isDel, bool isTaken) :
            key(key), value(value), isDeleted(isDel), isTaken(isTaken) { }
    };
 
    std::vector<Node> data;
    size_t jumpValue;
    size_t size = 0;
    double maxLoadFactor = 0.5;
 
    size_t getHashCode(const std::string key) const
    {
        return getHash(key) % data.size();
    }
 
    void resize()
    {
        std::vector<Node> dataDest(2 * data.size());
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (it->isTaken && !it->isDeleted)
            {
                size_t index = getHash(it->key) % dataDest.size();
                size_t startIndex = index;
                do
                {
                    if (!dataDest[index].isTaken)
                    {
                        // We use std::move here!!!
                        dataDest[index] = Node(std::move(it->key), std::move(it->value), true, false);
                        break;
                    }
 
                    index = (index + jumpValue) % dataDest.size();
                } while (startIndex != index);
            }
        }
 
        data = std::move(dataDest);
    }
 
    
public:
    DictionaryLP()
    {
        data.resize(100);
        jumpValue = 3; // GCD(100, 3) = 1
    }
 
    double loadFactor()
    {
        return (double)size / data.size();
    }
 
    void add(const std::string& key, int value)
    {
        if (loadFactor() > maxLoadFactor)
        {
            resize();
        }
 
        size_t index = getHashCode(key);
        size_t startIndex = index;
        do
        {
            if (!data[index].isTaken || data[index].isDeleted)
            {
                data[index] = Node(key, value, true, false);
                size++;
                return;
            }
            else if (data[index].key == key)
            {
                return;
            }
 
            index = (index + jumpValue) % data.size();
        } while (startIndex != index);
    }
 
    int getValue(const std::string& key)
    {
        size_t index = getHashCode(key);
        size_t startIndex = index;
        do
        {
            if (!data[index].isTaken)
            {
                break;
            }
            else if (!data[index].isDeleted && data[index].key == key)
            {
                return data[index].value;
            }
 
            index = (index + jumpValue) % data.size();
        } while (startIndex != index);
 
        throw std::out_of_range("Element not found");
    }
 
    void remove(const std::string& key)
    {
        size_t index = getHashCode(key);
        size_t startIndex = index;
        do
        {
            if (!data[index].isTaken)
            {
                return;
            }
            else if (!data[index].isDeleted && data[index].key == key)
            {
                data[index].isDeleted = true;
                data[index].key.clear();
                data[index].value = 0;
                size--;
                return;
            }
 
            index = (index + jumpValue) % data.size();
        } while (startIndex != index);
    }
};