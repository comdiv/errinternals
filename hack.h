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


// а тут мы поняли что нам не нужен и вреден ZCHECKED так как из-за сброса состояний - посленее выражение перетерло бы
#define ZDIV(X, Y) ((Y) == 0 ? (((ERR_OUT_VARIABLE != NULL ? (*ERR_OUT_VARIABLE |= ERR_ARITH_ERROR) : 0) & 0) | -1) : (X) / (Y))