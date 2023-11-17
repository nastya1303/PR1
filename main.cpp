#include <iostream>
using namespace std;

int main(){
    setlocale(0, "");
    int choose = 0,idz = 0, idzChoose=-1;

    while (choose != -1) {

        cout << "\n\n\nВыберите, что вы хотите сделать, и введите номер задания, из меню ниже: \n" \
            "1.Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без.\n" \
            "2. Вывести на экран двоичное представление в памяти (все разряды) целого числа.\n" \
            "3.Вывести на экран двоичное представление в памяти (все разряды) типа float.\n\n\n";

        cout << "Задание: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3)
            cout << "Такого варианта ответа нет \n";

        else
            switch (choose) {

                case 0: {
                    cout << "Пока \n\n";
                    choose = -1;
                }
                    break;

                case 1: {
                    cout <<
                         "int: " << sizeof(int) << '\n' <<
                         "short int: " << sizeof(short int) << '\n' <<
                         "long int: " << sizeof(long int) << '\n' <<
                         "float: " << sizeof(float) << '\n' <<
                         "double: " << sizeof(double) << '\n' <<
                         "long double: " << sizeof(long double) << '\n' <<
                         "char: " << sizeof(char) << '\n' <<
                         "bool: " << sizeof(bool) << '\n';
                }
                    break;

                case 2: {
                    int num, order, numb, a;
                    unsigned int mask;

                    cout << "Введите целое число: ";
                    cin >> num;
                    cout << "\n";

                    order = sizeof(num) * 8 - 1;
                    mask = 1 << order;

                    for (int i = 0; i <= order; i++) {
                        cout << ((mask & num) ? 1 : 0);
                        mask >>= 1;

                        if (!i)
                            cout << " ";
                    }

                    cout << '\n';
                    cout << "Введите число, на которое вы хотите сдвинуть биты вправо: ";
                    cin >> a;
                    numb = num >> a;

                    cout << "\n";

                    order = sizeof(num) * 8 - 1;
                    mask = 1 << order;

                    for (int i = 0; i <= order; i++) {
                        cout << ((mask & numb) ? 1 : 0);
                        mask >>= 1;

                        if (!i)
                            cout << " ";
                    }
                }
                    break;

                case 3: {
                    float numF, numC;
                    int orderF, a;
                    unsigned int maskF;

                    cout << "Введите вещественное число: ";
                    cin >> numF;
                    cout << "\n";

                    orderF = sizeof(numF) * 8 - 1;
                    maskF = 1 << orderF;

                    union {
                        int intMemory;
                        float floatMemory;
                    };

                    floatMemory = numF;

                    for (int i = 0; i <= orderF; i++) {
                        cout << ((maskF & intMemory) ? 1 : 0);
                        maskF >>= 1;

                        if (!i or i == 8)
                            cout << " ";
                    }

                    cout << '\n';
                    int orderC;
                    unsigned int maskC;
                    cout << "Введите число, на которое вы хотите сдвинуть биты вправо: ";
                    cin >> a;
                    numC = (float) (*((unsigned int*)&numF) >> a);


                    orderC = sizeof(numC) * 8 - 1;
                    maskC = 1 << orderC;

                    union {
                        int intMemoryC;
                        float floatMemoryC;
                    };

                    floatMemoryC = numC;

                    for (int i = 0; i <= orderC; i++) {
                        cout << ((maskC & int(numC)) ? 1 : 0);
                        maskC >>= 1;

                        if (!i or i == 8)
                            cout << " ";
                    }
                    break;

                }
            }

        return 0;
    }
}
