# `std::make_heap` и `std::priority_queue`

### Операции, свързани с heap
- **Превръщане на heap**: `std::make_heap(begin_it, end_it)` - O(N)
- **Добавяне на елемент**:
  - Добавете елемент в края на контейнера.
  - Извикайте `std::push_heap(begin, end)` - O(logN)
- **Извличане на най-големия елемент**:
  - Извикайте `std::pop_heap(begin, end)` - O(logN)
  - Премахнете елемента в края.
- **Проверка дали е heap**: `std::is_heap(begin, end)` - O(N)

---

### Пример
```c++
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};



    // Making vector into a heap
    std::make_heap(v.begin(), v.end());
    std::cout << "Max element: " << v[0] << '\n'; // 9


    std::cout << "Max-Heap: ";
    
    for (int n : v)
        std::cout << n << ' ';  // 9 5 4 1 1 3

    std::cout << '\n';


    //Adding element to the heap
    v.push_back(6);                   // 9 5 4 1 1 3 6
    std::push_heap(v.begin(), v.end());

    std::cout << "Adding 6 to the heap: ";
    for (int n : v)
        std::cout << n << ' ';      // 9 5 6 1 1 3 4

    std::cout << '\n';


    std::pop_heap(v.begin(), v.end());  // 6 5 4 1 1 3 9
    v.pop_back();
    
    std::cout << "Removing the max element: ";

    for (int n : v)
        std::cout << n << ' ';   // 6 5 4 1 1 3

    std::cout << '\n';


    return 0;
}
```

---

### Пример за min-heap

```c++
#include <algorithm>
#include <vector>
#include <iostream>


int main() 
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9};

    // Making vector into a heap
    std::make_heap(v.begin(), v.end(), std::greater<int>);
    std::cout << "Min-Heap: ";
    
    for (int n : v)
        std::cout << n << ' ';  // 1 1 4 3 5 9
}
```


---

## Въведение в `std::priority_queue`

`std::priority_queue` е адаптер за контейнер, който осигурява интерфейс за достъп до елементи с приоритет. По подразбиране най-големият елемент се поставя най-отгоре (*max-heap*).

### Операции
- **Добавяне на елемент**: `pq.push(value)` - O(logN)
- **Премахване на най-високия приоритет**: `pq.pop()` - O(logN)
- **Достъп до най-високия приоритет**: `pq.top()` - O(1)
- **Проверка на размера**: `pq.size()` - O(1)
- **Проверка за празнота**: `pq.empty()` - O(1)

### Параметри на шаблона
```c++
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

### Пример

```c++
#include <queue>
#include <vector>
#include <iostream>

int main() {

    std::vector<int> v = {3, 1, 4, 1, 5, 9};

    std::priority_queue<int> pq;

    for (int x : v)
        pq.push(x);
    
    while (!pq.empty()) 
    {
        std::cout << pq.top() << ' ';
        pq.pop(); 
    }

    std::cout << '\n';

    std::priority_queue<int> pq2(v.begin(), v.end());

    while (!pq2.empty()) 
    {
        std::cout << pq2.top() << ' ';
        pq2.pop(); 
    }
}
```


---

### Пример с min-heap

```c++
#include <queue>
#include <vector>
#include <iostream>

int main() 
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq3(v.begin(), v.end());
    
    while (!pq3.empty()) 
    {
        std::cout << pq3.top() << ' ';
        pq3.pop(); 
    }
}
```
