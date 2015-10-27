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
    String *temp = test_userpassword;
    if (test_userpassword != NULL) {
        String test_user = (String)(*test_userpassword);
        test_userpassword++;
        String test_password = (String)(*test_userpassword);
        assertEqual(test_password, password_);
        assertEqual(test_user, user_);
    } else {
        fail();
    }
    delete temp;
}


void Comm::UrlParserTest::setup() {
    scheme_ = String("http");
    user_ = String("user");
    password_ = String("password");
    host_ = String("domain.com");
    location_ = user_ + ":" + password_ + "@" + host_;
    path_ = String("high/low");
    query_ = String("query=Carlos+I.+Perez+Sechi");
    fragment_ = String("link");
    url_ = scheme_ + "://" + location_ + "/" + path_ + "?" + query_ + "#" + fragment_;
}

void Comm::UrlParserTest::once() {
    TestCheckUrlFormat(url_);
    TestIsSchemaValid(scheme_);
    TestParseScheme(url_, scheme_);
    TestParseLocation(url_, location_);
    TestParseUsername(url_, user_, password_);
}
