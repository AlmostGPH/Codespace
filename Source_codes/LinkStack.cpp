#include<iostream>
using namespace std;

template<class T>
class Link{
public:
    T data;
    Link<T> *next;

    Link(const T info,Link<T>*nextValue=NULL){
        data=info;   
        next=nextValue;
    }
    Link(const Link<T>*nextValue){
        next=nextValue;
    }
};

template<class T>
class lnkStack{
private:
    Link<T>* top;
    int size;
public:
//    lnkStack(defsize){
//        top = nullptr;
//        size=defsize;
//    }
    lnkStack(){
        top = nullptr;
        size=0;
    }
    ~lnkStack(){
        clear();
    }
    void clear(){
        while(top!=nullptr){
            Link<T>*tmp=top;
            top=top->next;
            delete tmp;
        }
        size = 0;
    }
    bool push(const T item){
        Link<T>* tmp=new Link<T>(item,top);
        top=tmp;
        size++;
        return true;
    }
    bool pop(T& item){
        Link<T>*tmp;
        if(size==0){
            cout<<"删不了了"<<endl;
            return false;
        }
        item=top->data;
        tmp=top->next;
        delete top;
        top=tmp;
        size--;
        return true;
    }
    bool sttop(T& item){
        if (size==0){
            cout<<"栈为空，无法读取"<<endl;
            return false;
        }
        item = top->data;
        return true;
    }
};

// cin.peek()!='+'||cin.peek()!='-'||cin.peek()!='*'||cin.peek()!='/'

int main(){
    lnkStack<int> st;
    while(cin.peek()!= '#'){
        if(cin.peek()==' '){
            cin.get();
        }
        else{
            char n;
            n=cin.peek();
            if(n=='+'||n=='-'||n=='*'||n=='/'){
                int i2;
                int i1;
                st.pop(i2);
                st.pop(i1);
                if(n=='+') st.push(i1+i2);
                else if(n=='-') st.push(i1-i2);
                else if(n=='*') st.push(i1*i2);
                else st.push(i1/i2);
                cin.get();
            }
            else {
                int item;
                cin>>item;
                st.push(item);
            }
        }
    }
    int tp;
    st.sttop(tp);
    cout<<tp<<endl;
    return 0;
}










