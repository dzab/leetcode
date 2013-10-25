#include <vector>
#include <algorithm>
using std::vector;
//sort-colors

void sortColors(int A[], int n) {
    //回想算法书中的partition
    int begin = 0;
    int end = n-1;
    int cur = 0;
    while (cur <= end) {
        if (A[cur] == 2) {
            std::swap(A[cur], A[end--]);
        } else if (A[cur] == 0) {
            std::swap(A[begin++], A[cur++]); // because left hand elements are processed already
        } else {
            cur++;
        }
    }
}

vector<int> CountingSort(int A[], int n)
{ //稳定排序
    int cnt[3] = {0};
    for (int i = 0; i < n; ++i) {
        cnt[A[i]]++;
    }
    for (int i = 1; i < 3; ++i) {
        cnt[i] += cnt[i-1];
    }
    vector<int> B(n, 0);
    for (int i = n-1; i >=0; --i) {
        B[--cnt[A[i]]] = A[i]; 
    }
    std::for_each(B.begin(), B.end(), [](int a){printf("%d ", a); });
    printf("\n\n");
    return B;
}

void CountingSort2(int A[], int n)
{//非稳定排序,不使用另外数组
    int cnt[3] = {0};
    for (int i = 0; i < n; ++i) {
        cnt[A[i]]++;
    }
    int idx = n-1;
    int d = 2;
    while (d >= 0) {
       while (cnt[d]-->0) A[idx--] = d;
       d--;
    }
}

int main()
{
    int array[10] = { 1,2,1,0,1,2,0,1,0};
    sortColors(array, 10);
    //CountingSort2(array, 10);
    std::for_each(array, array+10, [](int a){printf("%d ", a); });
    return 0;
}
