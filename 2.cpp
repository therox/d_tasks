// Удалить из заданной строки все символы, расположенные между первой и последней запятой

#include <iostream>
using namespace std;

int main()
{

    string text = "Это должно входить, это не, должно, НЕТ, ДА, ДА, НЕТ, НЕТ, НЕТ , -., последовательность из 5 букв А: ААААА''', и это не должно, YXYXYЙ, а это должно остаться09";

    std::cout << "Строка на входе: " << text << std::endl;

    // Следующая конструкция разбивает строку на массив по запятым
    bool firstComma = false;
    string buf; // Буфер
    string res; // Строка с результатом
    // Задание про убирание букв Е и Л
    string resEL; // Строка с результатом для задания 3
    // Задание про последовательность из 5 букв А
    int aCount;
    bool fiveA = false;
    // Задание с двоеточиями
    string resTillColon;
    bool colonFound = false;
    // Задача про порядковый номер запятой
    int commaCount = 0;
    // Задача про количество пробелов
    int spaceCount = 0;
    // Задача про количество цифр в строке
    int numbersCount = 0;
    int yesStringCount = 0;
    string yesBuffer = "";
    int noStringCount = 0;
    string noBuffer = "";
    // Задача для рядомстоящих точки и тире
    bool dotWithDash = false;
    string dotWithDashBuf = "";
    // Задача про удаление XY из текста
    string xyRes = "";
    bool foundX = false;
    // Задача про преобразование строки путем удвоения любого символа кроме "'"
    string doubleString = "";
    // Задача про замену буквы А на группу символов НЕ
    string replacedString = "";

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

        // Задача про замену А на НЕ
        // Если текущий символ - А
        if (currentChar == "А")
        {
            // то к результирующей строчке вместо неё добавляем НЕ
            replacedString += "НЕ";
        }
        else
        {
            // А иначе, приплюсовываем текущую букву к результирующей строке
            replacedString += currentChar;
        }
        //======================^^^^^^^^^^^^^^============================

        // Задача про удвоение символов кроме "'"
        // Если текущий символ - '
        if (currentChar == "'")
        {
            // то просто добавляем его к результирующей строке
            doubleString += currentChar;
        }
        else
        {
            // иначе, добавляем к результирующей строке 2 текущих символа
            doubleString += currentChar + currentChar;
        }
        //======================^^^^^^^^^^^^^^============================

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
            // Если жэ это группа XY, то ничего не делаем, т.е. не добавляем ничего к резульрирующей строке, тем самым как бы убирем эту комбинацию из оригинальной строки
        }
        // Если это не X и не Y, просто добавляем ее к резульрирующей строке
        else
        {
            xyRes += currentChar;
        }
        //======================^^^^^^^^^^^^^^============================

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
        //======================^^^^^^^^^^^^^^============================

        // Проверка на наличие буквы Е или Л
        // Если текущй символ не Е и не Л, то добавляем его к результирующей строке
        if ((currentChar != "Е") && (currentChar != "Л"))
            resEL += currentChar;
        //======================^^^^^^^^^^^^^^============================

        // Проверка на вхождение слова "ДА" или "НЕТ"
        // Если текущий символ - Д и буфер пустой
        if ((currentChar == "Д") && (yesBuffer == ""))
        {
            // добавляем текущий символ в буфер
            yesBuffer += currentChar;
        }
        // Если текущий символ А и буфер содержит "Д"
        if ((currentChar == "А") && (yesBuffer == "Д"))
        {
            // мы нашли слово ДА
            // обнуляем буфер
            yesBuffer = "";
            //  и увеличиваем счетчик найденных комбинаций слов ДА на 1
            yesStringCount++;
        }
        // Если текущий символ - Н и буфер пустой
        if ((currentChar == "Н") && (noBuffer == ""))
        {
            noBuffer += currentChar;
        }
        // Если текущий символ - Е и в буфере есть Н
        if ((currentChar == "Е") && (noBuffer == "Н"))
        {
            // добавляем Е в буфер (пока что похоже на слово НЕТ)
            noBuffer += currentChar;
        }
        // Если текущий символ Т и в буфере содержится "НЕ"
        if ((currentChar == "Т") && (noBuffer == "НЕ"))
        {
            // мы нашли слово НЕТ
            // обнуляем буфер
            noBuffer = "";
            // увеличиваем счетчик на 1
            noStringCount++;
        }
        //======================^^^^^^^^^^^^^^============================

        // Задача на подсчет пробелов
        // Если встречаем пробел
        if (currentChar == " ")
        {
            // увеличиваем счетчик пробелов на 1
            spaceCount++;
        }
        //======================^^^^^^^^^^^^^^============================
        // Задача на подсчет цифр
        // Если найденный символ - цифра
        if ((currentChar >= "0") && (currentChar <= "9"))
        {
            // увеличивает счетчик цифр
            numbersCount++;
        }
        //======================^^^^^^^^^^^^^^============================
        // Задача на текст до двоеточия
        // Если текущий символ - двоеточие
        if (currentChar == ":")
        {
            // устанавливаем признак того, что нашли двоеточие
            colonFound = true;
        }
        // если признак, что мы нашли двоеточие не стоит
        if (!colonFound)
        {
            //прибавляем к результирующей строчке текущий символ
            resTillColon += currentChar;
        }
        //======================^^^^^^^^^^^^^^============================

        // Задача на подсчет рядомстоящих букв А
        // Если текущий символ - буква А
        if (currentChar == "А")
        {
            // увеличиваем счетчик найденных букв А
            aCount++;
            // Если их 5 подряд,
            if (aCount == 5)
            {
                // выставляем признак того, что нашли 5 букв А подряд
                fiveA = true;
            }
        }
        else
        {
            // Обнуляем счетчик букв А
            aCount = 0;
        }
        //======================^^^^^^^^^^^^^^============================

        // Задача на вывод текста до первой запятой и после последней
        // Если нашли запятую
        if (currentChar == ",")
        {
            // увеличиваем количество найденных запятых
            commaCount++;
            // Если до первой запятой мы еще не добирались
            if (!firstComma)
            {
                // прибавляем содержимое буфера (который формируется ниже по коду) к резульрирующей строке
                res += buf;
                // обнуляем буфер
                buf = "";
                // выставляем признак того, что мы нашли первую запятую
                firstComma = true;
            }
            // если же это не первая запятая
            else
            {
                // просто обнуляем буфер, нас не интересует то, что было после первой запятой и перед последней
                buf = "";
            }
        }
        else
        {
            buf += currentChar;
        }

        //======================^^^^^^^^^^^^^^============================

        j += cplen;
    }
    // Для задачки 2 добавляем последний буфер (от последней запятой до конца строки) к результату
    res += buf;

    std::cout << "Задача 2: "
              << "Результат: " << res << std::endl;

    std::cout << "Задача 3: "
              << "Результат: " << resEL << std::endl;
    // Проверка на вхождение слова "ДА" или "НЕТ"
    if (fiveA)
    {
        std::cout << "Задача 4: "
                  << "В строке обнаружена последовательность из 5 букв \"А\"" << std::endl;
    }
    else
    {
        std::cout << "Задача 4: "
                  << "В строке не обнаружена последовательность из 5 букв \"А\"" << std::endl;
    }

    if (colonFound)
    {
        std::cout << "Задача 5: "
                  << "Текст до первого двоеточия: \"" << resTillColon << "\"" << std::endl;
    }
    else
    {
        std::cout << "Задача 5: "
                  << "в тексте не обнаружено двоеточий" << std::endl;
    }

    if (commaCount > 0)
    {
        std::cout << "Задача 6: "
                  << "Порядковый номер последней запятой в строке: " << commaCount << std::endl;
    }
    else
    {
        std::cout << "Задача 6: "
                  << "в тексте не обнаружено запятых" << std::endl;
    }

    std::cout << "Задача 7: "
              << "В строке обнаружено " << spaceCount << " пробелов." << std::endl;
    std::cout << "Задача 8: "
              << "В строке обнаружено " << numbersCount << " цифр от 0 до 9" << std::endl;
    std::cout << "Задача 9: "
              << "В строке обнаружено " << yesStringCount << " вхождений слова \"ДА\" и " << noStringCount << " вхождений слова \"НЕТ\"" << std::endl;

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
    std::cout << "Задача 11: "
              << "Результат: " << xyRes << std::endl;
    std::cout << "Задача 12: "
              << "Результат: " << doubleString << std::endl;
    std::cout << "Задача 13: "
              << "Результат: " << replacedString << std::endl;
    return 0;
}