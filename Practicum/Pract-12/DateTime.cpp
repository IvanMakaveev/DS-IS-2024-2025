#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>

std::string formatDateTime(const std::tm &time)
{
    std::ostringstream oss;
    oss << std::put_time(&time, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

int main()
{
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm *local_time = std::localtime(&now_time);

        std::string formattedDateTime = formatDateTime(*local_time);

        std::cout << "Форматирано време (в LexStable формат): " << formattedDateTime << std::endl;
    }
    {
        std::string dateTime1 = "2025-01-06 14:30:45";
        std::string dateTime2 = "2025-01-07 10:15:20";

        if (dateTime1 < dateTime2)
        {
            std::cout << dateTime1 << " е преди " << dateTime2 << std::endl;
        }
        else
        {
            std::cout << dateTime1 << " е след или равно на " << dateTime2 << std::endl;
        }
    }
    {
        std::vector<std::string> dates = {
            "2025-01-07 10:15:20",
            "2025-01-06 14:30:45",
            "2024-12-31 23:59:59"};

        std::sort(dates.begin(), dates.end());

        std::cout << "Сортирани дати:" << std::endl;
        for (const auto &date : dates)
        {
            std::cout << date << std::endl;
        }
    }
    {
        std::string dateTime = "2025-01-06 14:30:45";
        std::hash<std::string> hashFn;

        size_t hashValue = hashFn(dateTime);

        std::cout << "Хеш стойност за " << dateTime << ": " << hashValue << std::endl;
    }
    {
        std::unordered_map<std::string, std::string> events;
        events["2025-01-06 14:30:45"] = "Meeting with team";
        events["2025-01-07 10:15:20"] = "Doctor's appointment";

        for (const auto &[key, value] : events)
        {
            std::cout << key << ": " << value << std::endl;
        }
    }

    return 0;
}
