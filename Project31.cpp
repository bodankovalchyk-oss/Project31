#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

class StaticStack {
    char* arr;
    int maxSize;
    int top;
public:
    StaticStack(int n = 10) {
        maxSize = n;
        arr = new char[maxSize];
        top = 0;
    }
    ~StaticStack() { delete[] arr; }

    bool push(char c) {
        if (top == maxSize) return false;
        arr[top++] = c;
        return true;
    }
    bool pop(char& c) {
        if (top == 0) return false;
        c = arr[--top];
        return true;
    }
    int count() { return top; }
    bool isEmpty() { return top == 0; }
    bool isFull() { return top == maxSize; }
    void clear() { top = 0; }
    bool peek(char& c) {
        if (top == 0) return false;
        c = arr[top - 1];
        return true;
    }
};

class DynamicStack {
    char* arr;
    int maxSize;
    int top;

    void resize() {
        int newSize = maxSize * 2;
        char* tmp = new char[newSize];
        for (int i = 0; i < top; i++)
            tmp[i] = arr[i];
        delete[] arr;
        arr = tmp;
        maxSize = newSize;
    }
public:
    DynamicStack(int n = 4) {
        maxSize = n;
        arr = new char[maxSize];
        top = 0;
    }
    ~DynamicStack() { delete[] arr; }

    void push(char c) {
        if (top == maxSize) resize();
        arr[top++] = c;
    }
    bool pop(char& c) {
        if (top == 0) return false;
        c = arr[--top];
        return true;
    }
    int count() { return top; }
    int capacity() { return maxSize; }
    bool isEmpty() { return top == 0; }
    void clear() { top = 0; }
    bool peek(char& c) {
        if (top == 0) return false;
        c = arr[top - 1];
        return true;
    }
};

template <typename T>
class Stack {
    T* arr;
    int maxSize;
    int top;

    void resize() {
        int newSize = maxSize * 2;
        T* tmp = new T[newSize];
        for (int i = 0; i < top; i++)
            tmp[i] = arr[i];
        delete[] arr;
        arr = tmp;
        maxSize = newSize;
    }
public:
    Stack(int n = 4) {
        maxSize = n;
        arr = new T[maxSize];
        top = 0;
    }
    Stack(int n, initializer_list<T> list) {
        maxSize = n;
        if ((int)list.size() > maxSize) maxSize = list.size();
        arr = new T[maxSize];
        top = 0;
        for (auto x : list)
            arr[top++] = x;
    }
    ~Stack() { delete[] arr; }

    void push(T v) {
        if (top == maxSize) resize();
        arr[top++] = v;
    }
    bool pop(T& v) {
        if (top == 0) return false;
        v = arr[--top];
        return true;
    }
    int count() { return top; }
    int capacity() { return maxSize; }
    bool isEmpty() { return top == 0; }
    void clear() { top = 0; }
    bool peek(T& v) {
        if (top == 0) return false;
        v = arr[top - 1];
        return true;
    }
};

int main() {
    StaticStack s1(3);
    s1.push('a');
    s1.push('b');
    s1.push('c');
    cout << s1.count() << " " << s1.isFull() << endl;
    cout << s1.push('d') << endl;
    char c;
    s1.peek(c);
    cout << c << endl;
    while (s1.pop(c)) cout << c << " ";
    cout << endl;

    DynamicStack s2(2);
    for (char ch = 'a'; ch <= 'h'; ch++) {
        s2.push(ch);
        cout << s2.count() << "/" << s2.capacity() << " ";
    }
    cout << endl;
    while (s2.pop(c)) cout << c << " ";
    cout << endl;

    Stack<int> s3(3, { 1, 2, 3, 4, 5 });
    s3.push(6);
    int x;
    s3.peek(x);
    cout << s3.count() << " " << s3.capacity() << " " << x << endl;
    while (s3.pop(x)) cout << x << " ";
    cout << endl;

    Stack<string> s4(2, { "one", "two" });
    s4.push("three");
    string str;
    while (s4.pop(str)) cout << str << " ";
    cout << endl;

    return 0;
}