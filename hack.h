#pragma once

typedef int Err;
typedef struct IntResult {
    int r;  Err err;
} IntResult;

typedef struct VoidResult{
    Err err;
}VoidResult;

#define NO_ERROR_CODE 0
#define NO_ERROR_RESULT (VoidResult){NO_ERROR_CODE}

#define INT_OR_ERR(cond,eval,defval,errcode) ((cond) ? (IntResult){(eval),NO_ERROR_CODE} : (IntResult){(defval),(errcode)})
#define APPLY_INT_OR_ERR(err, trg, value) { IntResult tmp = (value); err |= ((tmp.err == NO_ERROR_CODE) ? ((trg = tmp.r) & 0) : tmp.err); } 

#define unwrapValueOrError(target, vres) { IntResult tmp = (vres); int it = tmp.r; if(tmp.err != NO_ERROR_CODE) {return (VoidResult){tmp.err};} else { (target) = tmp.r; } } 
#define unwrapOrError(res) { VoidResult tmp = (res);  if(tmp.err != NO_ERROR_CODE) {return tmp;} } 

#define isSuccess(value) ((value).err == NO_ERROR_CODE)
#define isError(value) ((value).err != NO_ERROR_CODE)
#define panic(value) {printf("Error! Read manual, error code: %d\n", value.err); exit(value.err);}

#define unwrapOrPanic(res) { VoidResult tmp = (res);  if(isError(tmp)) { panic(tmp); } } 