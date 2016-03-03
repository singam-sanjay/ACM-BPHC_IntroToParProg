#include<stdio.h>
#include<stdlib.h>

typedef float arr_t;

int main()
{
	/*register*/ arr_t sum = 0;//It's important to see the effect of multiple memory accesses to the same variable, which are absent when only have to access the CPU registers
	register int repeat;
	register size_t iter;
	const size_t N = 2*1024*1024;
	arr_t *arr = malloc( sizeof(float)*N );
	if( arr==NULL )//This is needed from now on to see if memory is allocated
	{
		perror("malloc() failed");
		return 1;
	}
	
	//This outer "repeat" loop compensates for issues with using large memory, by repeating the computations
	for( repeat = 0 ; repeat<1024 ; ++repeat )
	{
		for( iter=0 ; iter<N ; iter+=4 )
		{
			sum += (arr[iter]+arr[iter+1])+(arr[iter+2]+arr[iter+3]);
		}
	}

	free(arr);
	
	return 0;
} 
