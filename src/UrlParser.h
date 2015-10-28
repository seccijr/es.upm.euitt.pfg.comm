#ifndef _URLPARSER_H
#define _URLPARSER_H

#include "Arduino.h"

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
            UrlParserClass() : ok_(0) {};
            explicit UrlParserClass(int ok) : ok_(ok) {};
            int ok_;
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
