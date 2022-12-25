#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string line;
    cout << "Введите текст с клавиатуры:" << "\n";
    getline(cin, line);

    string symbol = "  ";
    size_t pos;
    while ((pos = line.find(symbol)) != line.npos)
        line.replace(pos, symbol.length(), " ");

    string symbol2 = ",,";
    size_t pos2;
    while ((pos2 = line.find(symbol2)) != line.npos)
        line.replace(pos2, symbol2.length(), ",");

    string symbol3 = "..";
    size_t pos3;
    while ((pos3 = line.find(symbol3)) != line.npos)
        line.replace(pos3, symbol3.length(), ".");

    string symbol4 = "!!";
    size_t pos4;
    while ((pos4 = line.find(symbol4)) != line.npos)
        line.replace(pos4, symbol4.length(), "!");

    string symbol5 = "??";
    size_t pos5;
    while ((pos5 = line.find(symbol5)) != line.npos)
        line.replace(pos5, symbol5.length(), "?");

    string symbol6 = "--";
    size_t pos6;
    while ((pos6 = line.find(symbol6)) != line.npos)
        line.replace(pos6, symbol6.length(), "-");

    string symbol7 = "\"\"";
    size_t pos7;
    while ((pos7 = line.find(symbol7)) != line.npos)
        line.replace(pos7, symbol7.length(), "\"");

    transform(line.begin(), line.end(), line.begin(), tolower);

    for (int i = 0; i <= line.length(); i++)
    {
        if (i != line.length() - 2)
        {
            if ((line[i] == '.' || line[i] == '!' || line[i] == '?') && line[i + 1] == ' ')
            {
                line[i + 2] = toupper(line[i + 2]);
            }
        }


    }
    line[0] = toupper(line[0]);
    cout << endl;
    cout << "Изменённая строка:" << "\n";
    cout << line << "\n";
    cout << endl;
    string linesecond = (line + " ");
    int lengthWord = 0;
    cout << "Строка, с напечатанными в обратном порядке словами: " << "\n";
    for (int i = 0; i < linesecond.length(); i++)
    {
        if (int(linesecond[i]) < 0 || (47 < int(linesecond[i]) && int(linesecond[i]) < 58))
        {
            lengthWord += 1;
        }
        else
        {
            if (lengthWord > 0)
            {
                for (int j = i - 1; j > i - lengthWord - 1; j--)
                {
                    cout << linesecond[j];
                }
            }
            cout << linesecond[i];
            lengthWord = 0;
        }

    }

    cout << endl;
    cout << endl;
    cout << "Введите то, что вы хотите удалить из строки:" << "\n";
    string linethird = line, part;

    getline(cin, part);
    size_t position;
    while ((position = linethird.find(part)) != linethird.npos)
        linethird.replace(position, part.length(), "");
    cout << linethird << "\n";

    string text1, part2;
    cout << "Введите подстроку, которую хотите найти: ";

    getline(cin, text1);
    cout << "Позиции текста, которые содержат введённую Вами подстроку (считая, что позиция первой буквы – 0): " << "\n";
    
    if (text1.length() == 1) {
        for (int i = 0; i <= line.length(); i++) {
            if ( line[i] == text1[0]) {
                cout << i << " ";
            }
        }
    }
    if (text1.length() >= 2) {
        for (int i = 0; i <= line.length(); i++)
        {
            if (line[i] == text1[0])
            {

                for (int j = i; j < (i + text1.length()); j++)
                {

                    for (int k = j; k < (j + text1.length()); k++) {
                        part2 += line[k - 1];

                        if (k == (j + text1.length()))
                            part2 += "\0";
                    }

                    if (part2 == text1) {
                        cout << i << " - " << (j + text1.length() - 2) << "\t";
                        part2.clear();
                    }
                    if (part2 != text1) {
                        part2.clear();
                    }
                }
            }
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
