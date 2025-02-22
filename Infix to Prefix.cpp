#include<string>
#include <iostream>
#include<algorithm>
using namespace std;

#define MAX_SIZE 20
template<class T>
class stack {
    int top;
    T arr[MAX_SIZE];

public:

    stack() {  
        top = -1;
    }

    void push(T x) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow";
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " is pushed into Stack " << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Empty";
            return;
        }
        cout << arr[top] << " is popped from the stack" << endl;
        top--;
    }

    T peek() {
        if (top == -1) {
            cout << "Stack is Empty";
            return T();
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

};
int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
int main()
{
    stack<char>s;
    string op;
    cout << "Enter operation =  ";
    getline(cin, op);
    reverse(op.begin(), op.end());
    string result;
    for (char ch : op){
        if (ch >= 'a' && ch <= 'z') {
            cout << ch << endl;
            result += ch;
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!s.isEmpty() && prec(s.peek()) > prec((ch))) {
                result += s.peek();
                s.pop();
            }
            s.push(ch);
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.peek();
                s.pop();
            }
            if (!s.isEmpty()) {
                s.pop();
            }
        }
    }
    while (!s.isEmpty()) {
        result += s.peek();
        s.pop();
    }
    reverse(result.begin(), result.end());
    cout << "\nPrefix Expression: " << result;

    return 0;
}

