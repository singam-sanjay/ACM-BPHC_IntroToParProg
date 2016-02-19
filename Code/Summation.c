#include<stdio.h>

int main()
{
	register float sum = 0;
	float *arr = malloc( sizeof(float)*1024*1024 );

	int iter;
	for( iter=0 ; iter<(1024*1024) ; ++iter )
	{
		sum += arr[iter];
	}
	
	return 0;
} 
