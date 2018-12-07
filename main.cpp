#include "Blockchain.h"
#include "sha256.h"
#include <sstream>
#include <stdio.h>

#define EPOCH_20180101 1514793600


int main() {
    const string genesisLabel = "Genesis Block";
    Block genesis = Block(0, genesisLabel, EPOCH_20180101);
    Blockchain chain = Blockchain(genesis);

    cout << "Init Blockchain[ts=" << EPOCH_20180101 << "]: '" << genesisLabel << "'" << endl << endl;

    for (int i=1; i<=3; i++) {
        std::ostringstream label;
        time_t ts = EPOCH_20180101 + i;

        label << "Block #" << i << " Data";

        cout << i << ". Mining[ts=" << ts << "]: '" << label.str() << "'" << endl;

        Block block = Block(i, label.str(), ts);
        chain.addBlock(block);
    }

    return 0;
}
