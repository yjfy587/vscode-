#include<iostream>
using namespace std;

struct sequenlist {
    int data[1000];
    int last;      // 最后一个元素的下标，空表时为 -1
};

// 创建空顺序表
sequenlist* create() {
    sequenlist* l = new sequenlist;
    l->last = -1;
    return l;
}

// 将 x 插入有序表（递增）中，保持有序
void insert(int x, sequenlist* l) {
    // 检查表是否已满
    if (l->last >= 999) {
        cout << "表满，无法插入" << endl;
        return;
    }

    int i = 0;
    // 找到第一个大于等于 x 的位置（即所有小于 x 的元素跳过）
    while (i <= l->last && l->data[i] < x) {
        i++;
    }

    // 将 i 及之后的元素后移一位
    for (int j = l->last; j >= i; j--) {
        l->data[j + 1] = l->data[j];
    }

    // 插入 x
    l->data[i] = x;
    // 更新表长
    l->last++;
}

int main() {
    sequenlist* a = create();

    // 手动构造一个递增序列 {1, 3, 5}
    a->data[0] = 1; a->last = 0;
    a->data[1] = 3; a->last = 1;
    a->data[2] = 5; a->last = 2;

    // 插入 4
    insert(4, a);

    // 输出结果
    for (int i = 0; i <= a->last; i++) {
        cout << a->data[i] << " ";
    }
    cout << endl;

    delete a;
    return 0;
}