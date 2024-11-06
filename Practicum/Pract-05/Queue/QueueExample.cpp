#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Добавяме елементи в опашката
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << "Front element: " << q.front() << std::endl; // Извеждаме първия елемент в опашката -> 1

    q.pop(); // Премахваме първия елемент в опашката -> 1

    std::cout << "Front element after pop: " << q.front() << std::endl; // Извеждаме първия елемент в опашката след премахване -> 2

    std::cout << "Back element: " << q.back() << std::endl; // Извеждаме последния елемент в опашката -> 5

    std::cout << std::boolalpha << "Is queue empty: " << q.empty() << std::endl; // Проверяваме дали опашката е празна -> false

    std::cout << "Size of queue: " << q.size() << std::endl; // Извеждаме размера на опашката -> 4

    // Премахваме всички елементи от опашката
    while (!q.empty())
        q.pop();

    std::cout << std::boolalpha << "Is queue empty: " << q.empty() << std::endl; // Проверяваме дали опашката е празна -> true

    return 0;
}
