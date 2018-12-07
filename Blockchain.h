#ifndef TOYCHAIN_BLOCKCHAIN_H
#define TOYCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _getLastBlock() const;

public:
    Blockchain();
    Blockchain(Block bGenesis);

    void addBlock(Block bNew);

};

#endif //TOYCHAIN_BLOCKCHAIN_H
