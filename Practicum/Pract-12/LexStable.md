# LexStable формат за дати и часове

**LexStable** (Lexicographically Stable) е формат за дати и часове като `YYYY-MM-DD HH:MM:SS`, 
който осигурява лексикографска подредба, съответстваща на хронологичния ред.

## Формат `YYYY-MM-DD HH:MM:SS`
- `YYYY` - година (4 цифри)
- `MM` - месец (2 цифри)
- `DD` - ден (2 цифри)
- `HH` - час (24-часов формат, 2 цифри)
- `MM` - минути (2 цифри)
- `SS` - секунди (2 цифри)

## Характеристики 
1. **Лексикографскa стабилност**
   - Когато сравняваме два стринга в този формат, тяхното лексикографско (азбучно) подреждане съвпада с хронологичния ред на датите.
   - Поради структурата на формата (`година → месец → ден → час → минута → секунда`), най-значимите единици са разположени в началото.
2. **Уникалност** - всяка дата и час са представени еднозначно
3. **Универсалност** - може да се използва както за сравнение, така и за сортиране и хеширане

## Примери

### 1. Форматиране на дата и час
```c++
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>

std::string formatDateTime(const std::tm& time) {
    std::ostringstream oss;
    oss << std::put_time(&time, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);

    std::string formattedDateTime = formatDateTime(*local_time);

    std::cout << "Форматирано време (в LexStable формат): " << formattedDateTime << std::endl;

    return 0;
}
```

#### Получаване на текущото време
- `std::chrono::system_clock::now()` → взима текущата времева точка от системния часовник
- типът на `now` е `std::chrono::time_point`, който представлява времева точка (броят на секундите от 1 януари 1970 г.)
- `std::chrono::system_clock::to_time_t(now)` → преобразува времевата точка в `std::time_t`, който е стандартен тип за време (броят секунди от епохата)

#### Преобразуване в локално време
- `std::localtime` → преобразува `std::time_t` в `std::tm`
- `std::tm` е структура, която съдържа:
    -  ***година*** (`tm_year`) → годината минус 1900
      - **Пример:** 2025 → `tm_year = 125`
    - ***месец*** (`tm_mon`) → стойност от 0 (януари) до 11 (декември)
    - ***ден*** (`tm_mday`) → ден от месеца (1-31)
    - ***час*** (`tm_hour`) → час от денонощието (0-23)
    - ***минути*** (`tm_min`) → минути (0-59)
    - ***секунди*** (`tm_sec`) → секунди (0-59)

#### Форматиране на времето
- `std::ostringstream` → стрингов поток, който работи като буфер за текст
- `std::put_time` → форматира структура `std::tm` в посочения вид

### 2. Сравнение на дати и часове
```c++
#include <iostream>
#include <string>

int main() {
    std::string dateTime1 = "2025-01-06 14:30:45";
    std::string dateTime2 = "2025-01-07 10:15:20";

    if (dateTime1 < dateTime2) {
        std::cout << dateTime1 << " е преди " << dateTime2 << std::endl;
    } else {
        std::cout << dateTime1 << " е след или равно на " << dateTime2 << std::endl;
    }

    return 0;
}
```

### 3. Сортиране на дати и часове
```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> dates = {
        "2025-01-07 10:15:20",
        "2025-01-06 14:30:45",
        "2024-12-31 23:59:59"
    };

    std::sort(dates.begin(), dates.end());

    std::cout << "Сортирани дати:" << std::endl;
    for (const auto& date : dates) {
        std::cout << date << std::endl;
    }

    return 0;
}
```

### 4. Хеширане на дати и часове
```c++
#include <iostream>
#include <functional>
#include <string>

int main() {
    std::string dateTime = "2025-01-06 14:30:45";
    std::hash<std::string> hashFn;

    size_t hashValue = hashFn(dateTime);

    std::cout << "Хеш стойност за " << dateTime << ": " << hashValue << std::endl;

    return 0;
}
```

### 5. Използване в контейнери
```c++
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, std::string> events;
    events["2025-01-06 14:30:45"] = "Meeting with team";
    events["2025-01-07 10:15:20"] = "Doctor's appointment";

    for (const auto& [key, value] : events) {
        std::cout << key << ": " << value << std::endl;
    }

    return 0;
}
```

## Приложения

### 1. Регистриране на логове
В някои системи е важно да се запазва лог на действията, които са извършени, т.е всяко събитие да бъде
маркирано с точно време (timestamp).
<details>
<summary>Пример</summary>

```c++
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <string>

void logMessage(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);

    std::ostringstream oss;
    oss << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] ";
    oss << message;

    std::cout << oss.str() << std::endl;
}

int main() {
    logMessage("Стартиране на приложението.");
    logMessage("Грешка: Липсва файлът config.json.");
    logMessage("Приложението приключи успешно.");

    return 0;
}
```
</details>

### 2. Генериране на уникални имена за файлове
<details>
<summary>Пример</summary>

```c++
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <string>

std::string generateBackupFileName() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);

    std::ostringstream oss;
    oss << "backup_" << std::put_time(local_time, "%Y%m%d_%H%M%S") << ".zip";
    return oss.str();
}

int main() {
    std::string backupFile = generateBackupFileName();
    std::cout << "Генерирано име на файл за архив: " << backupFile << std::endl;

    return 0;
}
```
</details>

### 3. Генериране на времеви интервали
<details>
<summary>Пример</summary>

```c++
#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    auto start = std::chrono::system_clock::now();
    
    // Изчакване на 3 секунди
    std::this_thread::sleep_for(std::chrono::seconds(3));

    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "Операцията отне " << duration.count() << " секунди." << std::endl;

    return 0;
}
```
</details>

## Документация
- [std::system_clock](https://en.cppreference.com/w/cpp/chrono/system_clock)
- [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm)
- [std::localtime](https://en.cppreference.com/w/cpp/chrono/c/localtime)
- [std::put_time](https://en.cppreference.com/w/cpp/io/manip/put_time)