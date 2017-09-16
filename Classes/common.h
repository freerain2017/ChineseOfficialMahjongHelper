﻿#ifndef __COMMON_H__
#define __COMMON_H__

#include "cocos2d.h"
#include "compiler.h"

namespace Common {

static inline void scaleLabelToFitWidth(cocos2d::Label *label, float width) {
    const cocos2d::Size &size = label->getContentSize();
    if (size.width > width) {
        float s = width / size.width;
        label->setScale(s);
    }
    else {
        label->setScale(1.0f);
    }
}

static inline bool isCStringEmpty(const char *str) {
    return *str == '\0';
}

template <size_t BufferSize>
static std::string format(const char *fmt, ...) FORMAT_CHECK_PRINTF(1, 2);

template <size_t BufferSize>
inline std::string format(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    char buf[BufferSize];
    vsnprintf(buf, BufferSize, fmt, ap);
    va_end(ap);

    return buf;
}

}

#endif
