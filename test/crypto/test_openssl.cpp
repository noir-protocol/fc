#define BOOST_TEST_MODULE openssl
#include <boost/test/included/unit_test.hpp>

#include <fc/crypto/hex.hpp>
#include <fc/crypto/ripemd160.hpp>
#include <fc/crypto/sha1.hpp>
#include <fc/crypto/sha224.hpp>
#include <fc/crypto/sha256.hpp>
#include <fc/crypto/sha512.hpp>
#include <fc/exception/exception.hpp>

using namespace fc;

auto s = std::string_view("The quick brown fox jumps over the lazy dog");

BOOST_AUTO_TEST_SUITE(openssl)
BOOST_AUTO_TEST_CASE(test_sha1) try {
   auto h1 = sha1::hash("", 0);
   auto h2 = sha1::hash(s.data(), s.size());

   BOOST_CHECK_EQUAL(h1.str(), "da39a3ee5e6b4b0d3255bfef95601890afd80709");
   BOOST_CHECK_EQUAL(h2.str(), "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12");
} FC_LOG_AND_RETHROW();

BOOST_AUTO_TEST_CASE(test_sha224) try {
   auto h1 = sha224::hash("", 0);
   auto h2 = sha224::hash(s.data(), s.size());

   BOOST_CHECK_EQUAL(h1.str(), "d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f");
   BOOST_CHECK_EQUAL(h2.str(), "730e109bd7a8a32b1cb9d9a09aa2325d2430587ddbc0c38bad911525");
} FC_LOG_AND_RETHROW();

BOOST_AUTO_TEST_CASE(test_sha256) try {
   auto h1 = sha256::hash("", 0);
   auto h2 = sha256::hash(s.data(), s.size());

   BOOST_CHECK_EQUAL(h1.str(), "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
   BOOST_CHECK_EQUAL(h2.str(), "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592");
} FC_LOG_AND_RETHROW();

BOOST_AUTO_TEST_CASE(test_sha512) try {
   auto h1 = sha512::hash("", 0);
   auto h2 = sha512::hash(s.data(), s.size());

   BOOST_CHECK_EQUAL(h1.str(), "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e");
   BOOST_CHECK_EQUAL(h2.str(), "07e547d9586f6a73f73fbac0435ed76951218fb7d0c8d788a309d785436bbb642e93a252a954f23912547d1e8a3b5ed6e1bfd7097821233fa0538f3db854fee6");
} FC_LOG_AND_RETHROW();

BOOST_AUTO_TEST_CASE(test_ripemd160) try {
   auto h1 = ripemd160::hash("", 0);
   auto h2 = ripemd160::hash(s.data(), s.size());

   BOOST_CHECK_EQUAL(h1.str(), "9c1185a5c5e9fc54612808977ee8f548b2258d31");
   BOOST_CHECK_EQUAL(h2.str(), "37f332f68db77bd9d7edd4969571ad671cf9dd3b");
} FC_LOG_AND_RETHROW();

BOOST_AUTO_TEST_SUITE_END()

