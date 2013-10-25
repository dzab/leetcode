#include <vector>
#include <algorithm>
using std::vector;

vector<vector<int> > vv;
vector<vector<int> > permute(vector<int> &num)
{
    std::sort(num.begin(), num.end());
    do {
        vv.push_back(num);
    }while(std::next_permutation(num.begin(), num.end()));
    return vv;
}
void generate(vector<int> &num, int k) 
{
    if (num.size() == k+1) {
        vv.push_back(num);
    }else {
        for (int i = k; i < num.size(); ++i) {
            std::swap(num[i], num[k]);
            generate(num, k+1);
            std::swap(num[i], num[k]);
        }
    }
}

vector<vector<int> > permute2(vector<int> &num)
{
    generate(num, 0);
    return vv;
}

int main()
{
    vector<int> v = { 1,2,3,4 };
    //vector<vector<int> > vv;
    vv = permute2(v);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) {
            printf("%d ", vv[i][j]);
        }
        printf("\n");
    }
    return 0;
}
