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
        assertTrue(test_scheme.equals(scheme));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseLocation(const String &url, const String &location) {
    String test_location = ParseLocation(url);
    if (test_location) {
        assertTrue(test_location.equals(location));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseUsername(const String &url, const String &user, const String &password) {
    String *test_userpassword = ParseUserName(url);
    if (test_userpassword != NULL) {
        String test_user = (String)(*test_userpassword);
        test_userpassword++;
        String test_password = (String)(*test_userpassword);
        assertTrue(test_password.equals(password));
        assertTrue(test_user.equals(user));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseTCP(const String &url, const String &tcp) {
    String test_tcp = ParseTCP(url);
    if (test_tcp) {
        assertTrue(test_tcp.equals(tcp));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseHost(const String &url, const String &host) {
    String test_host = ParseHost(url);
    if (test_host) {
        assertTrue(test_host.equals(host));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParsePort(const String &url, const int &port) {
    int test_port = ParsePort(url);
    if (test_port != -1) {
        assertEqual(test_port, port);
    } else {
        fail();
    }
}

void Comm::UrlParserTest::setup() {
    scheme_ = String("http");
    user_ = String("user");
    password_ = String("password");
    host_ = String("domain.com");
    port_ = 80;
    tcp_ = host_ + ":" + port_;
    location_ = user_ + ":" + password_ + "@" + tcp_;
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
    TestParseTCP(url_, tcp_);
    TestParseHost(url_, host_);
    TestParsePort(url_, port_);
}
