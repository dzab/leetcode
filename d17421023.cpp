#include <vector>
#include <algorithm>
using std::vector;

// choose k numbers from n numbers
/*
void generate(const vector<int> &S, vector<int> &v, int n, int k, vector<vector<int> > &vv) {
    if (1 == k) {
        for (int i = n-1; i >= 0; --i) { v.push_back(S[i]); vv.push_back(v); v.pop_back(); }
        return;
    }
    for (int i = n-1; i >= k-1; --i) {
        v.push_back(S[i]);
        generate(S, v, i, k-1, vv);
        v.pop_back();
    }
}
*/
// choose k numbers between [first, last]

void generate(const vector<int> &S, vector<int> &v,  int first, int last, int k, vector<vector<int> > &vv) {
    if (1 == k) {
        for (int i = first; i <= last; ++i) { v.push_back(S[i]); vv.push_back(v); v.pop_back(); }
        return;
    }
    for (int i = first; i <= last-(k-1); ++i) {
        v.push_back(S[i]);
        generate(S, v, i+1 , last, k-1, vv);
        v.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &S) {
    int n = S.size();
    if (S.empty()) return vector<vector<int> >();
    vector<vector<int> > vv;
    vector<int> v;
    vv.push_back(v);  // k = 0;
    std::sort(S.begin(), S.end());
    for (int k = 1; k <= n; ++k) {
        printf("k=%d\n", k);
        //generate(S, v, n, k, vv);
        //因为输出要求有序,所以不能从后面打,省不了参数了
        generate(S, v, 0, n-1, k, vv);
    }
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j)
            printf("%d ", vv[i][j]);
        printf("\n");
    }
    return vv;
}


//迭代生成
/*
vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > v(1);
    for(int i = 0; i < S.size(); ++i) {
        int j = v.size();
        while(j-- > 0) {
            v.push_back(v[j]);
            v.back().push_back(S[i]);
        }
        for (int a = 0; a < v.size(); ++a) {
            printf("[");
            for (int b = 0; b < v[a].size(); ++b) printf("%d ", v[a][b]);
            printf("],");
        }
        printf("\n");
    }
    return v;
}
*/

int main()
{
    vector<int> v{ 1,2,2};
    subsets(v);
    return 0;
}
