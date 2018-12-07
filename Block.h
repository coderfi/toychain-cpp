#ifndef TOYCHAIN_BLOCK_H
#define TOYCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block {
private:
    string _sData;
    uint32_t _nIdx;
    uint32_t _nNonce;
    time_t _tTime;

    string _hash() const;

public:
    string sHash;
    string sHashPrev;

    Block(uint32_t nIdxIn, const string &sDataIn, time_t tTimestampIn);
    Block(uint32_t nIdxIn, const string &sDataIn);

    void mine(uint32_t nDifficulty);
};

#endif //TOYCHAIN_BLOCK_H
