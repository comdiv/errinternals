#pragma once
#ifndef HACK_HEADER
#define HACK_HEADER

#include <errno.h>

#ifndef ERR_ARITH_ERROR
// потенциальная пробема - код ошибки у нас тут свой, хотя и "ненавязчивый"
#define ERR_ARITH_ERROR 3
#endif

#ifndef ERR_OUT_VARIABLE
// типа повзоляем перекрыть дефолт
#define ERR_OUT_VARIABLE errno
#endif

#define ZCHECKED(EXPR) (ERR_OUT_VARIABLE = 0) | (EXPR)
#define ZDIV(X, Y) ((Y) == 0 ? (((ERR_OUT_VARIABLE = ERR_ARITH_ERROR) & 0) | -1 ): (X) / (Y))

#endif