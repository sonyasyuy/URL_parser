#include "parse_url.h"


URLParser::URLParser(const std::string &url) {
    url_ = url;
    parseURL();
}

std::string URLParser::getProtocol() const {
    return protocol_;
}

std::string URLParser::getUsername() const {
    return username_;
}

std::string URLParser::getPassword() const {
    return password_;
}

std::string URLParser::getHost() const {
    return host_;
}

std::string URLParser::getHostName() const {
    return hostname_;
}

std::string URLParser::getPort() const {
    return port_;
}

std::string URLParser::getPath() const {
    return path_;
}

std::string URLParser::getQuery() const {
    return query_;
}

std::string URLParser::getHash() const {
    return hash_;
}


void URLParser::parseURL() {
    // Парсинг протокола
    size_t protocolEnd = url_.find("://");
    if (protocolEnd != std::string::npos) {
        protocol_ = url_.substr(0, protocolEnd);
        url_ = url_.substr(protocolEnd + 3);
    }

    // Парсинг username password
    size_t at = url_.find('@');
    if (at != std::string::npos) {
        std::string username_password = url_.substr(0, at);
        size_t colon = username_password.find(':');
        username_ = url_.substr(0, colon);
        username_password = username_password.substr(colon + 1);
        password_ = username_password.substr(0);
        url_ = url_.substr(at + 1);
    } else {
        username_ = "";
        password_ = "";
    }

    // Парсинг хэша
    size_t hashStart = url_.find('#');
    if (hashStart != std::string::npos) {
        hash_ = url_.substr(hashStart + 1);
        url_ = url_.substr(0, hashStart);
    }

    // Парсинг запроса
    size_t queryStart = url_.find('?');
    if (queryStart != std::string::npos) {
        query_ = url_.substr(queryStart + 1);
        url_ = url_.substr(0, queryStart);
    }

    // Парсинг пути
    size_t pathStart = url_.find('/');
    if (pathStart != std::string::npos) {
        host_ = url_.substr(0, pathStart);
        size_t host_colon = host_.find(':');
        if (host_colon != std::string::npos) {
            hostname_ = host_.substr(0, host_colon);
            port_ = host_.substr(host_colon + 1);
        } else {
            hostname_ = host_;
        }
        path_ = url_.substr(pathStart);
    } else {
        host_ = url_;
    }

}



