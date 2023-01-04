#include <cstdlib>
#include "MyException.h"
#include "Array.h"

// ����� ������ ������ ����������� � ������� �
// ��������� ��� �������� ����������
void initialise_random_int(Array<int> & array) {
  for (size_t i = 0; i < array.Size(); ++i) {
    array[i] = rand() % 10 - 5;
  }
}

void initialise_random_double(Array<double> & array) {
  for (size_t i = 0; i < array.Size(); ++i) {
    array[i] = (double) rand() / (double) RAND_MAX;
  }
}

int main()
{          
  try{
    Array<int>  aaaa; 
    aaaa.Add(123); 

    Array<int>  a(10);
    initialise_random_int(a);
    Array<int>  b(20,20);
    initialise_random_int(b);
    Array<double> r(30,30);
    initialise_random_double(r);
    a[2] = b[9];
    a[2] = 100;
    
    a.Add(25);
    printf("\nB:\n");
    for (size_t i = 0; i < b.Size(); ++i) { printf("%d, ", b[i]); }
    b.Remove(13);
    printf("\nB:\n");
    for (size_t i = 0; i < b.Size(); ++i) { printf("%d, ", b[i]); }
    b.Insert(5, 300);
    printf("\nB:\n");
    for (size_t i = 0; i < b.Size(); ++i) { printf("%d, ", b[i]); }
    b.Insert(5, 400);
    printf("\nB:\n");
    for (size_t i = 0; i < b.Size(); ++i) { printf("%d, ", b[i]); }

    r[4] = 12345.6789;

  } catch (MyException *e) {
      printf("My exception: %s  code %d\n", e->Message(), e->Code());
      if (e->Code() == EC_MEMORY) printf("memory error\n");
      if (e->Code() == EC_RANGE)  printf("range error\n");
      delete e;
      return -1;  // ��� ����� ������ �������� ...
  } 
  return 0;
} 
