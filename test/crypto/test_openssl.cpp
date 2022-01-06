#define BOOST_TEST_MODULE openssl
#include <boost/test/included/unit_test.hpp>

#include <fc/crypto/hex.hpp>
#include <fc/crypto/sha1.hpp>
#include <fc/exception/exception.hpp>

using namespace fc;

BOOST_AUTO_TEST_SUITE(openssl)
BOOST_AUTO_TEST_CASE(test_sha1) try {
   auto s = std::string_view("The quick brown fox jumps over the lazy dog");

   auto h1 = sha1::hash("", 0);
   auto h2 = sha1::hash(s.data(), s.size());

   BOOST_CHECK_EQUAL(h1.str(), "da39a3ee5e6b4b0d3255bfef95601890afd80709");
   BOOST_CHECK_EQUAL(h2.str(), "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12");
} FC_LOG_AND_RETHROW();

BOOST_AUTO_TEST_SUITE_END()

