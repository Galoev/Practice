#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>

using namespace std;

bool Insert(float *pMas, const int aFrom, const int aTo) {
  if (aFrom <= 0 || aTo <= 0){
    return false;
  }
  if (aFrom == aTo ) {
    return true;
  }
  float tmp = pMas[aFrom];
  if (aFrom > aTo) {
    for (int i = aFrom; i > aTo; i--) {
      pMas[i] = pMas[i - 1];
    }
  }
  else {
    for (int i = aFrom; i<aTo; i++) {
      pMas[i] = pMas[i + 1];
    }
  }
  pMas[aTo]=tmp;
  return true;
}

bool TransformMtrxFirstAlg(float *pMtrx, const int nRow, const int nCol) {
  if (nRow <= 0 || nCol <= 0){
    return false;
  }
  int place = 1;
  int start = nCol;
  int end = nCol;

  for (int i = 0; i < nCol; i++) {
    for (int j = start; j < (nRow * nCol -1); j += end) {
      Insert(pMtrx, j, place);
      place++;
    }
    start += (nRow - 1);
    place++;
    end--;
  }
  return true;
}

bool TransformMtrxSecondAlg(float *pMtrx, const int nRow, const int nCol) {
  if (nRow <= 0 || nCol <= 0) {
    return false;
  }
  for (int i = 1; i < nRow ; i++) {
    for (int j = 0; j < nCol ; j++) {
      Insert(pMtrx, i * nCol + j, j * (i + 1) + i);
    }
  }
  return true;
}

bool TransformMtrxThirdAlg(float *pMtrx, int nRow, int nCol) {
  if (nRow <= 0 || nCol <= 0) {
    return false;
  }
  while(nCol > 1)
  {
    for(unsigned int i = 0; i < nRow;i++) {
      unsigned int index = nCol - 1 + nCol * (nRow - 1 - i);
      unsigned int target=nCol * nRow - 1 - i;
      Insert(pMtrx, index, target);
    }
    --nCol;
  }
  return true;
}

bool TransformMtrxFourthAlg(float *pMtrx, const int nRow, const int nCol) {
  if (nRow <= 0 || nCol <= 0) {
    return false;
  }
  int size = nRow * nCol - 1;
  float t;
  int next;
  int cycleBegin;
  int i;
  vector<bool> b(nRow * nCol);

  for (size_t i = 0; i < nRow * nCol; i++) {
    b[i] = false;
  }
  b[0] = b[size] = 1;
  i = 1;
  while (i < size) {
    cycleBegin = i;
    t = pMtrx[i];
    do {
      next = (i * nRow) % size;
      swap(pMtrx[next], t);
      b[i] = 1;
      i = next;
    }
    while (i != cycleBegin);
    
    for (i = 1; i < size && b[i]; i++);
  }
  return true;
}

bool CheckTranspose(float *pA, float *pB, const unsigned int nSize) {
  if (nSize <= 0) {
    return false;
  }
  for (int i=0; i < nSize; i++) {
    if (pA[i] != pB[i]) {
      return false;
    }
  }
  return true;
}
