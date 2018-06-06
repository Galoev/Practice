#include <vector>
#include <math.h>
using namespace std;

int GetPrime(int iNumber) {
    if (iNumber == 1){
        return 2;
    }
    if (iNumber == 2){
        return 3;
    }
    if (iNumber <= 1){
        return -1;
    }
    const int N_MAX = 15000;
    if (iNumber > N_MAX){
        return -2;
    }
    unsigned int numberCurentPrime = 2;
    unsigned int currentPrime = 3;
    unsigned int possiblyPrime = 3;
    while (numberCurentPrime <= iNumber) {
        bool flag = false;
        double end = sqrt((double)possiblyPrime);
        for (int j = 2; j <= end; j++){
            if (possiblyPrime % j == 0){
                flag = true;
                break;
            }
        }
        if (!flag){
            currentPrime = possiblyPrime;
            numberCurentPrime++;
        }
        possiblyPrime += 2;
    }
    return currentPrime;
}
