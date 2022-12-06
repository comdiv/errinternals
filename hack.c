#include <setjmp.h>
#include "hack.h"
#include <stdio.h>
#include <stdlib.h>

jmp_buf  __global_try_stack[TRY_STACK_SIZE];
int __jump_buf_index = -1;

jmp_buf* nextJump() {
     __jump_buf_index++;
     return &(__global_try_stack[__jump_buf_index]);
}


jmp_buf* unwindJump() {
     if(__jump_buf_index >= 0)  {
        __jump_buf_index--;
        return  &(__global_try_stack[__jump_buf_index+1]);
     }
     return (jmp_buf*)0;
}


int isCatching() { return __jump_buf_index >= 0; }

void panic(int errorCode) {
    fprintf(stderr,"Panic! Uncatched error with code: %d!\n", errorCode);
    exit(errorCode);
}




