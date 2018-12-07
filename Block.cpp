#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIdxIn, const string &sDataIn, time_t tTimestampIn) : _nIdx(nIdxIn), _sData(sDataIn), _tTime(tTimestampIn) {
    _nNonce = 0;
    sHash = _hash();
}

Block::Block(uint32_t nIdxIn, const string &sDataIn) : Block(nIdxIn, sDataIn, time(nullptr)) {}

void Block::mine(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i=0; i<nDifficulty; i++) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);

    while (sHash.substr(0, nDifficulty) != str) {
        _nNonce++;
        sHash = _hash();
    }

    cout << "Block mined: " << sHash << endl;
}

inline string Block::_hash() const {
    SHA256 sha256;
    stringstream ss;
    ss << _nIdx << sHashPrev << _tTime << _sData << _nNonce;

    return sha256(ss.str());
}
