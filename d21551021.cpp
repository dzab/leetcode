#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
//generate-parentheses

//搜索题
void generateP(int n, vector<string> &vs, string str, int l, int r)
{
    if (l == n) {
        vs.push_back(str.append(n-r, ')'));
        return;
    }
    generateP(n, vs, str+'(', l+1, r);
    if (r < l) {
        generateP(n, vs, str+')', l, r+1);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> vs;
    generateP(n, vs, "", 0, 0);
    return vs;
}

int main()
{
    vector<string> vs = generateParenthesis(3);
    std::for_each(vs.begin(), vs.end(), [](string s){ printf("%s , ", s.c_str()); });
    printf("\n");
    return 0;
}


