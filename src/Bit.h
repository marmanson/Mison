#ifndef MISON_SRC_BIT_H
#define MISON_SRC_BIT_H

#include <string>
#include <vector>
#include <memory>
#include "type.h"
#include <string>

namespace meng {
using std::string;
using std::shared_ptr;
using std::move;
using std::vector;
class BitMap {
public:
    BitMap(vector<u64> &&bits);
    size_t length() {
        return bits.size();
    }
    const u64& operator[](size_t i) {
        return bits[i];
    }
private:
    vector<u64> bits;
};

inline u64 R(u64 x) {
    return x & (x - 1);
}

inline u64 E(u64 x) {
    return x & (-x);
}

inline u64 S(u64 x) {
    return x ^ (x - 1);
}

BitMap Building_Character_Bitmaps(const string &str, u8 ch);
}

#endif