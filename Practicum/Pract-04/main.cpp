#include <iostream>
#include <vector>

struct Node
{
    int val = 0;
    Node* next = nullptr;
};

bool areEqual(Node* first, Node* second)
{
    while (first && second)
    {
        if (first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return !first && !second;
}

Node* makeToList(const std::vector<int>& arr)
{
    Node dummy;
    Node* iter = &dummy;
    for (int i = 0; i < arr.size(); i++)
    {
        iter->next = new Node{arr[i]};
        iter = iter->next;
    }

    return dummy.next;
}

Node* addElementAt(Node* node, int val, int ind)
{
    if (ind < 0) return node;

    Node* prev = node;
    Node* iter = node;

    while (iter && ind)
    {
        prev = iter; 
        iter = iter->next;
        ind--;
    }

    if (ind > 0) return node;

    if (prev == iter)
        return new Node{val, node};

    prev->next = new Node{val, iter};
    return node;

}

Node* removeElementAt(Node* node, int ind)
{
    if (ind < 0) return node;

    Node* prev = node;
    Node* iter = node;

    while (iter && ind)
    {
        prev = iter; 
        iter = iter->next;
        ind--;
    }

    if (ind > 0) return node;

    if (prev == iter)
    {
        node = node->next;
        delete iter;
        return node;
    }

    prev->next = iter->next;
    delete iter;
    return node;
}





int main()
{
    
}