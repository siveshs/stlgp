#include <stdio.h>

int main(int argc, char *argv[]) {
  int a;
  unsigned int a1;
  long int b;
  unsigned long int b1;
  float c;
  double d;
  char e;
  short int f;
  unsigned short int f1;

  printf("The number of bytes taken up by an int is:\t\t %lu \n",sizeof(a));
  printf("The number of bytes taken up by an unsigned int is:\t %lu \n",sizeof(a1));
  printf("The number of bytes taken up by a long int is:\t\t %lu \n",sizeof(b));
  printf("The number of bytes taken up by an usnigned long int is: %lu \n",sizeof(b1));
  printf("The number of bytes taken up by a short int is:\t\t %lu \n",sizeof(f));
  printf("The number of bytes taken up by an usnigned short int is: %lu \n",sizeof(f1));
  printf("The number of bytes taken up by a float is:\t\t %lu \n",sizeof(c));
  printf("The number of bytes taken up by a double is:\t\t %lu \n",sizeof(d));
  printf("The number of bytes taken up by a char is:\t\t %lu \n",sizeof(e));
}
