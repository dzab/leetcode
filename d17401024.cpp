#include <stack>
#include <algorithm>
using std::stack;
using std::pair;
using std::make_pair;
using std::min;

int trap(int A[], int n) {
    stack<pair<int, int> > s;
    int water = 0;
    for (int i = 0; i < n; ++i) {
        int height = 0;
        while (!s.empty()) {
            int bar = s.top().first;
            int pos = s.top().second;
            water += (min(bar, A[i]) - height) * (i - pos - 1);
            height = bar;
            if (A[i] < bar) break;
            else s.pop();
        }
        s.push(make_pair(A[i], i));
    }
    return water;
}

int main() {
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", trap(A, 12));
    return 0;
}
