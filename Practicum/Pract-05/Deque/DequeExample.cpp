#include <iostream>
#include <deque>

int main() {
    std::deque<int> d;

    d.push_back(1);  // добавяме в края
    d.push_front(2); // добавяме в началото
    d.push_back(3);  // добавяме в края
    d.push_front(4); // добавяме в началото

    std::cout << "Front element: " << d.front() << std::endl; // Извеждаме първия елемент в дека -> 4
    std::cout << "Back element: " << d.back() << std::endl;  // Извеждаме последния елемент в дека -> 3

    d.pop_front(); // премахваме първия елемент
    d.pop_back(); // премахваме последния елемент

    std::cout << "Deque elements after pop operations: ";
    for (int elem : d) {
        std::cout << elem << " "; // Извеждаме елементите в дека -> 2 1
    }
    std::cout << std::endl;

    // Пример за използване на дек като опашка
    d.push_back(5); // добавяме елемент в края, както при опашка
    int queueFront = d.front(); // получаваме елемента в началото, както при опашка -> 2
    d.pop_front(); // премахваме го от началото, както при опашка

    std::cout << "Queue front element: " << queueFront << std::endl;
    std::cout << "Deque elements after using it as a queue: ";
    for (int elem : d) {
        std::cout << elem << " "; // Извеждаме елементите в дека -> 1 5
    }
    std::cout << std::endl;

    return 0;
}
