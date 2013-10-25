#include <vector>
#include <cstdio>
//gray-code

std::vector<int> v;

std::vector<int> grayCode(int n) {
    v.clear();
    v.reserve(1<<n);
    if (n >= 0) v.push_back(0);
    if (n >= 1) v.push_back(1);
    int k = 1;
    while (k < n) {
        unsigned int highestBit = 1 << k;
        int sz = v.size();
        for (int i = sz-1; i >= 0; --i) {
            v.push_back(v[i]|highestBit);
        }
        ++k;
    }       
    return v;
}

int main()
{
    int n; 
    scanf("%d", &n);
    grayCode(n);
    for (int i = 0; i < (1<<n); ++i) {
        printf("%x ", v[i]);
    }
    printf("\n");
    return 0;
}
