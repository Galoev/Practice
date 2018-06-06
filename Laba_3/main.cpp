#include "cryptography.cpp"
// Тесты
#define MY_DEF_USE_LIBTAP
// Подключение libtap для Visual Studio
// 1. Скопировать каталог libtap в папку с исходными файлами
// 2. Указать две нижеследующие строки, соблюдая порядок:
#define TAP_COMPILE // включает компиляцию libtap (указывать в одном и только одном исходном файле)
#include "libtap\cpp_tap.h" // подключает заголовочные файлы библиотеки (указывать в тех исходных файлах, где создаются тесты)


int main(int, char *[]) {
  using namespace std;

  plan_tests(6);
  ok1(GetPrime(0) == -1);
  ok1(GetPrime(15001) == -2);
  ok1(GetPrime(1) == 2);
  ok1(GetPrime(2) == 3);
  ok1(GetPrime(14999) == 163819);
  ok1(GetPrime(15000) == 163841);
  return exit_status();

  return 0;
}


