#include <iostream>
#include <queue>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

bool isValidBSTRec(const Node* root, int min, int max)
{
    if (root == nullptr)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    return isValidBSTRec(root->left, min, root->data) 
        && isValidBSTRec(root->right, root->data, max);
}

bool isValidBST(const Node* root)
{
    return isValidBSTRec(root, INT_MIN, INT_MAX);
}

void free(Node* root)
{
    free(root->left);
    free(root->right);

    delete root;
}