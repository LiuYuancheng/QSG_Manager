#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,  q, c, d, k, sum = 0;
  n = atoi(argv[1]);
  printf("init 3 int matrix with size <%d>", n);
  int first[n][n], second[n][n], multiply[n][n];
  // init the matrix 1
  for (c = 0; c < n; c++)
    for (d = 0; d < n; d++)
      first[c][d] = rand() % 10;
  // init the matrix 2
   for (c = 0; c < n; c++)
     for (d = 0; d < n; d++)
       second[c][d]= rand() % 10;
  // init the time 
  struct timespec startW, endW;
  clock_gettime(CLOCK_REALTIME, &startW);
  double start = (double)clock() /(double) CLOCKS_PER_SEC;
  // multiply 2 matrix
  for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++) {
        for (k = 0; k < n; k++) {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }
  // calculate and display the time.
  double end = (double)clock() / (double) CLOCKS_PER_SEC;
  clock_gettime(CLOCK_REALTIME, &endW);
  double seconds = (double)((endW.tv_sec+endW.tv_nsec*1e-9) - (double)(startW.tv_sec+startW.tv_nsec*1e-9));
  printf("wall time %fs\n", seconds);
  printf("cpu time %fs\n", end - start);
  // clear the result matrix. 
  printf("Product of entered matrices:%d-\n", n);
    for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++)
        multiply[c][d]=0;
    }
  return 0;
}
