#ifndef SHADOWSOCKS_ASIO_ENCRYPT_H
#define SHADOWSOCKS_ASIO_ENCRYPT_H

#include "utils.h"


std::string pbkdf2(std::string password);

class BaseDecEncrypter {
public:
    virtual ~BaseDecEncrypter() = default;
    virtual void encrypt(char *dst, std::size_t dlen, char *src, std::size_t slen) = 0;
    virtual void decrypt(char *dst, std::size_t dlen, char *src, std::size_t slen) = 0;
};

std::unique_ptr<BaseDecEncrypter> getDecEncrypter(const std::string &method,
                                            const std::string &pwd);

void put_random_bytes(char *buffer, std::size_t length);

#endif // SHADOWSOCKS_ASIO_ENCRYPT_H
