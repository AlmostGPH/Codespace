#include<iostream>
using namespace std;

template<class T>
class arrStack{
private:
    int nSize;
    int top;
    T * st;
public:
    arrStack(int size){
        mSize=size;
        top = -1;
        st = new T[mSize];
    }
    arrStack(){
        top = -1;
    }
    ~arrStack(){
        delete[]st;
    }
    void clear(){
        top = -1;
    }
    bool push(const T item){
        if((top == mSize -1)){
            cout<<"栈溢出了"<<endl;
            return false;
        }
        else{
            st[++top]=item;
            return true;
        }
    }
    bool pop(T & item){
        if(top == -1){
            cout<<"栈为空"<<endl;
            return false;
        }
        else{
            item = st[top--];
            return true;
        }
    }
    bool top(T & item){
        if (top == -1){
            cout<<"栈为空"<<endl;
            return false;
        }
        else{
            item=st[top];
            return true;
        }
    }
    bool abspush(const T item);
};

template<class T>
bool arrStack<T>::abspush(const T item){
    if(top == mSize -1){
        T * newSt=new T [mSize * 2];
        for (int i=0;i<=top;i++){
            newSt[i]=st[i];
        }
        delete[]st;
        st = newSt;
        mSize*=2;
    }
    st[++top]=item;
    return true;
}