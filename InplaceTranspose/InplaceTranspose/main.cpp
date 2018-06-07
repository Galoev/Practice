#include <iostream>

using namespace std;

void Insert(float *mas, const unsigned int from, const unsigned int to){
    float tmp = mas[from];
    if (from == to ) return;
    if (from > to)
        for (size_t i = from; i>to; i--)
            mas[i] = mas[i-1];
    else
        for (size_t i = from; i<to; i++)
            mas[i] = mas[i+1];
    mas[to]=tmp;
}

int main() {
    size_t n = 3, m = 5;
    size_t size = n*m;
    float *mas = new float[size];
    for (int i = 0; i<size; i++)
        mas[i] = i;
    Insert(mas, 5, 1);
    cout << "[";
    for(int i = 0; i<n*m; i++){
        cout << mas[i] << " ";
    }
    cout << "]"<<endl;
    return 0;
}
