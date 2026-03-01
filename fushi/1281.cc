#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isNum(char ch) {
    return (ch >= '0' && ch <= '9') ? true : false;
}
int cal(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}
int prio(char c) {
    return (c == '*' || c == '/') ? 1 : 0;
}
int main() {
    string s;
    while (cin >> s) {
        stack<int> st;
        stack<char> op;
        // + - * / 优先级
        int i = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (!isNum(s[j])) {
                int t = stoi(s.substr(i, j - i));
                st.push(t);
                // 优先级小或者相同：取两个数计算，结果入栈，当前op入栈
                // 优先级大：直接入栈

                // **必须用while!! 
                // 只要栈顶优先级大于等于当前操作符，就一直弹栈计算
                while (!op.empty() && prio(s[j]) <= prio(op.top())) {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    char n_op = op.top();
                    op.pop();
                    st.push(cal(a, b, n_op));
                }
                op.push(s[j]);
                j++;
                i = j;
            }
        }
        st.push(stoi(s.substr(i)));
        // 计算最后留在stack里的数
        while(!op.empty()) {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            char n_op = op.top();
            op.pop();
            st.push(cal(a, b, n_op));
        }
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
/*
6/2+3+3*4
18
15+20*10-3*8
191
15+20*10-48/2
*/