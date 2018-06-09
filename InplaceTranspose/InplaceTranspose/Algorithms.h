#ifndef Algorithms_h
#define Algorithms_h

bool Insert(float *pMas, const unsigned int aFrom, const unsigned int aTo);
bool TransformMtrxFirstAlg(float *pMtrx, const int nRow, const int nCol);
bool TransformMtrxSecondAlg(float *pMtrx, const int nRow, const int nCol);
bool TransformMtrxThirdAlg(float *pMtrx,unsigned int nRow,unsigned int nCol);
bool TransformMtrxFourthAlg(float *pMtrx, int nRow, int nCol);
bool CheckTranspose(float *pA, float *pB, const unsigned int nSize);

#endif /* Algorithms_h */
