#include <iostream>

using namespace std;

/*---Функция факториала---*/
int fact(int N)
{
    if (N<0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N*fact(N-1);
}

/*---Изменения для второго комита---*/
//jfjircwnbcjer

int main() {
    int N;
    cout<<"Введите число для вычисления факториала: ";
    cin>>N;
    cout << "Факториал для числа " << N << " = " << fact(N) << endl;
    return 0;
}
