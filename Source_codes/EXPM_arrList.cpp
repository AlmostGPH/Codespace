#include<iostream>
using namespace std;

template<class T>
class arrList{
private:
    T*aList;
    int maxSize;
    int curLen;
    int position;
public:
    arrList(const int size){
        maxSize=size;
        aList=new T[maxSize];
        curLen=position=0;
    }
    ~arrList(){
        delete[]aList;
    }
    void clear(){
        delete[]aList;
        curLen=position=0;
        aList=new T[maxSize];
    }
    int length();
    bool append(const T value);
    bool insert(const int p, const T value);
    bool arrdelete(const int p);
    bool setValue(const int p,const T value);
    bool getValue(const int p,T& value);
    bool pekValue(const int p,T& value);
    bool getPos(int& p,const T value);
};

template <class T>
bool arrList<T>::getPos(int& p,const T value){
    int i;
    int n=curLen;
    for(i=0;i<n;i++){
        if(value==aList[i]){
            p=i;
            return true;
        }
    }
    return false;
}

template <class T>
bool arrList<T>::insert(const int p,const T value){
    int i;
    if(curLen>=maxSize){
        cout<<"顺序表溢出了"<<endl;
        return false; 
    }
    if(p<0||p>curLen){
        cout<<"不能插在这儿"<<endl;
        return false;
    }
    for(i=curLen;i>p;i--){ 
        aList[i]=aList[i-1];
    aList[p]=value;
    curLen++;
    return true;
    }
}

template <class T>
bool arrList<T>::arrdelete(const int p){
    int i;
    if (curLen<=0){
        cout<<"顺序表为空"<<endl;
        return false; 
    }
    if(p<0||p>curLen-1){
        cout<<"不能删这儿"<<endl;
        return false; 
    } 
    for(i=p;i<curLen-1;i++){
        aList[i]=aList[i+1];
        curLen--;
        return true;
    }
}

template <class T>
bool arrList<T>::append(const T value){
    int i=curLen+1;
    if(curLen>=maxSize){
        cout<<"顺序表溢出了"<<endl;
        return false; 
    }
    aList[i]=value;
    curLen++;
    return true;
}

template <class T>
bool arrList<T>::setValue(const int p,const T value){
    int i=p;
    if(p<0||p>maxSize){
        cout<<"不能改这儿"<<endl;
        return false; 
    }
    aList[i]=value;
    return true;
}

template <class T>
bool arrList<T>::getValue(const int p,T& value){
    int i=p;
    if(p<0||p>maxSize){
        cout<<"非法位置"<<endl;
        return false; 
    }	
    value=aList[i];
    return true;
}

template <class T>
bool arrList<T>::pekValue(const int p,T& value){
    int i=p;
    if(p<0||p>maxSize){
        return false;
    }
    value=aList[i];
    return true;
}

template <class T>
int arrList<T>::length(){
    return curLen;
}

//int arl1[6]={3,4,2,3,1,2};
//int arl2[8]={-2,3,4,2,5,1,6,0};

//sizeof(arl1)/sizeof(arl1[0])+6
//sizeof(arl2)/sizeof(arl2[0])+6

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
    arrList<int> al(sizea*2),bl(sizeb*2),cl(sizea*2+sizeb*2);
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
//	while(cl.pekValue(v3,p3)){
//				cl.getValue(v3,p3);
//		cout<<p3<<' ';
//		v3++;
//	}
//	
    
    for(int i=0;i<ta;i++){
        cl.getValue(v3,p3);
        cout<<p3<<' ';
        v3++;	
    }
    return 0;
}