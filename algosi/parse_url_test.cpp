#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "parse_url.h"

TEST_CASE("URL Parsing_1", "TEST1") {
    SECTION("HTTP URL") {
        URLParser parser("http://www.example.com/path");
        REQUIRE(parser.getProtocol() == "http");
        REQUIRE(parser.getHost() == "www.example.com");
        REQUIRE(parser.getPath() == "/path");
        REQUIRE(parser.getUsername().empty());
        REQUIRE(parser.getPassword().empty());
        REQUIRE(parser.getHostName() == "www.example.com");
        REQUIRE(parser.getPort().empty());
        REQUIRE(parser.getQuery().empty());
        REQUIRE(parser.getHash().empty());
    }

    SECTION("HTTPS URL with port") {
        URLParser parser("https://www.example.com:8080/path");
        REQUIRE(parser.getProtocol() == "https");
        REQUIRE(parser.getHost() == "www.example.com:8080");
        REQUIRE(parser.getHostName() == "www.example.com");
        REQUIRE(parser.getPort() == "8080");
        REQUIRE(parser.getPath() == "/path");
        REQUIRE(parser.getUsername().empty());
        REQUIRE(parser.getPassword().empty());
        REQUIRE(parser.getQuery().empty());
        REQUIRE(parser.getHash().empty());
    }

    SECTION("HTTPS URL with query and hash") {
        URLParser parser("https://www.example.com/path/to/resource?query=123#fragment");
        REQUIRE(parser.getProtocol() == "https");
        REQUIRE(parser.getHost() == "www.example.com");
        REQUIRE(parser.getHostName() == "www.example.com");
        REQUIRE(parser.getPort().empty());
        REQUIRE(parser.getPath() == "/path/to/resource");
        REQUIRE(parser.getQuery() == "query=123");
        REQUIRE(parser.getHash() == "fragment");
        REQUIRE(parser.getUsername().empty());
        REQUIRE(parser.getPassword().empty());
    }

    SECTION("FTP URL with username and password") {
        URLParser parser("ftp://username:password@ftp.example.com/path/to/file");
        REQUIRE(parser.getProtocol() == "ftp");
        REQUIRE(parser.getUsername() == "username");
        REQUIRE(parser.getPassword() == "password");
        REQUIRE(parser.getHost() == "ftp.example.com");
        REQUIRE(parser.getPath() == "/path/to/file");
        REQUIRE(parser.getQuery().empty());
    }
}

TEST_CASE("URL Parsing_2", "TEST2") {
    SECTION("URL Kinopoisk") {
        URLParser parser("https://www.kinopoisk.ru/series/464963/");
        REQUIRE(parser.getProtocol() == "https");
        REQUIRE(parser.getHost() == "www.kinopoisk.ru");
        REQUIRE(parser.getHostName() == "www.kinopoisk.ru");
        REQUIRE(parser.getPort().empty());
        REQUIRE(parser.getPath() == "/series/464963/");
        REQUIRE(parser.getUsername().empty());
        REQUIRE(parser.getPassword().empty());
        REQUIRE(parser.getQuery().empty());
        REQUIRE(parser.getHash().empty());
    }

    SECTION("URL Glassdoor"){
        URLParser parser("https://www.glassdoor.com/Overview/Working-at-Amazon-EI_IE6036.11,17.htm");
        REQUIRE(parser.getProtocol() == "https");
        REQUIRE(parser.getHost() == "www.glassdoor.com");
        REQUIRE(parser.getHostName() == "www.glassdoor.com");
        REQUIRE(parser.getPort().empty());
        REQUIRE(parser.getPath() == "/Overview/Working-at-Amazon-EI_IE6036.11,17.htm");
        REQUIRE(parser.getUsername().empty());
        REQUIRE(parser.getPassword().empty());
        REQUIRE(parser.getQuery().empty());
        REQUIRE(parser.getHash().empty());
    }
    SECTION("URL query"){
        URLParser parser("http://www.example.com:30/product-7298?color=blue&size=L&material=cotton&discount=true&shipping=express&seller=companyX&brand=brandZ&rating=4.5");
        REQUIRE(parser.getProtocol() == "http");
        REQUIRE(parser.getHost() == "www.example.com:30");
        REQUIRE(parser.getHostName() == "www.example.com");
        REQUIRE(parser.getPort() == "30");
        REQUIRE(parser.getPath() == "/product-7298");
        REQUIRE(parser.getUsername().empty());
        REQUIRE(parser.getPassword().empty());
        REQUIRE(parser.getQuery() == "color=blue&size=L&material=cotton&discount=true&shipping=express&seller=companyX&brand=brandZ&rating=4.5");
        REQUIRE(parser.getHash().empty());
    }
}
