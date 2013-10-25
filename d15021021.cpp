#include <vector>
#include <algorithm>
using std::vector;

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > vv(n, vector<int>(n, 0));
    if (0 == n) return vv;
    int diR[] = { 0, 1, 0, -1};
    int diC[] = { 1, 0, -1, 0};
    int di = 0;
    int ir = 0, irN;
    int ic = 0, icN;
    int cur = 1;
    for (;;) {
        vv[ir][ic] = cur++;
        if (cur > n*n) return vv;
        irN = ir +diR[di]; icN = ic + diC[di];
        if (irN>=0&&irN<n&&icN>=0&&icN<n && vv[irN][icN]==0) {
            ir = irN; ic = icN;
        } else {
            di = (di+1)%4;
            ir += diR[di];
            ic += diC[di];
        }
    }
}

vector<vector<int> > generateMatrix2(int n) {
    vector<vector<int> > vv(n, vector<int>(n, 0));
    if (0 == n) return vv;
    int c = 0, r = 0;
    for (int i = 0; i < n*n; ++i) {
        vv[r][c] = i+1;
        if (r+c < n-1 && r <= c+1) c++;  // go right 
        else if (r+c >= n-1 && r < c) r++;  // go down
        else if (r+c > n-1 && r >= c) c--;  // go left
        else if (r+c <= n-1 && r > c+1) r--;  // go up
        else printf("end r=%d c=%d\n", r,c);
    }
    return vv; 
}

vector<vector<int> > generateMatrix3(int n) {
    vector<vector<int> > vv(n, vector<int>(n, 0));
    if (0 == n) return vv;
    int begin = 0, end = n-1;
    int cur = 0;
    while (begin < end) {
        for (int j = begin; j < end; ++j) {
            vv[begin][j] = ++cur;
        }
        for (int i = begin; i < end; ++i) {
            vv[i][end] = ++cur;
        }
        for (int j = end; j > begin; --j) {
            vv[end][j] = ++cur;
        }
        for (int i = end; i > begin; --i) {
            vv[i][begin] = ++cur;
        }
        ++begin; --end;
    }
    if (begin==end) vv[begin][end] = ++cur;
    return vv;
}

int main()
{
    vector<vector<int> > vv = generateMatrix3(5);
    std::for_each(vv.begin(), vv.end(), [](vector<int> &v) {
            std::for_each(v.begin(), v.end(), [](int a) { printf("%3d ", a); });
            printf("\n");
            });
     
    return 0;
}
