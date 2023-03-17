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
    bool pekValue(const int p,T& value);
    bool getPos(int &p,const T value);
};

template<class T>
lnkList<T>::lnkList(int defSize){
    head=new Link<T>(defSize);
    tail=new Link<T>(defSize);
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
    while(head!=NULL){
        Link<T>* tmp;
        tmp=head;
        head=head->next;
        delete tmp;
    }
    delete head;
    delete tail;
}

template<class T>
int lnkList<T>::length(){
    Link<T>* p=head;
    int t=0;
    while(p!=NULL){
        p=p->next;
        t++;
    }
    return t;
}

template<class T>

bool lnkList<T>::append(const T value){
    if(head==NULL){
        head=new Link<T>(value,nullptr);
        tail = head;
    }
    else{
        tail->next=new Link<T>(value);
        tail=tail->next;
    }   
    return true;
}

template<class T>
bool lnkList<T>::getValue(const int p,T& value){
    if(p>length()||p<0){
        cout<<"非法位置"<<endl;
        return false;
    }
    else{
        Link<T>* tmp=head;
        for(int i=0;i<p;i++){
            tmp=tmp->next;
        }
        value=tmp->data;
        return true;
    }
}


template<class T>
bool lnkList<T>::pekValue(const int p,T& value){
    if(p>length()||p<0){
        return false;
    }
    else{
        Link<T>* tmp=head;
        for(int i=0;i<p;i++){
            tmp=tmp->next;
        }
        value=tmp->data;
        return true;
    }
}

//int arl1[6]={3,4,2,3,1,2};
//int arl2[8]={-2,3,4,2,5,1,6,0};

int main(){
    int sizea;
    cout<<"请指定第一个多项式项数"<<endl;
    cin>>sizea;
    cout<<"请按序输入系数和幂次"<<endl;
    int* arl1=new int[sizea*2];
    for(int i=0;i<sizea*2;i++){
        cin>>arl1[i];
    }
    int sizeb;
    cout<<"请指定第二个多项式项数"<<endl;
    cin>>sizeb;
    cout<<"请按序输入系数和幂次"<<endl;
    int* arl2=new int[sizeb*2];
    for(int i=0;i<sizeb*2;i++){
        cin>>arl2[i];
    }
    lnkList<int> al(sizea*2),bl(sizeb*2),cl(sizea*2+sizeb*2);
    for(int i=0;i<sizea*2;i++){
        al.append(arl1[i]);
    }
    for(int i=0;i<sizeb*2;i++){
        bl.append(arl2[i]);
    }	

    int p1,p2;
    int n1=2,n2=2,ta=0;
    while(al.pekValue(n1,p1)==true||bl.pekValue(n2,p2)==true){
        if(al.pekValue(n1,p1)==false&&bl.pekValue(n2,p2)==true){
            int v3;
            bl.getValue(n2-1,v3);
            if(v3!=0){
                cl.append(v3);
                cl.append(p2);
                ta+=2;
                n2+=2;
            }
            else{
                n2+=2;
            }
        }
        else if(al.pekValue(n1,p1)==true&&bl.pekValue(n2,p2)==false){
            int v3;
            al.getValue(n1-1,v3);
            if(v3!=0){
                cl.append(v3);
                cl.append(p1);
                ta+=2;
                n1+=2;
            }
            else{
                n2+=2;
            }
        }
        else{
            if(p1<p2){
                int v3;
                bl.getValue(n2-1,v3);
                if(v3!=0){
                    cl.append(v3);
                    cl.append(p2);
                    ta+=2;
                    n2+=2;
                }
                else{
                    n2+=2;
                }
            }
            else if(p1>p2){
                int v3;
                al.getValue(n1-1,v3);
                if(v3!=0){
                    cl.append(v3); 
                    cl.append(p1);
                    ta+=2;
                    n1+=2;
                }
                else{
                    n2+=2;
                }
            }
            else{
                int v3a,v3b;
                al.getValue(n1-1,v3a);
                bl.getValue(n2-1,v3b);
                if((v3a+v3b)!=0){
                    cl.append(v3a+v3b);
                    cl.append(p1);
                    ta+=2;
                    n1+=2;
                    n2+=2;
                }
                else{
                    n1+=2;
                    n2+=2;
                }
            }
        }
    }
    int p3,v3=1;
    cout<<"相加后为如下"<<endl;
    for(int i=0;i<ta;i++){
        cl.getValue(v3,p3);
        cout<<p3<<' ';
        v3++;	
    }
    return 0;
}
