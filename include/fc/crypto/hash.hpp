#pragma once
#include <openssl/evp.h>
#include <cstdint>

namespace fc { namespace hash {

template<typename T>
class encoder {
public:
  encoder(): ctx(EVP_MD_CTX_new()) {
    reset();
  }
  ~encoder() {
    EVP_MD_CTX_free(ctx);
  }

  void write(const char* d, uint32_t dlen) {
    EVP_DigestUpdate(ctx, d, dlen);
  }
  void put(char c) {
    write(&c, 1);
  }
  void reset() {
    EVP_DigestInit(ctx, type);
  }
  T result() {
    T h;
    EVP_DigestFinal(ctx, (uint8_t*)h.data(), nullptr);
    return h;
  }

  static const EVP_MD* type;

private:
  EVP_MD_CTX* ctx;
};

}} // namespace fc::hash
