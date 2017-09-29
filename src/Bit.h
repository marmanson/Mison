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
    string to_string();
    BitMap(vector<i64> &&bits);
    size_t length() {
        return bits.size();
    }
    const i64& operator[](size_t i) {
        return bits[i];
    }
private:
    vector<i64> bits;
};

inline i64 R(i64 x) {
    return x & (x - 1);
}

inline i64 E(i64 x) {
    return x & (-x);
}

inline i64 S(i64 x) {
    return x ^ (x - 1);
}

BitMap Building_Structural_Character_Bitmaps(const string &str, u8 ch);
}

#endif