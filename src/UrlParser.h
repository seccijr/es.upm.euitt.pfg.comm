#ifndef _URLPARSER_H
#define _URLPARSER_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

namespace UrlParser {
    enum UrlParserError {
        kOk = 0,
        kUninitialized = 1,
        kInvalidFormat = 2,
        kInvalidSchemeName = 3
    };

    class ParseUrlClass {
        public:
            static ParseUrlClass ParseUrl(const String& url);
            ParseUrlClass() : error_code_(kUninitialized) {};
            explicit ParseUrlClass(UrlParserError error_code) : error_code_(error_code) {};
            bool IsValid() const {
                return error_code_ == kOk;
            }
            String get_scheme() {
                return scheme_;
            };
            void set_scheme(String scheme) {
                scheme_ = scheme;
            };
            String get_host() {
                return host_;
            };
            void set_host(String host) {
                host_ = host;
            };
            int get_port() {
                return port_;
            };
            void set_port(int port) {
                port_ = port;
            };
            String get_path() {
                return path_;
            };
            void set_path(String path) {
                path_ = path;
            };
            String get_query() {
                return query_;
            };
            void set_query(String query) {
                query_ = query;
            };
            String get_fragment() {
                return fragment_;
            };
            void set_fragment(String fragment) {
                fragment_ = fragment;
            };
            String get_user_name() {
                return user_name_;
            };
            void set_user_name(String user_name) {
                user_name_ = user_name;
            };
            String get_password() {
                return password_;
            };
            void set_password(String password) {
                password_ = password;
            };
        private:
            UrlParserError error_code_;
            String scheme_;
            String host_;
            int port_;
            String path_;
            String query_;
            String fragment_;
            String user_name_;
            String password_;
    };
};

#endif
