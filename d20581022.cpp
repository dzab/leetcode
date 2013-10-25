#include <vector>
using std::vector;
//combinations

//统一在base case输出
void pick(vector<vector<int> > &vv, vector<int> v, int start, int end, int num) {
    if (0 == num) {
        vv.push_back(v);
        return;
    } 
    for (int i = start; i <= end-(num-1); ++i) {
        v.push_back(i);
        pick(vv, v, i+1, end, num-1);
        v.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > vv;
    vector<int> v;
    pick(vv,v, 1, n, k);
    return vv;
}

//在尾部添加, 真正的递归
vector<vector<int> > combine2(int n, int k) {
    if (n < k) return vector<vector<int> >();
    vector<vector<int> > vv; 
    vector<int> v;
    if (1 == k) {
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        vv.push_back(v);
        return vv;
    }
    for (int i = n; i >= k; --i) {
        vector<vector<int> > vvtemp = combine(i-1, k-1);
        for (int j = 0; j < vvtemp.size(); ++j) {
            vvtemp[j].push_back(i);
            vv.push_back(vvtemp[j]);
        }
    }
    return vv;        
}

int main()
{
    vector<vector<int> > vv = combine2(5,3);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[0].size(); ++j) 
            printf("%d ", vv[i][j]);
        printf("\n");
    }
    return 0;
}
