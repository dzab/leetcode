#include <vector>
#include <algorithm>
using std::vector;
//subsets-II

void generate(const vector<int> &S, vector<int> &path, int depth, vector<vector<int> > &vv) {
    printf("depth=%d\n", depth);
    vv.push_back(path); //取0次是一定要的
    for (int i = depth; i < S.size(); ++i) {
        if (i != depth && S[i] == S[i-1]) continue;   //不重复的时候注掉这句就可以了
        path.push_back(S[i]);
        generate(S, path, i+1, vv);
        path.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > vv;
    vector<int> path;
    generate(S, path, 0, vv);
    // print vv
    for (int a = 0; a < vv.size(); ++a) {
        printf("[");
        for (int b = 0; b < vv[a].size(); ++b) printf("%d ", vv[a][b]);
        printf("],");
    }
    return vv;
}

int main()
{
    vector<int> v{ 1,2,3};
    subsets(v);
    return 0;
}
