#pragma once
 
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <forward_list>
 
size_t getHash(const std::string& str)
{
    return str.size();
}
 
class Dictionary
{
    typedef std::pair<std::string, int> element;
    std::list<element> data;
    std::vector<std::forward_list<std::list<element>::iterator>> hashTable;
 
    double maxLoadFactor = 8;
 
    void resize()
    {
        size_t htSize = hashTable.size();
        hashTable.clear();
        hashTable.resize(htSize * 2);
 
        for (auto it = data.begin(); it != data.end(); ++it)
            hashTable[getHashCode(it->first)].push_front(it);
    
    }
 
    size_t getHashCode(const std::string key) const
    {
        return getHash(key) % hashTable.size();
    }
 
public:
    Dictionary()
    {
        hashTable.resize(2);
    }
 
    double loadFactor() const {
        return ((double) data.size()) / hashTable.size();
    }
 
    void add(const std::string& key, int value)
    {
        if (loadFactor() >= maxLoadFactor)
        {
            resize();
        }
 
        size_t hashCode = getHashCode(key);
        auto& bucket = hashTable[hashCode];
        auto iter = std::find_if(bucket.begin(), bucket.end(), [&key](const std::list<element>::iterator& currIter)
            {
                return currIter->first == key;
            });
 
        if (iter != bucket.end())
        {
            return;
        }
 
        data.push_back({key, value});
        bucket.push_front(--data.end());
    }
 
    int getValue(const std::string& key) const
    {
        size_t hashCode = getHashCode(key);
        auto& bucket = hashTable[hashCode];
        auto iter = std::find_if(bucket.begin(), bucket.end(), [&key](const std::list<element>::iterator& currIter)
            {
                return currIter->first == key;
            });
 
        if (iter == bucket.end())
        {
            throw std::out_of_range("Element not found");
        }
 
        return (*iter)->second;
    }
 
    void remove(const std::string& key)
    {
        size_t hashCode = getHashCode(key);
        auto& bucket = hashTable[hashCode];
        bucket.remove_if([this, &key](const std::list<element>::iterator& currIter)
            {
                if (key == currIter->first)
                {
                    data.erase(currIter);
                    return true;
                }
                return false;
            });
    }
 
    void print()
    {
        for (auto iter = data.begin(); iter != data.end(); ++iter)
        {
            std::cout << iter->first << ' ' << iter->second << std::endl;
        }
    }
};
