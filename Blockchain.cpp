#include "Blockchain.h"

Blockchain::Blockchain(Block bGenesis) {
    _vChain.emplace_back(bGenesis);
    _nDifficulty = 5;
}

void Blockchain::addBlock(Block bNew) {
    bNew.sHashPrev = _getLastBlock().sHash;
    bNew.mine(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_getLastBlock() const {
    return _vChain.back();
}
