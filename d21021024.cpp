#include <vector>
#include <algorithm>
using std::vector;

bool NextPermutation(vector<int> &num) {
    int n = num.size();
    int ii = n-1;
    int i, j;
    while (ii > 0) {
        i = ii-1;
        if (num[i] < num[ii]) {
            j = n;
            while (num[--j] <= num[i]) ;
            std::swap(num[i], num[j]);
            std::reverse(num.begin()+ii, num.end());

            for (int j = 0; j < num.size(); ++j) 
                printf("%d ", num[j]);
            printf("\n");
            return true;
        } else {
            ii--;
        }
    }
    return false;
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    int n = num.size();
    std::sort(num.begin(), num.end());
    vector<vector<int> > vv;
    do {
        vv.push_back(num);
    }while(NextPermutation(num));
    return vv;
}

int main()
{
    vector<int> num{1,2,2};
    vector<vector<int> > vv = permuteUnique(num);
   /* for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) 
            printf("%d ", vv[i][j]);
        printf("\n");
    }
    */
    return 0;
}
