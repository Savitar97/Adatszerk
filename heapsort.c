#include <stdio.h>
#include <stdlib.h>

struct MaxGyoker
{
    int size;
    int* array;
};


void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }


void maxGyokere(struct MaxGyoker* maxGyoker, int idx)
{
    int largest = idx;  
    int left = (idx << 1) + 1; 
    int right = (idx + 1) << 1; 

    
    if (left < maxGyoker->size &&
        maxGyoker->array[left] > maxGyoker->array[largest])
        largest = left;


    if (right < maxGyoker->size &&
        maxGyoker->array[right] > maxGyoker->array[largest])
        largest = right;

 
    if (largest != idx)
    {
        swap(&maxGyoker->array[largest], &maxGyoker->array[idx]);
        maxGyokere(maxGyoker, largest);
    }
}


struct MaxGyoker* kupackeszit(int *array, int size)
{
    int i;
    struct MaxGyoker* maxGyoker =
              (struct MaxGyoker*) malloc(sizeof(struct MaxGyoker));
    maxGyoker->size = size;  
    maxGyoker->array = array; 

    
    for (i = (maxGyoker->size - 2) / 2; i >= 0; --i)
        maxGyokere(maxGyoker, i);
    return maxGyoker;
}

void kupacrendez(int* array, int size)
{
 
    struct MaxGyoker* maxGyoker = kupackeszit(array, size);

    while (maxGyoker->size > 1)
    {

        swap(&maxGyoker->array[0], &maxGyoker->array[maxGyoker->size - 1]);
        --maxGyoker->size; 

        maxGyokere(maxGyoker, 0);
    }
}

// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {37,27,39,93,46,78,50,89,84,95,48,94,5,43,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    kupacrendez(arr, size);

    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}