#include<stdio.h>
#include "malloc.h"
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

void generate_process()
{
	struct process_block *blocks;
	int i;
	for(i = 0; i < MAX_PROCESS-1; i++)
	{
		//Create each process from 0 to 49
		//within each creation 
			//generate random number from 10KB to 2MB
				//record the current time
				//MyMalloc(random_number)
				//record the current time 
					//Get difference in time
			
	}
}
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
	//printf("%d", sizeof(int));
  	/**********************************Testing My Malloc ********************************************/
	signed long long x;
    signed long long y;
    x = rdtsc();

    
    long double cpu_time_used;
    long double telapsed;
    
	int *p = (int*)MyMalloc(100*sizeof(int));
    char *q = (char*)MyMalloc(250*sizeof(char));
    int *r = (int*)MyMalloc(1000*sizeof(int));
    

   
    

    MyFree(p);
	MyFree(q);
	MyFree(r);
	y = rdtsc();
	printf("%lld\n",y);
    printf("My malloc took : %lld\n",y-x);
    /***********************************************************************************************/

    /**********************************Testing Malloc ********************************************
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
    ***********************************************************************************************/

}

