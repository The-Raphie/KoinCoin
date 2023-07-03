#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include "include/cryptlib.h"
#include "include/hex.h"
#include "include/files.h"
#include "include/sha.h"
// #include "cryptopp-8.8.0/
// #include "cryptopp-8.8.0/filters.h"
// #include "cryptopp-8.8.0/files.h"
// #include "cryptopp-8.8.0/sha.h"
// #include "cryptopp/modes.h"
// #include "cryptopp/filters.h"
// #include "cryptopp/files.h"
// #include "cryptopp/hex.h"
// #include "cryptopp/sha.h"
// #include "cryptopp/hmac.h"
// #include "cryptopp/filters.h"
// #include "cryptopp/aes.h"
// #include "cryptopp/modes.h"
// #include "cryptopp/base64.h"

// using namespace std;
using namespace std::chrono;
using namespace CryptoPP;

struct block {
    std::string hash;
    std::string previous_hash;
    int block_number;
};

std::vector< block > blockchain;

int HASH_SYMBOLS_SIZE = 36;
char hash_symbols[36] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
int HASH_SIZE = 64;

int main() {
    int counter = -1;
    while (true) {
        double transfer_amount;
        std::cin >> transfer_amount;

        auto wait_time = seconds(2);
        
        std::this_thread::sleep_for(wait_time);
        block new_block;

        srand((unsigned) time(NULL));

        counter++;

        new_block.block_number = counter;
        new_block.hash = "";
        new_block.previous_hash = "0";
        if (blockchain.size() > 0) {
            new_block.previous_hash = blockchain[new_block.block_number - 1].hash;
        }

        for(int i = 0; i < HASH_SIZE; i++) {
            new_block.hash = new_block.hash + hash_symbols[rand() % 36];
        }
        // cout << new_block.hash;
        blockchain.push_back(new_block); //adds a new block

        for(int i = blockchain.size() - 1; i < blockchain.size(); i++) {
            std::cout << "Hash: " << blockchain[i].hash << std::endl;
            std::cout << "Previous Hash: " << blockchain[i].previous_hash << std::endl;
        }

        // std::string message = "e";

        // HexEncoder encoder(new FileSink(std::cout));

        // std::string msg = "Yoda said, Do or do not. There is no try.";
        // std::string digest;

        SHA256 hash;
        // hash.Update((const byte*)msg.data(), msg.size());
        // digest.resize(hash.DigestSize());
        // hash.Final((byte*)&digest[0]);

        // std::cout << "Message: " << msg << std::endl;

        // std::cout << "Digest: ";
        // // StringSource(digest, true, new Redirector(encoder));
        // std::cout << std::endl;

        // cout << "SHA256: " << string((char*)abDigest) << endl;
    }
}//undefined reference to `vtable for CryptoPP::FileSink'