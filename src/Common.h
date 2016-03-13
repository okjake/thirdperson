#ifndef thirdperson_common_h
#define thirdperson_common_h

#include "BaseOutput.h"

enum SWEETSPOT_SECTOR {
    SECTOR_LEFT,
    SECTOR_RIGHT
};

struct OutputPair {
    BaseOutput *one;
    BaseOutput *two;
};

struct ValuePair {
    short one;
    short two;
};

struct LRPair {
    unsigned int left;
    unsigned int right;
};

#endif
