#include <stdio.h>  
#include <math.h>
#include <stdlib.h>
void insertionSort(int arr[], int n)

{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void swap(int *xp, int *yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}

void bubblesort(int arr[],int n){
    int i, j;
for (i = 0; i < n-1; i++)
for (j = 0; j < n-i-1; j++)
if (arr[j] > arr[j+1])
swap(&arr[j], &arr[j+1]);
    
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        
        swap(&arr[min_idx], &arr[i]);
    }
}
void merge(int arr[], int l, 
           int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    // Create temp arrays
    int L[n1], R[n2];
  
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    
    i = 0; 
  
   
    j = 0; 
  
    
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  

void mergeSort(int arr[], 
               int l, int r)
{
    if (l < r) 
    {
        
        int m = l + (r - l) / 2;
  
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
  
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(&arr[pivotIndex], &arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(&arr[i++], &arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    printf("Enter the number of elements to be sorted \n");
    int n;;
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the number one by one \n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Enter 1 for insertion sort,2 for bubble sort, 3 for selection sort,4 for merge sort, 5 for quick sort \n");
    int c;
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        insertionSort(arr,n);
        break;
    case 2:
        bubblesort(arr,n);
        break;
    case 3:
        selectionSort(arr,n);
        break;
    case 4:
        insertionSort(arr,n);
        break;
    case 5:
        quickSort(arr,0,n-1);
        break;
    
    default:
        printf("ERROR!!! WRONG CHOICE SELECTED ");
        break;
    }
    printArray(arr,n);
    return 0;
}