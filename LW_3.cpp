#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Декларації функцій для кожного завдання
void task_if14();
void task_if27();
void task_geom8(); // Варіант 8 (жовта частина)

int main() {
    int menu;
    do {
        cout << "\n=========================================\n";
        cout << "               MAIN MENU                 \n";
        cout << "=========================================\n";
        cout << "1. Task If14 (Min and max of three numbers)\n";
        cout << "2. Task If27 (Piecewise function value)\n";
        cout << "3. Task Variant 8 (Geometric area)\n";
        cout << "0. Exit program\n";
        cout << "-----------------------------------------\n";
        cout << "Enter task number (0-3): ";
        cin >> menu;

        // Перемикання між завданнями за допомогою switch
        switch (menu) {
            case 1:
                task_if14();
                break;
            case 2:
                task_if27();
                break;
            case 3:
                task_geom8();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Error! Invalid task number. Please try again.\n";
        }
        
        if (menu != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    } while (menu != 0);

    return 0;
}

// ==========================================
// Реалізація завдання If14
// Дано три числа. Вивести спочатку найменше, а потім найбільше з даних чисел.
// ==========================================
void task_if14() {
    cout << "\n--------- Task If14 ---------" << endl;
    double a, b, c;
    cout << "Enter three numbers (a, b, c): ";
    cin >> a >> b >> c;

    // Використовуємо функціонал бібліотеки <algorithm> для пошуку мін та макс
    double min_val = min({a, b, c});
    double max_val = max({a, b, c});

    cout << "Minimum number: " << min_val << endl;
    cout << "Maximum number: " << max_val << endl;
}

// ==========================================
// Реалізація завдання If27
// Знаходження значення функції f(x) залежно від інтервалів
// ==========================================
void task_if27() {
    cout << "\n--------- Task If27 ---------" << endl;
    double x;
    cout << "Enter real number x: ";
    cin >> x;

    int f;
    if (x < 0) {
        f = 0; // якщо x менше за 0
    } else {
        int int_part = static_cast<int>(x); // отримання цілої частини числа
        // Якщо ціла частина парна -> 1, якщо непарна -> -1
        if (int_part % 2 == 0) {
            f = 1;  // для інтервалів [0,1), [2,3) тощо
        } else {
            f = -1; // для інтервалів [1,2), [3,4) тощо
        }
    }

    cout << "Function value f(x) = " << f << endl;
}

// ==========================================
// Реалізація геометричної задачі (Варіант 8)
// Визначення потрапляння точки в жовту область 8 варіанта
// ==========================================
void task_geom8() {
    cout << "\n--- Task: Variant 8 (Geometric Area) ---" << endl;
    double a, b;
    cout << "Enter rectangle parameters a and b: ";
    cin >> a >> b;
    
    if (cin.fail() || a <= 0 || b <= 0) {
        cerr << "Invalid data for figure dimensions!" << endl;
        return;
    }

    double x, y;
    cout << "Enter point coordinates (x, y): ";
    cin >> x >> y;

    if (cin.fail()) {
        cerr << "Non-numeric data for coordinates!" << endl;
        return;
    }

    // Обчислення допоміжних параметрів згідно з шаблоном лабораторної
    double R2 = a * a / 4.0;
    double xc = b / 2.0, yc = a / 2.0;
    double circle = pow(x - xc, 2) + pow(y - yc, 2);

    // Умова потрапляння в область 8 варіанта (жовта частина згідно креслення)
    bool inVariant8 = (x >= 0 && y >= 0 && (circle <= R2));

    if (inVariant8) {
        cout << "Point (" << x << ", " << y << ") belongs to Variant 8 area (yellow part)." << endl;
    } else {
        cout << "Point (" << x << ", " << y << ") does NOT belong to Variant 8 area." << endl;
    }
}