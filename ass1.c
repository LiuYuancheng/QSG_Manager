#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
 
int main()
{
  int n,  q, c, d, k, sum = 0; 
  printf("Enter the number n for the nxn matrix\n");
  scanf("%d", &n);
  printf("Enter the elements of first matrix\n");
	int first[n][n], second[n][n], multiply[n][n];
  // init the first matrix
	for (c = 0; c < n; c++)
    for (d = 0; d < n; d++)
      first[c][d] = rand() % 10; 
  // init the second matrix 
   for (c = 0; c < n; c++)
     for (d = 0; d < n; d++)
       second[c][d]= rand() % 10;  
  //Calculation [x]x[x]

	struct timespec startW, endW;  
	
	// wall clock time
	clock_gettime(CLOCK_REALTIME, &startW); 
	// cpu time 	
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
	// 
	clock_gettime(CLOCK_REALTIME, &endW);
	double seconds = (double)((endW.tv_sec+endW.tv_nsec*1e-9) - (double)(startW.tv_sec+startW.tv_nsec*1e-9));
	printf("wall time %fs\n", seconds);
	printf("cpu time %fs\n", end - start);


	printf("Product of entered matrices:-\n");
    for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++)
        //printf("%d\t", multiply[c][d]);
 				multiply[c][d]=0; 
      //printf("\n");
    }
  return 0;
}
