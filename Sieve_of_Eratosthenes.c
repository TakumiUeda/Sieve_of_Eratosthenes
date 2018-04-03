#include <stdio.h>
#include <math.h>

#define NUM 10000

int main(void)
{
  unsigned i, j;
  unsigned sq_num = (long)sqrt((double)NUM);
  unsigned prime[NUM];

  for (i = 0; i < NUM; i++){
      prime[i] = 1;
  }
  prime[0] = 0;
  for (i = 1; i < sq_num; i++) {
    if (prime[i] == 1)
      for (j = (i+1); (i+1) * j <= NUM; j++)
        prime[(i+1) * j - 1] = 0;
  }
  j=0;
  for (i = 0; i < NUM; i++){
    if (prime[i] == 1){
      j++;
      printf("%5d", i + 1);
    }
  }
  printf("\r\n");
  printf("発見した素数の個数は%d個です\r\n",j);
  return (0);
}
