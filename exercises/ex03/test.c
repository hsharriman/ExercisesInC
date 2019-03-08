#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

uint8_t flip_nybbles(uint8_t n){
  while (n) {

    n >>= 1;
}
printf("\n");
  uint8_t out = 0;
  for (int i = 0; i < 8; i++){
    if (n & 1){
        out = out | (1 << (7-i));
        printf("1");
    } else{
        printf("0");
    }
    n >>=1;
  }
  while (out) {
    if (out & 1){
        printf("1");
    }else{
        printf("0");
      }
    out >>= 1;
}
  return out;
}
// PRACTICE QUIZ 4 PROBLEMS
union {
  float f;
  uint32_t i;
} b;

uint32_t get_exp(float x){
  b.f = x;
  uint32_t mask = 0xff;
  uint32_t expon = (b.i >> 23) & mask;
  return expon;
}

float div_by_pow_2(float x, int n){
  b.f = x;
  uint32_t expon = get_exp(x);
  printf("%d\n", expon);
  expon = expon - n;
  printf("%d\n", expon);
  int mask = (1 << 23) - 1;
  expon = (expon << 23);
  b.i = (b.i & mask) | expon;
  return b.f;
}

/* END OF PRACTICE QUIZ 4 PROBLEMS */
double * get_int_part(double* arr, int size){
  double *res = (double*)malloc(size);
  for (int i=0; i<size; i++){
    modf(arr[i], res+i);
    printf("i = %i, %f, address %p\n", i, *(res+i), res+i);
  }
  return res;
}

char * strfilter(char * str, char * let){
  int k = 0;
  char temp[100];
  int i = 0;
  while(str[i] != '\0'){
    int j = 0;
    while (let[j] != '\0'){
      if (let[j] != str[i]){
        temp[k] = str[i];
        k++;
      }
      j++;
    }
    i++;
  }
  temp[k+1] = '\0';
  char * res = (char * )malloc(k+1);
  strcpy(res, temp);
  return res;
}
// double * get_int_part2(double* arr, int size){
//   double res[size] = (double)malloc(size);
//   for (int i=0; i<size; i++){
//     modf(arr[i], res[i]);
//     printf("i = %i, %f, address %p\n", i, res[i], res+i);
//   }
//   return res[0];
// }

int main(){
  // double arr[7] = {1.2, 12.3, 4.5, 2.3, 2.3, 5.6, 4.3};
  // printf("%zu\n", sizeof(arr));
  // printf("\n");
  // double *res = get_int_part(arr, 7);
  // for (int i=0; i<7; i++){
  //   printf(" %f, address %p\n", *(res+i), (res+i));
  // }
  // float res = div_by_pow_2(16.23, 2.0);
  uint8_t out = flip_nybbles(0xab);
  printf("%d, %x, %d, %x\n", 0xab, 0xab, out, out);
  // for (int i=0; i<8; i++){
    // printf("%s\n", res+i);
  // }
  return 0;
}
