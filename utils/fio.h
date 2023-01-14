#ifndef SORTALGORITHM_FIO_H
#define SORTALGORITHM_FIO_H

#include <cstdio>

int read() {
    int ch = getchar();
    int op = 1, value = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') op = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        value = value * 10 + ch - 48;
        ch = getchar();
    }
    return op * value;
}

template<typename T>
static void writeUnsigned(T value) {
    if (value > 9) writeUnsigned(value / 10);
    putchar(value % 10 + 48);
}

template<typename T>
void write(T value) {
    if (value < 0) putchar('-'), value = -value;
    write(value), putchar('\n');
}

#endif //SORTALGORITHM_FIO_H
