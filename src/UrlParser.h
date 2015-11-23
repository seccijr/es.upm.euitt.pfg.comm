#ifndef _URLPARSER_H
#define _URLPARSER_H

#include <Arduino.h>

bool CheckUrlFormat(const String &url);
bool IsSchemeValid(const String &scheme);
String ParseScheme(const String &url);
String ParseLocation(const String &url);
int ParseUserName(const String &url, String result[], int size);
String ParseTCP(const String &url);
String ParseHost(const String &url);
int ParsePort(const String &url);
String ParsePath(const String &url);
String ParseFragment(const String &url);
String ParseQuery(const String &url);

namespace Comm {
    class UrlParserClass {
        public:
            static UrlParserClass Parse(const String& url);
            UrlParserClass() : ok(0) {};
            explicit UrlParserClass(int ok) : ok(ok) {};
            int ok;
            String scheme;
            String host;
            int port;
            String path;
            String query;
            String fragment;
            String user;
            String password;
    };
};

#endif
