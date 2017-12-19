
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Введите, пожалуйста, строку:";
    string text;
    getline(std::cin, text);
    // string text = "Это должно входить, это не, должно, НЕТ, ДА, ДА, НЕТ, НЕТ, НЕТ , -., последовательность из 5 букв А: ААААА''', и это не должно, YXYXYЙ, а это должно остаться09";

    std::cout << "Строка на входе: " << text << std::endl;

    // Задача про удаление XY из текста
    string xyRes = "";
    bool foundX = false;

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

        // Задача про удаление XY
        // Если текущий символ Х
        if (currentChar == "X")
        {
            // Если перед ним не было символа Х, ставим признак того, что это первый X в true
            if (!foundX)
            {
                foundX = true;
            }
            // иначе (перед этим уже был Х)
            else
            {
                // добавляем к результирующей строке предыдущий Х и текущая Х становится как бы первой в группе
                xyRes += "X";
            }
        }
        // Если же текущая буква не Х, а Y,
        else if (currentChar == "Y")
        {
            // Если до нее не было Х, то это не группа XY
            if (!foundX)
            {
                // добавляем эту букву к результу
                xyRes += currentChar;
            }
            foundX = false;
            // Если жэ это группа XY, то ничего не делаем, т.е. не добавляем ничего к резульрирующей строке, тем самым как бы убирем эту комбинацию из оригинальной строки
        }
        // Если это не X и не Y, просто добавляем ее к резульрирующей строке
        else
        {
            if (foundX)
            {
                xyRes += "X";
                foundX = false;
            }
            xyRes += currentChar;
        }

        j += cplen;
    }
    std::cout << "Задача 11: "
              << "Результат: " << xyRes << std::endl;

    return 0;
}