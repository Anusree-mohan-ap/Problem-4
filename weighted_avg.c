/* Documentation 
Name          : Anusree Mohan
Date          : 28-11-24
Title         : To generate n random numbers and calculate the 5 point weighted moving average 
Sample input  : 10 20 30 40 50
Sample output : 30 40 50
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *weighted_avg(int *arr, int size, int *returnSize) {
	int weight[] = {1,2,3,2,1};
	int *result = malloc((size-5+1)*sizeof(int));
	if(result == NULL) return NULL;
	int end = size - 1;
	int start = 0;
	while( end >= 4 ) {
		int val = 0;
		for(int i = start,k = 0; i < start + 5; i++, k++) {
			val += arr[i]*weight[k];
		}
		result[start] = val/9;
		start++;
		end--;
	}
	*returnSize = start;
	return result;
}

void print_array(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int size,n;
	printf("Enter the size of array ( size > 5) : ");
	scanf("%d",&n);

	if(n < 5) {
		printf("INFO: minimum size of array is 5\n");
		return 0;
	}
	// declare array
	int arr[n];

	// To generate random values
	srand(time(NULL));
	int low, high;
	printf("Enter the range of values\n");
	printf("\tlower limit : ");
	scanf("%d",&low);
	printf("\tupper limit : ");
	scanf("%d",&high);
	// generate numbers
	for(int i = 0; i < n; i++) {
		arr[i] = low + rand() % (high - low + 1);
	}
	
	printf("The array is : ");
	print_array(arr,n);

	int *res = weighted_avg(arr,n,&size);
	printf("Weighted average : ");
	print_array(res,size);

    return 0;
}


