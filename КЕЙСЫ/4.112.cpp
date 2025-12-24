#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    long long n, month_index;

    cin >> n;
    const string month_names[12] = {
        "Январь", "Февраль", "Март", "Апрель",
        "Май", "Июнь", "Июль", "Август",
        "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };



    month_index = ((n % 12 + 12) % 12);
    cout << month_names[month_index] << "\n";
    return 0;
}