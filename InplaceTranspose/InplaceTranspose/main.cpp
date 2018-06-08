#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>

using namespace std;

void Insert(float *pMas, const unsigned int aFrom, const unsigned int aTo){
    float tmp = pMas[aFrom];
    if (aFrom == aTo ) return;
    if (aFrom > aTo)
        for (int i = aFrom; i>aTo; i--)
            pMas[i] = pMas[i-1];
    else
        for (int i = aFrom; i<aTo; i++)
            pMas[i] = pMas[i+1];
    pMas[aTo]=tmp;
}

void TransformMtrxFirstAlg(float *pMtrx, const int nRow, const int nCol){
    int place = 1;
    int start = nCol;
    int end = nCol;
    
    for (int i = 0; i < nCol; i++){
        for (int j = start; j < (nRow * nCol -1); j += end){
            Insert(pMtrx, j, place);
            place++;
        }
        start += (nRow-1);
        place++;
        end--;
    }
}

void TransformMtrxSecondAlg(float *pMtrx, const int nRow, const int nCol){
    for (int i = 1; i < nRow ; i++){
        for (int j = 0; j < nCol ; j++){
            Insert(pMtrx, i * nCol + j, j * (i + 1) + i);
        }
    }
}

void TransformMtrxThirdAlg(float *pMtrx,unsigned int nRow,unsigned int nCol)
{
    while(nCol>1)
    {
        for(unsigned int i=0;i<nRow;i++) {
            unsigned int index=nCol-1+nCol*(nRow-1-i);
            unsigned int target=nCol*nRow-1-i;
            Insert(pMtrx, index, target);
        }
        --nCol;
    }
}

void TransformMtrxFourthdAlg(float *pMtrx, int nRow, int nCol)
{
    int size = nRow*nCol - 1;
    float t;
    int next;
    int cycleBegin;
    int i;
    vector<bool> b(nRow*nCol);
    
    for (size_t i = 0; i<nRow*nCol; i++)
        b[i] = false;
    b[0] = b[size] = 1;
    i = 1;
    while (i < size)
    {
        cycleBegin = i;
        t = pMtrx[i];
        do
        {
            next = (i*nRow)%size;
            swap(pMtrx[next], t);
            b[i] = 1;
            i = next;
        }
        while (i != cycleBegin);
        
        for (i = 1; i < size && b[i]; i++);
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
    TransformMtrxFourthdAlg(mas, m, n);
    cout << "[";
    for(int i = 0; i<n*m; i++){
        cout << mas[i] << " ";
    }
    cout << "]"<<endl;
    return 0;
}
