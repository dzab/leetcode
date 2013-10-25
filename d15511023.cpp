#include <vector>
#include <string>
using std::vector;
using std::string;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return string();
    char c;
    string res;
    int idx = 0;
    while (strs[0].size() > idx) {
        bool pass = true;
        c = strs[0][idx];
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].size() <= idx || strs[i][idx]!=c) { pass = false; break; }
        }
        if (pass) res.append(1, c);
        idx++;
    }
    return res;
}

int main()
{
    vector<string> vs = { "aca", "cba" };
    printf("%s\n", longestCommonPrefix(vs).c_str());
    return 0;
}

