#pragma once
#include <string>

class URLParser {
public:
    explicit URLParser(const std::string &url);
    [[nodiscard]] std::string getProtocol() const;

    [[nodiscard]] std::string getHost() const;

    [[nodiscard]] std::string getPath() const;

    [[nodiscard]] std::string getQuery() const;

    [[nodiscard]] std::string getHash() const;

    [[nodiscard]] std::string getUsername() const;

    [[nodiscard]] std::string getPassword() const;

    [[nodiscard]] std::string getHostName() const;

    [[nodiscard]] std::string getPort() const;

private:
    void parseURL();


    std::string url_;
    std::string protocol_;
    std::string username_;
    std::string password_;
    std::string host_;
    std::string hostname_;
    std::string port_;
    std::string path_;
    std::string query_;
    std::string hash_;

};

