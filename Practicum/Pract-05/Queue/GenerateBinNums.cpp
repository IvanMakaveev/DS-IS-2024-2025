#include <iostream>
#include <queue>
#include <string>

void generateBinaryNumbers(int n) {
    std::queue<std::string> q;

    q.push("1");

    for (int i = 1; i <= n; ++i) {
        std::string current = q.front();
        q.pop();
        
        std::cout << current << " ";

        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n = 5;
    std::cout << "Двоични числа от 1 до " << n << ": ";
    generateBinaryNumbers(n);

    return 0;
}