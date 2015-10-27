#include "UrlParserTest.h"
#include "src/UrlParser.h"

void Comm::UrlParserTest::TestCheckUrlFormat(const String &url) {
    bool checked = CheckUrlFormat(url);
    if (checked) {
        pass();
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestIsSchemaValid(const String &scheme) {
    bool valid = IsSchemeValid(scheme);
    if (valid) {
        pass();
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseScheme(const String &url, const String &scheme) {
    String test_scheme = ParseScheme(url);
    if (test_scheme) {
        assertEqual(test_scheme, scheme);
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseLocation(const String &url, const String &location) {
    String test_location = ParseLocation(url);
    if (test_location) {
        assertEqual(test_location, location);
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseUsername(const String &url, const String &user, const String &password) {
    String *test_userpassword = ParseUserName(url);
    if (test_userpassword) {
    } else {
    }
}


void Comm::UrlParserTest::setup() {
    scheme_ = String("http");
    user_ = String("seccijr");
    password_ = String("password");
    host_ = String("github.com");
    location_ = user_ + ":" + password_ + "@" + host_;
    path_ = String("seccijr/quintocrawl");
    query_ = String("q=Carlos+I.");
    fragment_ = String("permalink");
    url_ = scheme_ + "://" + location_ + "/" + path_ + "?" + query_ + "#" + fragment_;
}

void Comm::UrlParserTest::once() {
    TestCheckUrlFormat(url_);
    TestIsSchemaValid(scheme_);
    TestParseScheme(url_, scheme_);
    TestParseLocation(url_, location_);
    TestParseUsername(url_, user_, password_);
}
