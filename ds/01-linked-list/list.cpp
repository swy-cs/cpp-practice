// ============================================================
//  单链表 —— 实现练习
//
//  用法：
//    编译  build.bat ds\01-linked-list\list.cpp
//    运行  .\build\list.exe
//
//  目标：把所有 TODO 填完，直到运行结果全部 PASS。
//  每个函数的时间复杂度写在注释里，写完自己核对一遍。
// ============================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* next;
    explicit Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head_(nullptr), size_(0) {}
    ~LinkedList() { clear(); }

    // 尾部插入 —— O(1) 还是 O(n)？想想没有尾指针时的情况
    void push_back(int v) {
        // TODO: 新建节点，挂到链表末尾；注意空链表的情况
    }

    // 头部插入 —— O(1)
    void push_front(int v) {
        // TODO
    }

    // 删除第一个值为 v 的节点，返回是否删成功 —— O(n)
    bool remove(int v) {
        // TODO: 注意三种情况
        //   1) v 在头节点
        //   2) v 在中间或尾部
        //   3) 链表里没有 v
        return false;
    }

    // 反转整条链表 —— O(n)，不许新建节点，只能改指针
    void reverse() {
        // TODO: 三个指针（prev / cur / next）经典写法
    }

    // 导出为 vector，方便测试比较 —— O(n)
    vector<int> toVector() const {
        vector<int> out;
        // TODO: 遍历链表填入 out
        return out;
    }

    int size() const { return size_; }
    bool empty() const { return size_ == 0; }

private:
    void clear() {
        // TODO: 释放所有节点，防止内存泄漏
        // 提示：不能先 delete 再访问 next
    }

    Node* head_;
    int size_;
};

// ============================================================
//  以下为测试代码，不要修改
// ============================================================
static int g_pass = 0;
static int g_fail = 0;

void check(const string& name, bool ok) {
    if (ok) {
        ++g_pass;
        cout << "  PASS  " << name << "\n";
    } else {
        ++g_fail;
        cout << "  FAIL  " << name << "\n";
    }
}

string vecToStr(const vector<int>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += to_string(v[i]);
        if (i + 1 < v.size()) s += ", ";
    }
    return s + "]";
}

void checkVec(const string& name, const vector<int>& got, const vector<int>& want) {
    bool ok = (got == want);
    if (!ok) {
        cout << "        期望 " << vecToStr(want) << " 实际 " << vecToStr(got) << "\n";
    }
    check(name, ok);
}

int main() {
    cout << "===== 单链表测试 =====\n\n";

    {
        cout << "[基础]\n";
        LinkedList l;
        check("空链表 size 为 0", l.size() == 0);
        check("空链表 empty 为 true", l.empty());

        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        checkVec("push_back 三次", l.toVector(), {1, 2, 3});
        check("size 为 3", l.size() == 3);
    }

    {
        cout << "\n[头部插入]\n";
        LinkedList l;
        l.push_front(3);
        l.push_front(2);
        l.push_front(1);
        checkVec("push_front 逆序插入", l.toVector(), {1, 2, 3});
    }

    {
        cout << "\n[删除]\n";
        LinkedList l;
        for (int i = 1; i <= 5; ++i) l.push_back(i);

        check("删除中间值 3", l.remove(3) == true);
        checkVec("删除后", l.toVector(), {1, 2, 4, 5});
        check("size 减少", l.size() == 4);

        check("删除头节点 1", l.remove(1) == true);
        checkVec("删除头后", l.toVector(), {2, 4, 5});

        check("删除尾节点 5", l.remove(5) == true);
        checkVec("删除尾后", l.toVector(), {2, 4});

        check("删除不存在的 99 返回 false", l.remove(99) == false);
        checkVec("不存在的值不影响链表", l.toVector(), {2, 4});
    }

    {
        cout << "\n[边界情况]\n";
        LinkedList l;
        check("空链表删除返回 false", l.remove(1) == false);

        l.push_back(7);
        check("单节点删除自己", l.remove(7) == true);
        check("删完变空", l.empty() && l.size() == 0);
    }

    {
        cout << "\n[反转]\n";
        LinkedList l;
        for (int i = 1; i <= 5; ++i) l.push_back(i);
        l.reverse();
        checkVec("反转 1..5", l.toVector(), {5, 4, 3, 2, 1});

        LinkedList one;
        one.push_back(42);
        one.reverse();
        checkVec("单节点反转", one.toVector(), {42});

        LinkedList emptyList;
        emptyList.reverse();
        checkVec("空链表反转", emptyList.toVector(), {});
    }

    cout << "\n===== 结果：" << g_pass << " 通过 / " << g_fail << " 失败 =====\n";
    if (g_fail == 0) {
        cout << "全部通过！可以提交了：\n";
        cout << "  git add .\n";
        cout << "  git commit -m \"feat(list): 完成单链表基础操作\"\n";
        cout << "  git push\n";
    } else {
        cout << "还有 " << g_fail << " 项没通过，逐个排查边界情况。\n";
    }
    return g_fail == 0 ? 0 : 1;
}
