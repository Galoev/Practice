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

void TransformMtrxFirstAlg(float *mtrx, const int m, const int n){
    int place = 1;
    int start = m;
    int end = m;
    
    for (int i(0); i < m; i++){
        for (int j = start; j < (n * m -1); j += end){
            Insert(mtrx, j, place);
            place++;
        }
        start += (n-1);
        place++;
        end--;
    }
}

int main() {
    size_t n = 3, m = 5;
    size_t size = n*m;
    float *mas = new float[size];
    for (int i = 0; i<size; i++)
        mas[i] = i+1;
    //Insert(mas, 5, 1);
    cout << "[";
    for(int i = 0; i<n*m; i++){
        cout << mas[i] << " ";
    }
    cout << "]"<<endl;
    TransformMtrxFirstAlg(mas, m, n);
    cout << "[";
    for(int i = 0; i<n*m; i++){
        cout << mas[i] << " ";
    }
    cout << "]"<<endl;
    return 0;
}
