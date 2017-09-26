
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,  q, c, d, k = 0;
  printf("Enter the number n for the nxn matrix\n");
  //scanf("%d", &n);
  n = atoi(argv[1]);
  printf("Enter the elements of first matrix\n");
  float first[n][n], second[n][n], multiply[n][n];
  float sum = 0.0;
  for (c = 0; c < n; c++)
    for (d = 0; d < n; d++)
      first[c][d] = 1.0*(rand() % 10)+0.1;

   for (c = 0; c < n; c++)
     for (d = 0; d < n; d++)
       second[c][d]= 1.0*(rand() % 10)+0.1;

  struct timespec startW, endW;
  clock_gettime(CLOCK_REALTIME, &startW);
  double start = (double)clock() /(double) CLOCKS_PER_SEC;
  for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++) {
        for (k = 0; k < n; k++) {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }
  double end = (double)clock() / (double) CLOCKS_PER_SEC;
  clock_gettime(CLOCK_REALTIME, &endW);
  double seconds = (double)((endW.tv_sec+endW.tv_nsec*1e-9) - (double)(startW.tv_sec+startW.tv_nsec*1e-9));
  printf("wall time %fs\n", seconds);
  printf("cpu time %fs\n", end - start);

  printf("Product of entered matrices:%d-\n", n);
    for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++){
        //printf("%f ",multiply[c][d]);
        multiply[c][d]=0;
    }}
   //printf("\n");
  return 0;
}
