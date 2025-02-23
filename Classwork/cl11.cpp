#include <iostream>
using namespace std;

const int MAX = 50;

template <class T>
struct Stack{
    T data[MAX];
    int size;
};

template <class T>
void initStack(Stack<T>& s){
    s.size = 0;
}

template <class T>
void hienThi(Stack<T> s){
    cout << endl;
    for(int i = 0; i < s.size ; i ++)
        cout << s.data[i] << ' ';
 
}

template <class T>
T isFull(Stack<T> s){
    return s.size == MAX;
}

template <class T>
T isEmpty(Stack<T> s){
    return s.size == 0;
}

template <class T>
void push1(Stack<T>& s, T x){
    if(isFull(s))
    {
        cout << "STACK IS FULL" << endl;
        return;
    }
    s.data[s.size] = x;
    s.size++;
}

template <class T>
void push2(Stack<T>* s, T x){
    if(isFull(*s))
    {
        cout << "STACK IS FULL" << endl;
        return;
    }
    s->data[s->size] = x;
    s->size++;
}
template <class T>
T pop(Stack<T>& s){
    if(isEmpty(s))
    {
        cout << "STACK IS EMPTY" << endl;
        return 0;
    }
    s.size--;
    return s.data[s.size];
}

template <class T>
T peek(Stack<T> s){
    return s.data[s.size-1];
}
//template <class T>
int main(){
    Stack<char> s;
    initStack(s);
    push2(&s,'a');
    push2(&s,'b');
    push2(&s,'c');
    push1(s,'d');
    push1(s,'e');
    hienThi(s);
    int p = pop(s);
    hienThi(s);
}
