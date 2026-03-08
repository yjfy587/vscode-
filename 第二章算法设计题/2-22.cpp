#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// 创建链表（输入 -1 结束）
node* create() {
    node* head = nullptr;
    node* tail = nullptr;
    int x;
    while (cin >> x && x != -1) {
        node* newNode = new node;
        newNode->data = x;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 逆转链表
node* reverse(node* head) {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;
    
    while (curr != nullptr) {
        next = curr->next;  // 保存下一个节点
        curr->next = prev;  // 反转指针
        prev = curr;        // 前移
        curr = next;        // 前移
    }
    return prev;  // 新的头节点
}

// 打印链表
void print(node* head) {
    node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    cout << "请输入链表元素（-1结束）: ";
    node* head = create();
    
    cout << "原链表: ";
    print(head);
    
    head = reverse(head);
    
    cout << "逆转后: ";
    print(head);
    
    return 0;
}