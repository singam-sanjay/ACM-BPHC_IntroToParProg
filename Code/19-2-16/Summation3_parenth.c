#include<stdio.h>
#include<stdlib.h>

typedef float arr_t;

int main()
{
	register arr_t sum = 0;
	register size_t iter;
	const size_t N = 1024*1024*1024;
	arr_t *arr = malloc( sizeof(float)*N );

	for( iter=0 ; iter<N ; iter+=4 )
	{
		sum += (arr[iter]+arr[iter+1])+(arr[iter+2]+arr[iter+3]);
	}

	free(arr);
	
	return 0;
} 
