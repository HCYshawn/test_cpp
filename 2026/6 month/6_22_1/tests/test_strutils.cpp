#include <cassert>
#include <iostream>
#include <string>

#include "strutils/strutils.hpp"

int main()
{
    // 测试1: 普通字符串转大写
    {
        std::string result = strutils::to_upper("hello world");
        assert(result == "HELLO WORLD");
        std::cout << "[PASS] Test 1: to_upper normal string" << std::endl;
    }

    // 测试2: 普通字符串转小写
    {
        std::string result = strutils::to_lower("HELLO WORLD");
        assert(result == "hello world");
        std::cout << "[PASS] Test 2: to_lower normal string" << std::endl;
    }

    // 测试3: 空字符串
    {
        assert(strutils::to_upper("") == "");
        assert(strutils::to_lower("") == "");
        std::cout << "[PASS] Test 3: empty string" << std::endl;
    }

    // 测试4: 含数字和符号的字符串
    {
        std::string result = strutils::to_upper("Hello 123 !@#");
        assert(result == "HELLO 123 !@#");
        std::cout << "[PASS] Test 4: string with numbers and symbols" << std::endl;
    }

    // 测试5: 全大写 / 全小写不变
    {
        assert(strutils::to_upper("ALREADY UPPER") == "ALREADY UPPER");
        assert(strutils::to_lower("already lower") == "already lower");
        std::cout << "[PASS] Test 5: already upper/lower unchanged" << std::endl;
    }

    // 测试6: 混合大小写
    {
        std::string result = strutils::to_lower("MiXeD CaSe");
        assert(result == "mixed case");
        std::cout << "[PASS] Test 6: mixed case to lower" << std::endl;
    }

    std::cout << "\nAll tests passed!" << std::endl;
    return 0;
}
