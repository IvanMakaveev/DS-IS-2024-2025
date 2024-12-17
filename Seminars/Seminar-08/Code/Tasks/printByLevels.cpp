#include <iostream>
#include <queue>

struct Node
{
    char data;
    std::vector<Node*> children;
};

void printByLevels(const Node* root)
{
    std::queue<const Node*> q;
    q.push(root);

    while (!q.empty())
    {
        unsigned levelSize = q.size();
        while (levelSize--)
        {
            auto curr = q.front();
            q.pop();

            std::cout << curr->data << " ";
            
            for (const Node* child : curr->children)
            {
                q.push(child);
            }
        }
        
        std::cout << std::endl;
    }
}

void free(Node* root)
{
    for (Node* child : root->children)
    {
        free(child);
    }

    delete root;
}

int main()
{
    Node* root = new Node{ 'a' };

    root->children.push_back(new Node{'b'});
    root->children.push_back(new Node{ 'c' });
    root->children.push_back(new Node{ 'd' });
    root->children.at(0)->children.push_back(new Node{ 'x' });
    root->children.at(0)->children.push_back(new Node{ 'y' });

    printByLevels(root);
    free(root);
}
