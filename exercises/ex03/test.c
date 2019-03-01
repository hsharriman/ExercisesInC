#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

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
  char* str = "equation";
  char* let = "aeiou";
  char * res = strfilter(str, let);
  // double *res = get_int_part(arr, 7);
  for (int i=0; i<8; i++){
    printf("%s\n", res+i);
  }
  return 0;
}
