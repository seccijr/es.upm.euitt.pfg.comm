#ifndef _URLPARSERTEST_H
#define _URLPARSERTEST_H

#include "Arduino.h"
#include "ArduinoUnit.h"

namespace Comm {
    class UrlParserTest: public TestOnce {
        public:
            UrlParserTest(const char *name): TestOnce(name) {
                verbosity = TEST_VERBOSITY_ALL;
            }
            void setup();
            void once();
        private:
            void TestCheckUrlFormat(const String &url);
            void TestIsSchemaValid(const String &scheme);
            void TestParseScheme(const String &url, const String &scheme);
            void TestParseLocation(const String &url, const String &location);
            void TestParseUsername(const String &url, const String &user, const String &password);
            String scheme_;
            String user_;
            String password_;
            String host_;
            String location_;
            String path_;
            String query_;
            String fragment_;
            String url_;
    };
}

#endif
