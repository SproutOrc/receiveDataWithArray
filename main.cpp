//
//  main.cpp
//  TSCFunction
//
//  Created by Atropos on 15/1/20.
//  Copyright (c) 2015年 Atropos. All rights reserved.
//

#include <iostream>

#define MAX_ARRAY_LENGTH 15

typedef struct {
    char string[MAX_ARRAY_LENGTH];
    char length;
}Str;

/**
 * 环境 xcode
 * 本函数是为了获取串口数据的
 * str 输出字符结构体
 *     string 输出的内容
 *     length 数组长度（也可以通过strlen获得）
 * available 状态函数指针，返回串口接收状态位
 * get 读取串口数值函数指针，函数返回串口数值
 */

bool receiveDataWithArray(Str * const str, bool (* available)(void), char (* get)(void)) {
    int i;
    char getData;
    
    for (i = 0; i < MAX_ARRAY_LENGTH; ++i) {
        while ((*available)() != 1);
        getData = (*get)();
        if (getData == 'r') {
            str->string[i] = '\0';
            str->length = i;
        } else if (getData == 'n') {
            return true;
        } else {
            str->string[i] = getData;
        }
    }
    
    return false;
}

// 函数测试

bool available() {
    return true;
}

int testNum = 0;
char str[] = "ha\r\n";

char get() {
    return str[testNum];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
