#include <stdio.h>

int main(void) {
  int i = 0;
  int *pi = &i;

  float f = 0.1f;
  float *pf = &f;

  void *pv1 = pi, *pv2 = pf;

  printf("%d %f\n", *pi, *pf);
  printf("%d %f\n",
         *((int *)pv1), *((float *)pv2));
  // printf("%d %f\n",
  //        *((int *)pv2), *((float *)pv1));
}
