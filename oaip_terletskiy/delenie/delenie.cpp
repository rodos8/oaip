#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

float a, b, c, eps, a1, b1;
int k;
char ch;

double F(double x)
{
    double x1 = 2 * x * x * x;
    double x2 = 3 * x * x;
    double x3 = 12 * x;
    double res = x1 - x2 - x3;
    return res;
}

/*
Алгоритм функции uravnenie() вкратце
1.x = (a + b)/2
2.Если f(a)·f(x) < 0, то b = x, иначе если f(x)·f(b) < 0, то a = x.
3.Если |b - a| > eps, то идти к 1.
4.x = (a + b)/2.
*/

void uravnenie() {
    cout << "2x^3 - 3x^2 - 12x = 0" << endl;
    cout << "Введите левую границу: ";
    cin >> a;
    cout << "Введите правую границу: ";
    cin >> b;
    cout << "Введите точность (eps): ";
    cin >> eps;
    a1 = a; b1 = b;
    k = 0;
    system("cls");
    if (a1 == b1)
    {
        cout << "Левая часть не может быть равна правой " << endl;
        return;
    }
    else if (a1 > b1)
    {
        cout << "Левая часть не может быть больше правой "<<endl;
        return;
    }

    while (abs(b - a) > eps)
    {
        k++;
        c = (a + b) / 2;

        if (F(c) == 0)
        {
            cout << "Уравнение на интервале (" << a1 << "; " << b1 << ") имеет точный корень x=" << c;
            return;
        }
        if (F(a) * F(c) < 0) b = c;
        if (F(a) * F(c) > 0) a = c;
    }

    if (F(c) != 0)
    {
        cout << "Уравнение на интервале (" << a1 << "; " << b1 << ") имеет точный корень x=" << c << endl;
        cout << "Точность (eps) достиглась за " << k << " шага(ов)" << endl << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        cout << "Решение уравнения 2x^3 - 3x^2 - 12x = 0 с помощью метода деления пополам " << endl <<endl;
        cout << "Операции" << endl;
        cout << "1. Начать решать" << endl;
        cout << "0. Закончить" << endl;
        switch (_getch())
        {
        case '1':
            system("cls");
            uravnenie();
            break;

        case '0':
            return 0;
            break;

        default:
            system("cls");
            break;
        }
    }

        
}