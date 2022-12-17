#pragma once
// 3456789012345678901234567890123456789012345678901234

#include "../../content/geometry/Point.h"

template <class T=double>
Point<T> randIntPt(int lim) {
    return Point<T>(rand()%(lim*2) - lim, rand()%(lim*2)-lim);
}
