#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <ctime>
#include "Algorithms.h"

using namespace std;

//#define MY_DEF_USE_LIBTAP
#define TIME_MEAS
#ifdef MY_DEF_USE_LIBTAP
#define TAP_COMPILE
#include "/Users/ilkin_galoev/Downloads/tst_example (1)/tst_example/libtap/cpp_tap.h"
int main(int, char *[]) {
  using namespace std;
  size_t n1 = 2, m1 = 4, n2 = 5, m2 = 3, n3 = 1, m3 = 2, n4 = 1, m4 = 1, n5 = 8, m5 = 1;
  size_t size1 = n1 * m1, size2 = n2 * m2, size3 = n3 * m3, size4 = n4 * m4, size5 = n5 * m5;
  float *mas1 = new float[size1];
  for (int i = 0; i < size1; i++)
    mas1[i] = i + 1;
  float *mas2 = new float[size2];
  for (int i = 0; i < size2; i++)
    mas2[i] = i + 1;
  float *mas3 = new float[size3];
  for (int i = 0; i < size3; i++)
    mas3[i] = i + 1;
  float *mas4 = new float[size4];
  for (int i = 0; i < size4; i++)
    mas4[i] = i + 1;
  float *mas5 = new float[size5];
  for (int i = 0; i < size5; i++)
    mas5[i] = i + 1;
  float rightMas1 [] = {1, 5, 2, 6, 3, 7, 4, 8};
  float rightMas2 [] = {1, 4, 7, 10, 13, 2, 5, 8, 11, 14, 3, 6, 9, 12, 15};
  float rightMas3 [] = {1, 2};
  float rightMas4 [] = {1};
  float rightMas5 [] = {1, 2, 3, 4, 5, 6, 7, 8};
  float *falseMas1 = new float[size1];
  for (int i = 0; i < size1; i++) {
    falseMas1[i] = 0;
  }
  float *falseMas2 = new float[size2];
  for (int i = 0; i < size2; i++) {
    falseMas2[i] = 0;
  }
  float falseMas3 [] = {0, 0};
  float falseMas4 [] = {0};
  float *falseMas5 = new float[size5];
  for (int i = 0; i < size5; i++) {
    falseMas5[i] = 0;
  }
  
  plan_tests(66);
  
  TransformMtrxFirstAlg(mas1, n1, m1);
  TransformMtrxFirstAlg(mas2, n2, m2);
  TransformMtrxFirstAlg(mas3, n3, m3);
  TransformMtrxFirstAlg(mas4, n4, m4);
  TransformMtrxFirstAlg(mas5, n5, m5);
  ok1(CheckTranspose(mas1, rightMas1, size1) == true);
  ok1(CheckTranspose(mas1, falseMas1, size1) == false);
  ok1(CheckTranspose(mas2, rightMas2, size2) == true);
  ok1(CheckTranspose(mas2, falseMas2, size2) == false);
  ok1(CheckTranspose(mas3, rightMas3, size3) == true);
  ok1(CheckTranspose(mas3, falseMas3, size3) == false);
  ok1(CheckTranspose(mas4, rightMas4, size4) == true);
  ok1(CheckTranspose(mas4, falseMas4, size4) == false);
  ok1(CheckTranspose(mas5, rightMas5, size5) == true);
  ok1(CheckTranspose(mas5, falseMas5, size5) == false);
  ok1(TransformMtrxFirstAlg(mas1, -5, -10) == false);
  ok1(TransformMtrxFirstAlg(mas1, 0, 0) == false);
  ok1(TransformMtrxFirstAlg(mas1, 0, 1) == false);
  ok1(TransformMtrxFirstAlg(mas1, 1, 0) == false);
  
  for (int i = 0; i < size1; i++) {
    mas1[i] = i + 1;
  }
  for (int i = 0; i < size2; i++) {
    mas2[i] = i + 1;
  }
  for (int i = 0; i < size3; i++) {
    mas3[i] = i + 1;
  }
  mas4[0] = 1;
  for (int i = 0; i < size5; i++) {
    mas5[i] = i + 1;
  }
  TransformMtrxSecondAlg(mas1, n1, m1);
  TransformMtrxSecondAlg(mas2, n2, m2);
  TransformMtrxSecondAlg(mas3, n3, m3);
  TransformMtrxSecondAlg(mas4, n4, m4);
  TransformMtrxSecondAlg(mas5, n5, m5);
  ok1(CheckTranspose(mas1, rightMas1, size1) == true);
  ok1(CheckTranspose(mas1, falseMas1, size1) == false);
  ok1(CheckTranspose(mas2, rightMas2, size2) == true);
  ok1(CheckTranspose(mas2, falseMas2, size2) == false);
  ok1(CheckTranspose(mas3, rightMas3, size3) == true);
  ok1(CheckTranspose(mas3, falseMas3, size3) == false);
  ok1(CheckTranspose(mas4, rightMas4, size4) == true);
  ok1(CheckTranspose(mas4, falseMas4, size4) == false);
  ok1(CheckTranspose(mas5, rightMas5, size5) == true);
  ok1(CheckTranspose(mas5, falseMas5, size5) == false);
  ok1(TransformMtrxSecondAlg(mas1, -5, -10) == false);
  ok1(TransformMtrxSecondAlg(mas1, 0, 0) == false);
  ok1(TransformMtrxSecondAlg(mas1, 0, 1) == false);
  ok1(TransformMtrxSecondAlg(mas1, 1, 0) == false);
  
  
  for (int i = 0; i < size1; i++) {
    mas1[i] = i + 1;
  }
  for (int i = 0; i < size2; i++) {
    mas2[i] = i + 1;
  }
  for (int i = 0; i < size3; i++) {
    mas3[i] = i + 1;
  }
  mas4[0] = 1;
  for (int i = 0; i < size5; i++) {
    mas5[i] = i + 1;
  }
  TransformMtrxThirdAlg(mas1, n1, m1);
  TransformMtrxThirdAlg(mas2, n2, m2);
  TransformMtrxThirdAlg(mas3, n3, m3);
  TransformMtrxThirdAlg(mas4, n4, m4);
  TransformMtrxThirdAlg(mas5, n5, m5);
  ok1(CheckTranspose(mas1, rightMas1, size1) == true);
  ok1(CheckTranspose(mas1, falseMas1, size1) == false);
  ok1(CheckTranspose(mas2, rightMas2, size2) == true);
  ok1(CheckTranspose(mas2, falseMas2, size2) == false);
  ok1(CheckTranspose(mas3, rightMas3, size3) == true);
  ok1(CheckTranspose(mas3, falseMas3, size3) == false);
  ok1(CheckTranspose(mas4, rightMas4, size4) == true);
  ok1(CheckTranspose(mas4, falseMas4, size4) == false);
  ok1(CheckTranspose(mas5, rightMas5, size5) == true);
  ok1(CheckTranspose(mas5, falseMas5, size5) == false);
  ok1(TransformMtrxThirdAlg(mas1, -5, -10) == false);
  ok1(TransformMtrxThirdAlg(mas1, 0, 0) == false);
  ok1(TransformMtrxThirdAlg(mas1, 0, 1) == false);
  ok1(TransformMtrxThirdAlg(mas1, 1, 0) == false);
  
  for (int i = 0; i < size1; i++) {
    mas1[i] = i + 1;
  }
  for (int i = 0; i < size2; i++) {
    mas2[i] = i + 1;
  }
  for (int i = 0; i < size3; i++) {
    mas3[i] = i + 1;
  }
  mas4[0] = 1;
  for (int i = 0; i < size5; i++) {
    mas5[i] = i + 1;
  }
  TransformMtrxFourthAlg(mas1, n1, m1);
  TransformMtrxFourthAlg(mas2, n2, m2);
  TransformMtrxFourthAlg(mas3, n3, m3);
  TransformMtrxFourthAlg(mas4, n4, m4);
  TransformMtrxFourthAlg(mas5, n5, m5);
  ok1(CheckTranspose(mas1, rightMas1, size1) == true);
  ok1(CheckTranspose(mas1, falseMas1, size1) == false);
  ok1(CheckTranspose(mas2, rightMas2, size2) == true);
  ok1(CheckTranspose(mas2, falseMas2, size2) == false);
  ok1(CheckTranspose(mas3, rightMas3, size3) == true);
  ok1(CheckTranspose(mas3, falseMas3, size3) == false);
  ok1(CheckTranspose(mas4, rightMas4, size4) == true);
  ok1(CheckTranspose(mas4, falseMas4, size4) == false);
  ok1(CheckTranspose(mas5, rightMas5, size5) == true);
  ok1(CheckTranspose(mas5, falseMas5, size5) == false);
  ok1(TransformMtrxFourthAlg(mas1, -5, -10) == false);
  ok1(TransformMtrxFourthAlg(mas1, 0, 0) == false);
  ok1(TransformMtrxFourthAlg(mas1, 0, 1) == false);
  ok1(TransformMtrxFourthAlg(mas1, 1, 0) == false);
  
  ok1(CheckTranspose(mas1, rightMas1, size1) == true);
  ok1(CheckTranspose(mas1, falseMas1, size1) == false);
  ok1(CheckTranspose(mas1, rightMas1, 0) == false);
  ok1(Insert(mas1, -8, 0) == false);
  ok1(Insert(mas1, -8, -1) == false);
  ok1(Insert(mas1, 0, -1) == false);
  ok1(Insert(mas1, 0, 0) == false);
  ok1(Insert(mas1, 0, 1) == false);
  ok1(Insert(mas1, 1, 0) == false);
  ok1(Insert(mas1, 1, 1));
  
  return exit_status();
  
  return 0;
}
#elif defined(TIME_MEAS)
int main() {
  cout<<"TIME_MEAS"<<endl<<endl;
  size_t n = 500, m = 50;
  size_t size = n * m;
  float *mas = new float[size];
  for (int i = 0; i < size; i++)
    mas[i] = i + 1;
  cout<<"Filled"<<endl;
  double sum[] ={0, 0, 0, 0};
  int times = 10;
  for (int i = 0; i < times; i++) {
    unsigned int start_time =  clock();
    TransformMtrxFirstAlg(mas, n, m);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout<<"Frist: "<<search_time<<endl;
    sum[0] += search_time;
    
    start_time =  clock();
    TransformMtrxSecondAlg(mas, n, m);
    end_time = clock();
    search_time = end_time - start_time;
    cout<<"Second: "<<search_time<<endl;
    sum[1] += search_time;
    
    start_time =  clock();
    TransformMtrxThirdAlg(mas, n, m);
    end_time = clock();
    search_time = end_time - start_time;
    cout<<"Third: "<<search_time<<endl;
    sum[2] += search_time;
    
    start_time =  clock();
    TransformMtrxFourthAlg(mas, n, m);
    end_time = clock();
    search_time = end_time - start_time;
    cout<<"Fourth: "<<search_time<<endl
    <<"---------------------"<<endl;
    sum[3] += search_time;
  }
  for (int i = 0; i < 4; i++) {
    cout<<i+1<<" "<<sum[i]/times<<endl;
  }
}
#else
int main() {
  size_t n = 8, m = 1;
  size_t size = n * m;
  float *mas = new float[size];
  for (int i = 0; i < size; i++)
    mas[i] = i + 1;
  //Insert(mas, 5, 1);
  cout << "[";
  for(int i = 0; i < n * m; i++) {
    cout << mas[i] << " ";
  }
  cout << "]"<<endl;
  TransformMtrxFourthAlg(mas, n, m);
  cout << "[";
  for(int i = 0; i < n * m; i++) {
    cout << mas[i] << " ";
  }
  cout << "]"<<endl;
  return 0;
}
#endif
