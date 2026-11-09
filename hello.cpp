// ===================================================
//  hello.cpp —— 环境验证程序
//  编译：Ctrl + Shift + B
//  运行：终端执行 build\hello.exe
// ===================================================
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "环境配置成功！" << std::endl;

    // 顺便演示一下后面数据结构要用的容器
    std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    int sum = 0;
    for (int x : nums) sum += x;

    std::cout << "vector 求和 = " << sum << std::endl;
    std::cout << "C++ 标准版本 = " << __cplusplus << std::endl;
    return 0;
}
