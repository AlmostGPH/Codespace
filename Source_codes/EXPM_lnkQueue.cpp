#include<iostream>
using namespace std;

template<class T>
class Link {									//节点类定义 
public:
    T data;
    Link<T>* next;

    Link(const T info, Link<T>* nextValue = nullptr) {
        data = info;
        next = nextValue;
    }
    Link(Link<T>* nextValue) {
        data = 0;
        next = nextValue;
    }
};

template <class T>
class lnkQueue {
private:
    int size;
    Link<T>* front;
    Link<T>* rear;
public:
    lnkQueue() {
        size = 0;
        front = rear = nullptr;
    }
    ~lnkQueue() {
        clear();
    }
    int length() {
        return size;
    }
    void clear() {                  //清除整个队列
        while (front != nullptr) {
            rear = front;
            front = front->next;
            delete rear;
        }
        rear = nullptr;
        size = 0;
    }
    bool enQueue(const T item) {            //从队尾输入一个元素
        if (rear == nullptr) {
            front = rear = new Link<T>(item, nullptr);
        }
        else {
            rear->next = new Link<T>(item, nullptr);
            rear = rear->next;
        }
        size++;
        return true;
    }
    bool absenQueue(const T item) {
        if (rear == nullptr) {
            front = rear = new Link<T>(item, nullptr);
            size++;
        }
        else {
            if (item < rear->data) {
                rear->next = new Link<T>(item, nullptr);
                rear = rear->next;
                size++;
            }
            else {
                int vr;
                deRear(vr);
                absenQueue(item);
            }
        }
        return true;
    }

    bool deQueue(T& item) {                     //从队首拿出一个元素
        Link<T>* tmp;
        if (size == 0) {
            cout << "为空，没有元素" << endl;
            return false;
        }
        item = front->data;
        tmp = front;
        front = front->next;
        delete tmp;
        if (front == nullptr) {
            rear = nullptr;
        }
        size--;
        return true;
    }
    bool getFront(T& item) {                    //看看队首的元素
        if (size == 0) {
            cout << "为空，没有元素" << endl;
            return false;
        }
        item = front->data;
        return true;
    }
    bool getRear(T& item) {                     //看看队尾的元素
        if (size == 0) {
            cout << "为空，没有元素" << endl;
            return false;
        }
        item = rear->data;
        return true;
    }
    bool deRear(T& item) {                      //拿出队尾的元素
        Link<T>* tmp1,* tmp2;
        tmp2 = rear;
        if (size == 0) {
            cout << "为空，没有元素" << endl;
            return false;
        }
        item = rear->data;
        tmp1 = front;
        for (int i = 0; i < size - 1; i++) {
            tmp1 = tmp1->next;
        }
        tmp1->next = nullptr;    
        rear = tmp1;
        delete tmp2;
        return true;
    }
};

int main() {
    int size = 0, win = 0;
    cin >> size >> win;
    int* winout = new int[size - win + 1]();
    lnkQueue<int> q;
    int tcin=0;
    for (int i = 0; i < size; i++) {
        int tmp;
        cin >> tmp;
        if (q.length() == 3) {
            int vf;
            q.deQueue(vf);
        }
        else {
            if (q.length() == 0) {
                q.enQueue(tmp);
            }
            else {
                q.absenQueue(tmp);
            }
            tcin++;
            if (tcin >= 3) {
                int vf;
                winout[i - 3] = q.getFront(vf);
            }
        }     
    }
    for (int i = 0; i < size - win + 1; i++) {
        cout << winout[i] << " ";
    }
    cout << endl;
    return 0;
}