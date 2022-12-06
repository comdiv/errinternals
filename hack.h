#pragma once

#include <setjmp.h>


#define TRY_STACK_SIZE 20
#define BEGIN_TRY_OK 0
#define BEGIN_TRY_OVERFLOW -1 
#define BEGIN_TRY_INVALID_STATE -2
#define ERROR_CODE __error_code

jmp_buf* nextJump();
jmp_buf* unwindJump();
int isCatching();
void panic(int errorCode);



#define BEGIN_TRY { int ERROR_CODE = 0; int CATCHED =0; if( !(ERROR_CODE = setjmp(*(nextJump()))) ){
#define CATCH(err)} else if (ERROR_CODE == err) { CATCHED = 1;
#define CATCH_ANY } else { CATCHED = 1; 
#define END_TRY  } if(ERROR_CODE !=0 && CATCHED == 0) { panic(ERROR_CODE); }  };
#define THROW(err) if(isCatching()) { longjmp(*(unwindJump()), err); } else { panic(err); } ; return (void*)0;