#include<stdio.h>
#include "malloc.h"
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>



inline uint64_t rdtsc() {
    uint32_t lo, hi;
    __asm__ __volatile__ (
      "xorl %%eax, %%eax\n"
      "cpuid\n"
      "rdtsc\n"
      : "=a" (lo), "=d" (hi)
      :
      : "%ebx", "%ecx");
    return (uint64_t)hi << 32 | lo;
}



int main()
{


    signed long long x_malloc;
    signed long long y_malloc;
    x_malloc = rdtsc();
    int *s_malloc = (int*) malloc(100 * sizeof(int));
    char *q_malloc = (char*)malloc(250 * sizeof(char));
    int *r_malloc = (int*)malloc(1000*sizeof(int));

    free(s_malloc);
    free(q_malloc);
    free(r_malloc);
    y_malloc = rdtsc();
    printf("Actual malloc took: %lld\n",y_malloc-x_malloc);
}
