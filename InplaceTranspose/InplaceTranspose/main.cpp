#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>

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

void TransformMtrxFirstAlg(float *mtrx, const int n, const int m){
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

void TransformMtrxSecondAlg(float *mtrx, const int n, const int m){
    for (int i = 1; i < n ; i++){
        for (int j = 0; j < m ; j++){
            Insert(mtrx, i * m + j, j * (i + 1) + i);
        }
    }
}

void TransformMtrxThirdAlg(float *mtrx,unsigned int n,unsigned int m)
{
    while(m>1)
    {
        for(unsigned int i=0;i<n;i++)
        {
            unsigned int index=m-1+m*(n-1-i);
            unsigned int target=m*n-1-i;
            Insert(mtrx, index, target);
        }
        --m;
    }
}



int main() {
    size_t n = 5, m = 3;
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
    TransformMtrxThirdAlg(mas, m, n);
    cout << "[";
    for(int i = 0; i<n*m; i++){
        cout << mas[i] << " ";
    }
    cout << "]"<<endl;
    return 0;
}
