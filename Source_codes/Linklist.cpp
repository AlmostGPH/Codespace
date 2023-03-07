#include<iostream>
using namespace std;

template<class T>
class Link{
public:
    T data;
    Link<T> *next;

    Link(const T info,const Link<T>*nextValue=NULL){
        data=info;
        next=nextValue;
    }
    Link(const Link<T>*nextValue){
        next=nextValue;
    }
};

template<class T>
class lnkList{
private:
    Link<T>* head,* tail;
    Link<T>* setPos(const int p);
public:
    lnkList(int s);
    ~lnkList();
    bool isEmpty();
    void clear();
    int length();
    bool append(const T value);
    bool insert(const int p,const T value);
    bool lnkdelete(const int p);
    bool getValue(const int p,T& value);
    bool getPos(int &p,const T value);
};

template<class T>
lnkList<T>::lnkList(int defSize){
    head=tail=new Link<T>;
}
template<class T>
lnkList<T>::~lnkList(){
    Link<T>* tmp;
    while(head!=NULL){
        tmp=head;
        head=head->next;
        delete tmp;
    }
}

template<class T>
Link<T> * lnkList<T>::setPos(int i){
    int count=0;
    if(i==-1) return head;
    Link<T>* p=new Link<T>(head->next);
    while(p!=NULL&&count<1){
        p=p->next;
        count++;
    }
    return p;
}

template<class T>
bool lnkList<T>::insert(const int i,const T value){
    Link<T> * p,* q;
    if((p=setPos(i-1))==NULL){
        cout<<"Illegal insert point."<<endl;
        return false;
    }
    q = new Link<T>(value,p->next);
    p->next=q;
    if(p==tail) tail = q;
    return true;
}

template<class T>
bool lnkList<T>::lnkdelete(const int i){
    Link<T>*p,*q;
    if((p=setPos(i-1))==NULL||p==tail){
        cout<<"Can not delete this point."<<endl;
        return false;
    }
    q=p->next;
    if(q==tail){
        tail=p;
        p->next=NULL;
        delete q;
    }
    else if(q!=NULL){
        p->next=q->next;
        delete q;
    }
    return true;
}
//Below are by myself，more possibilities of bugs
template<class T>
bool lnkList<T>::isEmpty(){
    if(head->next=NULL) return true;
    else return false;
}

template<class T>
void lnkList<T>::clear(){
    Link<T>* tmp;
    while(head!=NULL){
        tmp=head;
        head=head->next;
        delete tmp;
    }
    delete head;
    delete tail;
}

template<class T>
int lnkList<T>::length(){
    Link<T>* p;
    int t=0;
    while(p!=NULL){
        p=p->next;
        t++;
    }
    return t;
}

int main(){

    return 0;
}
