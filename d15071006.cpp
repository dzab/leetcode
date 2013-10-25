#include <vector>
#include <cstdio>

int searchInsert(int A[], int n, int target) 
{
    int low = 0;
    int high = n;
    int mid;
    while (low < high) {
        printf("%d,%d\n", low, high);
        mid = (low + high) / 2;
        if (A[mid]==target) {
            return mid;
        }
        else if (A[mid]<target) {
            low = mid+1;
        }
        else {  //A[mid]>target
            high = mid;
        }
    }
    return low;
}

int main()
{
   int array[4] = { 1,3,5,6 };
   int target;
   scanf("%d", &target);
   printf("resule=%d\n", searchInsert(array, 4, target));
   return 0;
}
