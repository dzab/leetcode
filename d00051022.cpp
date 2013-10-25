#include <vector>
#include <algorithm>
using std::vector;

vector<int> getRow(int rowIndex) {
    vector<int> v;
    v.push_back(1);
    if (rowIndex <= 0) return v;
    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = i-1; j > 0; --j) {
            v[j] = v[j] + v[j-1];
        }
        v.push_back(1);
        std::for_each(v.begin(), v.end(), [](int a) {printf("%d ",a);}); printf("\n");
    }
    return v;
}

int main()
{
    int n = 3;
    vector<int> v = getRow(n);
    std::for_each(v.begin(), v.end(), [](int a) {printf("%d ",a);});
    return 0;
}
