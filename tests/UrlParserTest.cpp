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
    String test_userpassword[2];
    int n_result = ParseUserName(url, test_userpassword, 2);
    if (n_result >= 1) {
        String test_user = test_userpassword[0];
        assertTrue(test_user.equals(user));
    } else {
        fail();
    }

    if (n_result == 2) {
        String test_password = test_userpassword[1];
        assertTrue(test_password.equals(password));
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

void Comm::UrlParserTest::TestParsePath(const String &url, const String &path) {
    String test_path = ParsePath(url);
    if (test_path) {
        assertTrue(test_path.equals(path));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseFragment(const String &url, const String &fragment) {
    String test_fragment = ParseFragment(url);
    if (test_fragment) {
        assertTrue(test_fragment.equals(fragment));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParseQuery(const String &url, const String &query) {
    String test_query = ParseQuery(url);
    if (test_query) {
        assertTrue(test_query.equals(query));
    } else {
        fail();
    }
}

void Comm::UrlParserTest::TestParse(
        const String &url,
        const String &scheme,
        const String &user,
        const String &password,
        const String &host,
        const int &port,
        const String &path,
        const String &query,
        const String &fragment) {
    UrlParserClass test_parser = UrlParserClass::Parse(url);
    if (test_parser.ok_) {
        assertTrue(test_parser.scheme_.equals(scheme));
        assertTrue(test_parser.user_.equals(user));
        assertTrue(test_parser.password_.equals(password));
        assertTrue(test_parser.host_.equals(host));
        assertEqual(test_parser.port_, port);
        assertTrue(test_parser.path_.equals(path));
        assertTrue(test_parser.query_.equals(query));
        assertTrue(test_parser.fragment_.equals(fragment));
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
    path_ = String("/high/low");
    query_ = String("query=q");
    fragment_ = String("link");
    url_ = scheme_ + "://" + location_ + path_ + "?" + query_ + "#" + fragment_;
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
    TestParsePath(url_, path_);
    TestParseFragment(url_, fragment_);
    TestParseQuery(url_, query_);
    TestParse(url_, scheme_, user_, password_, host_, port_, path_, query_, fragment_);
}
