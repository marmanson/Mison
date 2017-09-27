#include <iostream>
#include <cstdio>
#include "Bit.h"

namespace meng {
BitMap::BitMap(vector<i64> &&b): bits(std::move(b)) {}
string BitMap::to_string() {
    string res = "";
    for(auto item : bits) {
        for(int i=0; i<64; i++) {
            if(item&1) res += '1';
            else res += '0';
            item >>= 1;
        }
    }
    return res;
}

i64 set_full_bitmap(const string &str, int index, u8 ch, i64 &sta) {
    sta = sta | ((i64(!(str[index + 0] ^ ch))) << 0);
    sta = sta | ((i64(!(str[index + 1] ^ ch))) << 1);
    sta = sta | ((i64(!(str[index + 2] ^ ch))) << 2);
    sta = sta | ((i64(!(str[index + 3] ^ ch))) << 3);
    sta = sta | ((i64(!(str[index + 4] ^ ch))) << 4);
    sta = sta | ((i64(!(str[index + 5] ^ ch))) << 5);
    sta = sta | ((i64(!(str[index + 6] ^ ch))) << 6);
    sta = sta | ((i64(!(str[index + 7] ^ ch))) << 7);
    sta = sta | ((i64(!(str[index + 8] ^ ch))) << 8);
    sta = sta | ((i64(!(str[index + 9] ^ ch))) << 9);
    sta = sta | ((i64(!(str[index + 10] ^ ch))) << 10);
    sta = sta | ((i64(!(str[index + 11] ^ ch))) << 11);
    sta = sta | ((i64(!(str[index + 12] ^ ch))) << 12);
    sta = sta | ((i64(!(str[index + 13] ^ ch))) << 13);
    sta = sta | ((i64(!(str[index + 14] ^ ch))) << 14);
    sta = sta | ((i64(!(str[index + 15] ^ ch))) << 15);
    sta = sta | ((i64(!(str[index + 16] ^ ch))) << 16);
    sta = sta | ((i64(!(str[index + 17] ^ ch))) << 17);
    sta = sta | ((i64(!(str[index + 18] ^ ch))) << 18);
    sta = sta | ((i64(!(str[index + 19] ^ ch))) << 19);
    sta = sta | ((i64(!(str[index + 20] ^ ch))) << 20);
    sta = sta | ((i64(!(str[index + 21] ^ ch))) << 21);
    sta = sta | ((i64(!(str[index + 22] ^ ch))) << 22);
    sta = sta | ((i64(!(str[index + 23] ^ ch))) << 23);
    sta = sta | ((i64(!(str[index + 24] ^ ch))) << 24);
    sta = sta | ((i64(!(str[index + 25] ^ ch))) << 25);
    sta = sta | ((i64(!(str[index + 26] ^ ch))) << 26);
    sta = sta | ((i64(!(str[index + 27] ^ ch))) << 27);
    sta = sta | ((i64(!(str[index + 28] ^ ch))) << 28);
    sta = sta | ((i64(!(str[index + 29] ^ ch))) << 29);
    sta = sta | ((i64(!(str[index + 30] ^ ch))) << 30);
    sta = sta | ((i64(!(str[index + 31] ^ ch))) << 31);
    sta = sta | ((i64(!(str[index + 32] ^ ch))) << 32);
    sta = sta | ((i64(!(str[index + 33] ^ ch))) << 33);
    sta = sta | ((i64(!(str[index + 34] ^ ch))) << 34);
    sta = sta | ((i64(!(str[index + 35] ^ ch))) << 35);
    sta = sta | ((i64(!(str[index + 36] ^ ch))) << 36);
    sta = sta | ((i64(!(str[index + 37] ^ ch))) << 37);
    sta = sta | ((i64(!(str[index + 38] ^ ch))) << 38);
    sta = sta | ((i64(!(str[index + 39] ^ ch))) << 39);
    sta = sta | ((i64(!(str[index + 40] ^ ch))) << 40);
    sta = sta | ((i64(!(str[index + 41] ^ ch))) << 41);
    sta = sta | ((i64(!(str[index + 42] ^ ch))) << 42);
    sta = sta | ((i64(!(str[index + 43] ^ ch))) << 43);
    sta = sta | ((i64(!(str[index + 44] ^ ch))) << 44);
    sta = sta | ((i64(!(str[index + 45] ^ ch))) << 45);
    sta = sta | ((i64(!(str[index + 46] ^ ch))) << 46);
    sta = sta | ((i64(!(str[index + 47] ^ ch))) << 47);
    sta = sta | ((i64(!(str[index + 48] ^ ch))) << 48);
    sta = sta | ((i64(!(str[index + 49] ^ ch))) << 49);
    sta = sta | ((i64(!(str[index + 50] ^ ch))) << 50);
    sta = sta | ((i64(!(str[index + 51] ^ ch))) << 51);
    sta = sta | ((i64(!(str[index + 52] ^ ch))) << 52);
    sta = sta | ((i64(!(str[index + 53] ^ ch))) << 53);
    sta = sta | ((i64(!(str[index + 54] ^ ch))) << 54);
    sta = sta | ((i64(!(str[index + 55] ^ ch))) << 55);
    sta = sta | ((i64(!(str[index + 56] ^ ch))) << 56);
    sta = sta | ((i64(!(str[index + 57] ^ ch))) << 57);
    sta = sta | ((i64(!(str[index + 58] ^ ch))) << 58);
    sta = sta | ((i64(!(str[index + 59] ^ ch))) << 59);
    sta = sta | ((i64(!(str[index + 60] ^ ch))) << 60);
    sta = sta | ((i64(!(str[index + 61] ^ ch))) << 61);
    sta = sta | ((i64(!(str[index + 62] ^ ch))) << 62);
    sta = sta | ((i64(!(str[index + 63] ^ ch))) << 63);
    return sta;
}

i64 set_part_bitmap(const string &str, int index, u8 ch, i64 &sta) {
    for(int i=index; i<str.length(); i++) {
        sta = sta | (((i64(!(str[i] ^ ch))) << (i - index)));
    }
    return sta;
}

BitMap Building_Structural_Character_Bitmaps(const string &str, u8 ch) {
    int len = str.length() / 64 + (str.length() % 64 == 0? 0:1);
    vector<i64> v(len, 0);
    for(int i=0, j=0; i<str.length()/64; i++, j+=64) {
        set_full_bitmap(str, j, ch, v[i]);
    }
    
    set_part_bitmap(str, str.length()/64 *64, ch, v[len-1]);
    BitMap bits(std::move(v));
    return bits;
}

}