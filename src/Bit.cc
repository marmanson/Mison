#include <iostream>
#include <cstdio>
#include "Bit.h"

namespace meng {
BitMap::BitMap(vector<u64> &&b): bits(std::move(b)) {}

void set_full_bitmap(const string &str, int index, u8 ch, u64 &sta) {
    sta = sta | ((u64(!(str[index + 0] ^ ch))) << 63);
    sta = sta | ((u64(!(str[index + 1] ^ ch))) << 62);
    sta = sta | ((u64(!(str[index + 2] ^ ch))) << 61);
    sta = sta | ((u64(!(str[index + 3] ^ ch))) << 60);
    sta = sta | ((u64(!(str[index + 4] ^ ch))) << 59);
    sta = sta | ((u64(!(str[index + 5] ^ ch))) << 58);
    sta = sta | ((u64(!(str[index + 6] ^ ch))) << 57);
    sta = sta | ((u64(!(str[index + 7] ^ ch))) << 56);
    sta = sta | ((u64(!(str[index + 8] ^ ch))) << 55);
    sta = sta | ((u64(!(str[index + 9] ^ ch))) << 54);
    sta = sta | ((u64(!(str[index + 10] ^ ch))) << 53);
    sta = sta | ((u64(!(str[index + 11] ^ ch))) << 52);
    sta = sta | ((u64(!(str[index + 12] ^ ch))) << 51);
    sta = sta | ((u64(!(str[index + 13] ^ ch))) << 50);
    sta = sta | ((u64(!(str[index + 14] ^ ch))) << 49);
    sta = sta | ((u64(!(str[index + 15] ^ ch))) << 48);
    sta = sta | ((u64(!(str[index + 16] ^ ch))) << 47);
    sta = sta | ((u64(!(str[index + 17] ^ ch))) << 46);
    sta = sta | ((u64(!(str[index + 18] ^ ch))) << 45);
    sta = sta | ((u64(!(str[index + 19] ^ ch))) << 44);
    sta = sta | ((u64(!(str[index + 20] ^ ch))) << 43);
    sta = sta | ((u64(!(str[index + 21] ^ ch))) << 42);
    sta = sta | ((u64(!(str[index + 22] ^ ch))) << 41);
    sta = sta | ((u64(!(str[index + 23] ^ ch))) << 40);
    sta = sta | ((u64(!(str[index + 24] ^ ch))) << 39);
    sta = sta | ((u64(!(str[index + 25] ^ ch))) << 38);
    sta = sta | ((u64(!(str[index + 26] ^ ch))) << 37);
    sta = sta | ((u64(!(str[index + 27] ^ ch))) << 36);
    sta = sta | ((u64(!(str[index + 28] ^ ch))) << 35);
    sta = sta | ((u64(!(str[index + 29] ^ ch))) << 34);
    sta = sta | ((u64(!(str[index + 30] ^ ch))) << 33);
    sta = sta | ((u64(!(str[index + 31] ^ ch))) << 32);
    sta = sta | ((u64(!(str[index + 32] ^ ch))) << 31);
    sta = sta | ((u64(!(str[index + 33] ^ ch))) << 30);
    sta = sta | ((u64(!(str[index + 34] ^ ch))) << 29);
    sta = sta | ((u64(!(str[index + 35] ^ ch))) << 28);
    sta = sta | ((u64(!(str[index + 36] ^ ch))) << 27);
    sta = sta | ((u64(!(str[index + 37] ^ ch))) << 26);
    sta = sta | ((u64(!(str[index + 38] ^ ch))) << 25);
    sta = sta | ((u64(!(str[index + 39] ^ ch))) << 24);
    sta = sta | ((u64(!(str[index + 40] ^ ch))) << 23);
    sta = sta | ((u64(!(str[index + 41] ^ ch))) << 22);
    sta = sta | ((u64(!(str[index + 42] ^ ch))) << 21);
    sta = sta | ((u64(!(str[index + 43] ^ ch))) << 20);
    sta = sta | ((u64(!(str[index + 44] ^ ch))) << 19);
    sta = sta | ((u64(!(str[index + 45] ^ ch))) << 18);
    sta = sta | ((u64(!(str[index + 46] ^ ch))) << 17);
    sta = sta | ((u64(!(str[index + 47] ^ ch))) << 16);
    sta = sta | ((u64(!(str[index + 48] ^ ch))) << 15);
    sta = sta | ((u64(!(str[index + 49] ^ ch))) << 14);
    sta = sta | ((u64(!(str[index + 50] ^ ch))) << 13);
    sta = sta | ((u64(!(str[index + 51] ^ ch))) << 12);
    sta = sta | ((u64(!(str[index + 52] ^ ch))) << 11);
    sta = sta | ((u64(!(str[index + 53] ^ ch))) << 10);
    sta = sta | ((u64(!(str[index + 54] ^ ch))) << 9);
    sta = sta | ((u64(!(str[index + 55] ^ ch))) << 8);
    sta = sta | ((u64(!(str[index + 56] ^ ch))) << 7);
    sta = sta | ((u64(!(str[index + 57] ^ ch))) << 6);
    sta = sta | ((u64(!(str[index + 58] ^ ch))) << 5);
    sta = sta | ((u64(!(str[index + 59] ^ ch))) << 4);
    sta = sta | ((u64(!(str[index + 60] ^ ch))) << 3);
    sta = sta | ((u64(!(str[index + 61] ^ ch))) << 2);
    sta = sta | ((u64(!(str[index + 62] ^ ch))) << 1);
    sta = sta | ((u64(!(str[index + 63] ^ ch))) << 0);    
}

void set_part_bitmap(const string &str, int index, u8 ch, u64 &sta) {
    for(int i=index; i<str.length(); i++) {
        sta = sta | (((u64(!(str[i] ^ ch))) << (63 - i + index)));
    }
}

BitMap Building_Character_Bitmaps(const string &str, u8 ch) {
    int len = str.length() / 64 + (str.length() % 64 == 0? 0:1);
    vector<u64> v(len, 0);
    for(int i=0, j=0; i<str.length()/64; i++, j+=64) {
        set_full_bitmap(str, j, ch, v[i]);
    }
    
    set_part_bitmap(str, str.length()/64 *64, ch, v[len-1]);
    BitMap bits(std::move(v));
    return bits;
}

}