#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val, Node* next = nullptr) : data(val), next(next) {}
};

// find middle node
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// has cycle
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// reverse linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        Node* nextNode = current->next; // save next node
        current->next = prev; // reverse the link
        prev = current; // move prev to current
        current = nextNode; // move current to next node
    }

    return prev;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    Node* head1 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    head1->next->next->next->next->next = head1->next->next;

    Node* middle = findMiddle(head);
    std::cout << "Middle node " << middle->data << std::endl;

    std::cout << "Has cycle: " << std::boolalpha << hasCycle(head1) << std::endl;

    Node* reversedHead = reverseList(head);
    std::cout << "Reversed list: ";
    printList(reversedHead);

    freeList(head);

    return 0;
}