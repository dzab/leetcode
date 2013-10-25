#include <stack>
#include <string>
using std::string;

bool isValid(string s) {
    if (s.empty()) return false;
    std::stack<int> st;
    char c;
    if (s[0]!='(' && s[0]!='[' && s[0]!='{') return false;
    st.push(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (!st.empty() && (
                (s[i]==')' && st.top()=='(') ||
                (s[i]==']' && st.top()=='[') ||
                (s[i]=='}' && st.top()=='{') )) {
            st.pop();
        } else if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
            st.push(s[i]);
        } else {
            return false;
        }
    }
    if (st.empty()) return true; else return false;  
}

int main()
{
    std::string str("[])");
    printf("string=%s %d\n", str.c_str(), isValid(str));
    return 0;
}
