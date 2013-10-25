#include <cstdio>
#include <string>

int CharToNum(char c)
{
    switch(c) {
        case  'I': return 1; break;
        case  'V': return 5; break;
        case  'X': return 10; break;
        case  'L': return 50; break;
        case  'C': return 100; break;
        case  'D': return 500; break;
        case  'M': return 1000; break;
        default: return -1;
    }
    return -1;
}

int romanToInt(std::string str) {
    int sum = 0;
    int cur = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i]=='I') {
        } else if (str[i]=='X') {
        } else if (str[i]=='C') {
        }
    }
    return 0;
}

int main()
{

    
}
