#include <cstdio>

int search(int A[], int n, int target) {
    if (0 == n) return -1;
    int low = 0;
    int high = n;
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        //printf("%d %d, mid=%d\n", low, high, mid);
        if (target == A[mid]) return mid;
        if (A[mid] >= A[low]) {
            if (target < A[mid] && target >= A[low]) high = mid;
            else low = mid + 1;
        } else {
            if (target > A[mid] && target <= A[high-1]) low = mid + 1;
            else high = mid;
        }
    }
    return -1;
}

int main()
{
    int A[] = { 4,5,6,7,0,1,2 };
    printf("%d\n", search(A, 7, 2));
    return 0;
}
