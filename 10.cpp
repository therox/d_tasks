
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Введите, пожалуйста, строку:";
    string text;
    getline(std::cin, text);
    // string text = "Это должно входить, это не, должно, НЕТ, ДА, ДА, НЕТ, НЕТ, НЕТ , -., последовательность из 5 букв А: ААААА''', и это не должно, YXYXYЙ, а это должно остаться09";

    std::cout << "Строка на входе: " << text << std::endl;

    // Задача для рядомстоящих точки и тире
    bool dotWithDash = false;
    string dotWithDashBuf = "";

    for (size_t j = 0; j < text.length();)
    {
        int cplen = 1;
        if ((text[j] & 0xf8) == 0xf0)
            cplen = 4;
        else if ((text[j] & 0xf0) == 0xe0)
            cplen = 3;
        else if ((text[j] & 0xe0) == 0xc0)
            cplen = 2;
        if ((j + cplen) > text.length())
            cplen = 1;
        // Текущий символ text.substr(i, cplen)
        string currentChar = text.substr(j, cplen);

        // Проверка на наличие рядомстоящих точки и тире
        // Используем буфер, в который будем пихать точку или тире, чтобы было с чем сравнить по мере продвижения по строке
        // Если текущий символ - точка
        if (currentChar == ".")
        {
            // Если в буфере уже есть тире
            if (dotWithDashBuf == "-")
            {
                // ставим признак того, что мы нашли подходящую группу
                dotWithDash = true;
                // очищаем буфер
                dotWithDashBuf = "";
            }
            else
            {
                // Если в буфере точки нет, пихаем в буфер точку, вдруг следующий символ - тире?
                dotWithDashBuf = currentChar;
            }
        }
        // Если текущий символ - тире
        if (currentChar == "-")
        {
            // Если в буфере уже есть точка
            if (dotWithDashBuf == ".")
            {
                // ставим признак того, что мы нашли подходящую группу
                dotWithDash = true;
                // очищаем буфер
                dotWithDashBuf = "";
            }
            else
            {
                // Если в буфере точки нет, пихаем в буфер тире, вдруг следующий символ - точка?
                dotWithDashBuf = currentChar;
            }
        }

        j += cplen;
    }

    if (dotWithDash)
    {
        std::cout << "Задача 10: "
                  << "В строке обнаружены рядомстоящие символы с точкой-тире" << std::endl;
    }
    else
    {
        std::cout << "Задача 10: "
                  << "В строке не обнаружены рядомстоящие символы с точкой-тире" << std::endl;
    }

    return 0;
}