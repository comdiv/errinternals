#pragma once

#define NULL 0

#ifndef ERR_ARITH_ERROR
// потенциальная пробема - код ошибки у нас тут свой, хотя и "ненавязчивый"
#define ERR_ARITH_ERROR 3
#endif

#ifndef ERR_OUT_VARIABLE
// типа повзоляем перекрыть дефолт
#define ERR_OUT_VARIABLE err
#endif

#define ZCHECKED(EXPR) ((ERR_OUT_VARIABLE) == NULL ? 0 : *(ERR_OUT_VARIABLE) = 0) | (EXPR)
#define ZDIV(X, Y) ((Y) == 0 ? ((((ERR_OUT_VARIABLE) == NULL ? *(ERR_OUT_VARIABLE) = ERR_ARITH_ERROR : 0) & 0) | -1) : (X) / (Y))