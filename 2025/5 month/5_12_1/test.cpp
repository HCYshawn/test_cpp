#include <stdio.h>

#define LOG(fmt, ...) printf("[%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__)

int main()
{
    LOG("hh", 20);
    return 0;
}