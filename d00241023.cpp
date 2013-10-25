#include <vector>
#include <stdint.h>
#include <cstdlib>
using std::vector;

int threeSumClosest(vector<int> &num, int target) {
    int n = num.size();
    if (n < 3) return -1;
    std::sort(num.begin(), num.end());
    int low, high; 
    int minDiff = INT_MAX;
    int sum;
    int bestSum = num[0]+num[1]+num[2];
    for (int i = 1; i <= n-2; ++i) {
        low = 0; high = n-1;
        do {
            sum = num[low]+num[i]+num[high];
            if (minDiff > std::abs(sum-target)) {
                minDiff = std::abs(sum-target);
                bestSum = sum;
            }
            if (sum > target) high--;
            else if (sum < target) low++;
            else return sum;
        } while (high > i && low < i);
    }    
    return bestSum;
}

int main()
{
    int A[] = { 0, 2, 1, -3 };
    vector<int> num(A, A+4);
    printf("%d\n", threeSumClosest(num, 1));
    return 0;
}
