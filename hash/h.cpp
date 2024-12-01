#include <iostream>
#include <string>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

using namespace std;

std::string sha224(const string& filePath) {
    using namespace CryptoPP;
    SHA224 hash;
    string new_hash;
//FileSource читает содержимое файла и передает его в цепочку фильтров, которые вычисляют хэш и кодируют его в шестнадцатеричный формат.
    FileSource file(filePath.c_str(), true, new HashFilter(hash, new HexEncoder(new StringSink(new_hash))));
    return new_hash;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <путь_к_файлу>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    std::string hash = sha224(filePath);

    if (!hash.empty()) {
        std::cout << "Хэш файла " << filePath << ": " << hash << std::endl;
    }

    return 0;
}
