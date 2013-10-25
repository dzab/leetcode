#include <vector>
#include <algorithm>
using std::vector;

int uniquePathsWithObstacles(vector<vector<int> > &grid) {
    if (grid.empty()) return 0;
    if (grid[0][0] || grid.back().back()) return 0;
    vector<int> v(grid[0].size(), 0);
    v[0] = 1;
    for (int i = 0; i < grid.size(); ++i) {
        v[0] = (grid[i][0] || v[0]==0) ? 0 : 1;
        for (int j = 1; j < grid[i].size(); ++j) {
            if (grid[i][j]) v[j] = 0;
            else v[j] += v[j-1];
        }
        std::for_each(v.begin(), v.end(), [](int a){printf("%d ", a);});
        printf("\n");
    }
    return v[grid.back().size()-1];
}

int main()
{
    vector<vector<int> > vv{ {0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0} };
    uniquePathsWithObstacles(vv);
    return 0;
}
