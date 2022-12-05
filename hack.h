#pragma once

typedef int Err;
typedef struct IntOrErr {
    int r;  Err err;
} IntOrErr;

#define NO_ERROR 0

#define INT_OR_ERR(cond,eval,defval,errcode) ((cond) ? (IntOrErr){(eval),NO_ERROR} : (IntOrErr){(defval),(errcode)})
#define APPLY_INT_OR_ERR(err, trg, value) { IntOrErr tmp = (value); err |= ((tmp.err == NO_ERROR) ? ((trg = tmp.r) & 0) : tmp.err); } 