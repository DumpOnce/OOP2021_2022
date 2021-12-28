//
// Created by Admin on 20.10.2021.
//

//#include "../Dynamic/bigInt.h"
//#include "../../include/menu/menu.h"
//int main(){
//
//   // std::cout<<(bigInt(123)-bigInt(92));
//
//
//
//   getchar();
//
//    return 0;
//}
//
//

#include <windows.h>    // для Sleep
#include <cstdio>

void draw_progress_bar(int percents) {
    int half = percents / 2;
    printf("\r [");
    for (int i = 0; i < half; ++i) putc('#', stdout);
    for (int i = 0; i < 50 - half; ++i) putc(' ', stdout);
    printf("] %3d %%", percents);
    fflush(stdout);
}

int main() {
    printf("\n");
    for (int i = 0; i <= 100; ++i) {
        draw_progress_bar(i);
        Sleep(100);
    }
    printf("\n");
}