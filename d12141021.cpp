#include <vector>
#include <algorithm>
using std::vector;

int minPathSum(vector<vector<int> > &grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    vector<int> sum(grid[0].size(), 0);

    for (int i = 0; i < grid.size(); ++i) {
        sum[0] += grid[i][0];
        for (int j = 1; j < grid[i].size(); ++j) {
            if (i==0) {
                sum[j] = sum[j-1] + grid[i][j];
            } else {
                sum[j] = std::min(sum[j], sum[j-1]) + grid[i][j];
            }
        }
        //std::for_each(sum.begin(), sum.end(), [](int a) { printf("%d ", a); } ); printf("\n");
    }
    return sum.back();
}

int main()
{
   vector<vector<int> > vv = { {1,3,1}, {1,5,1}, {4,2,1}};
   printf("%d\n", minPathSum(vv));
   return 0;
}
