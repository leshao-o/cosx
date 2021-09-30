#include <iostream>
#include <cmath>                                     // подключение библиотеки которая считает косинус

#define PI 3.14159265

using namespace std;

int main(int argc, const char * argv[]) {
    
    double eps, x;
    
    cout << "угол (в радианах): ";
    cin >> x;                                        // ввод угла
    cout << "погрешность: ";
    cin >> eps;                                      // ввод погрешности
    cout << "\n";
        
    double dPI = PI * 2;                             // для вычиcлений угла которые > 2pi
    while (x > dPI)
        x = x - dPI;
    
    if (eps <= 0) {                                  // если вводимая погрешность меньше 0
        cout << "eps должна быть > 0" << endl << endl;
        return 0;
    }
    
    double cosx = cos(x);                            // точное значение косинуса
    int n = 0;                                       // счетчик циклов
    double sum = 1;                                  // сумма которую мы выведем с учетом погрешности (примерное значение косинуса)
    int znak = 1;                                    // знак
    double argx = 1;                                 // числитель
    double dnfact = 1;                               // знаменатель
    
    while (abs(cosx - sum) > eps) {                  // пока погрешность не станет допутимой
        n++;                                         // увеличние счетчика
        znak = -znak;                                // смена знака
        argx *= x * x;                               // увеличение степени икса
        dnfact *= (2 * n - 1) * (2 * n);             // увеличение знаменателя
        sum += znak * argx / dnfact;                 // увеличение суммы
    }
                                                     // вывод всех полученных значений
    cout << "1) погрешность: " << eps << endl;
    cout << "2) полученная погрешность: " << abs(cosx - sum) << endl;
    cout << "3) кол-во циклов: " << n << endl;
    cout << "4) полученное значение: " << sum << endl;
    cout << "5) точное значение: " << cosx << endl << endl;
    
    return 0;
}


