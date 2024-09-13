#include <stdio.h>
#include<stdlib.h>

int main() {
    int s_obj = 0;
    int* h_obj = (int*)malloc(sizeof(int));
    int s_obj2 = 0;
    int* h_obj2 = (int*)malloc(sizeof(int));
    printf("%p\n%p\n", &s_obj, h_obj);
    printf("%p\n%p\n", &s_obj2, h_obj2);
    printf("%p\n%p\n", main, printf);
}