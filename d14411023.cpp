#include <vector>
#include <algorithm>
using std::vector;
//search-for-a-range

vector<int> searchRange(int A[], int n, int target) {
    int low = 0; 
    int high = n;
    int mid;
    while (low < high) {
        mid = low + (high-low)/2;
        if (A[mid] < target) low = mid + 1;
        else if (A[mid] > target) high = mid;
        else { // found
            vector<int> v1(A+low, A+mid);
            vector<int> v2(A+mid+1, A+high);
            printf("A[low]=%d A[mid+1]=%d , low=%d mid=%d high=%d\n", A[low], A[mid+1], low, mid, high);
            low = std::lower_bound(v1.begin(), v1.end(), target) - v1.begin() + low;
            high = std::upper_bound(v2.begin(), v2.end(), target) - v2.begin() + mid + 1;
            return vector<int>{low, high};
        }
    }
    return vector<int>(2, -1);
}

int main()
{
    int A[] = { 1,2,3,3,4,4,4,4,5,5};
    vector<int> v = searchRange(A, 10, 4);
    printf("%d %d\n", v[0], v[1]);
    return 0;
}
