#include "UrlParser.h"

bool CheckUrlFormat(const String &url) {
    int dslash_index = url.indexOf("//");
    if (dslash_index < 0) {
        return false;
    }

    int scheme_sep_index = url.indexOf(':');
    if (scheme_sep_index < 0 || dslash_index != scheme_sep_index + 1) {
        return false;
    }

    return true;
}

bool IsSchemeValid(const String &scheme) {
    int len = scheme.length();
    if (len <= 0) {
        return false;
    }

    for (int i = 0; i < scheme.length(); i++) {
        char c = scheme[i];
        if (!isalpha(c) && c != '+' && c != '-' && c != '.') {
            return false;
        }
    }

    return true;
}

String ParseScheme(const String &url) {
    int dot_index = url.indexOf(':');
    String scheme = url.substring(0, dot_index);
    if (!IsSchemeValid(scheme)) {
        return String(NULL);
    }

    scheme.toLowerCase();
    return scheme;
}

String ParseLocation(const String &url) {
    int dslash_index = url.indexOf("//");
    String no_scheme = url.substring(dslash_index + 2);
    int slash_index = no_scheme.indexOf("/");
    if (slash_index < 0) {
        slash_index = no_scheme.length();
    }

    return no_scheme.substring(0, slash_index);
}

int ParseUserName(const String &url, String result[], int size) {
    int n_result = 0;
    String location = ParseLocation(url);
    int at_index = location.indexOf('@');
    if (at_index <= 0) {
        return n_result;
    }

    int pass_sep_index = location.indexOf(':');
    if (pass_sep_index > 0 && pass_sep_index  < at_index - 1 && size > 1) {
        result[0] = location.substring(0, pass_sep_index);
        result[1] = location.substring(pass_sep_index + 1, at_index);
        n_result = 2;
    } else if (pass_sep_index < 0 && size >= 1) {
        result[0] = location.substring(0, at_index);
        n_result = 1;
    }

    return n_result;
}

String ParseTCP(const String &url) {
    String location = ParseLocation(url);
    int bracket_index = location.indexOf('[');
    int close_bracket_index = location.indexOf(']');
    if (bracket_index >= 0 && close_bracket_index > bracket_index + 1) {
        return location.substring(bracket_index + 1, close_bracket_index);
    }

    int at_index = location.indexOf('@');
    if (at_index >= 0) {
        location = location.substring(at_index + 1);
    }
    return location;
}

String ParseHost(const String &url) {
    String host = ParseTCP(url);
    int port_sep_index = host.indexOf(':');
    if (port_sep_index > 0) {
        host = host.substring(0, port_sep_index);
    }
    return host;
}

int ParsePort(const String &url) {
    int result = -1;
    String tcp = ParseTCP(url);
    int port_sep_index = tcp.indexOf(':');
    if (port_sep_index > 0) {
        String port = tcp.substring(port_sep_index + 1);
        result = port.toInt();
    }

    return result;
}

String ParsePath(const String &url) {
    String location = ParseLocation(url);
    int location_index = url.indexOf(location);
    String path = url.substring(location_index + location.length());
    int fragment_index = path.indexOf('#');
    if (fragment_index >= 0) {
        path = path.substring(0, fragment_index);
    }

    int query_index = path.indexOf('?');
    if (query_index >= 0) {
        path = path.substring(0, query_index);
    }

    return path;
}

String ParseFragment(const String &url) {
    int fragment_index = url.indexOf('#');
    if (fragment_index >= 0) {
        return url.substring(fragment_index + 1);
    }

    return String(NULL);
}

String ParseQuery(const String &url) {
    int stop = url.length();
    int fragment_index = url.indexOf('#');
    if (fragment_index >= 0) {
        stop = fragment_index;
    }

    int query_index = url.indexOf('?');
    if (query_index >= 0) {
        return url.substring(query_index + 1, stop);
    }

    return String(NULL);
}

Comm::UrlParserClass Comm::UrlParserClass::Parse(const String &url) {
    if (!CheckUrlFormat(url)) {
        return UrlParserClass(0);
    }

    String scheme = ParseScheme(url);
    if (!scheme) {
        return UrlParserClass(0);
    }

    UrlParserClass result = UrlParserClass(1);
    result.scheme_ = scheme;
    String user_password[2];
    int n_user = ParseUserName(url, user_password, 2);
    if (n_user >= 1) {
        result.user_name_ = user_password[0];
    }

    if (n_user == 2) {
        result.password_ = user_password[1];
    }

    result.host_ = ParseHost(url);
    int port = ParsePort(url);
    if (port > 0 && port < 65535) {
        result.port_ = port;
    }

    String path = ParsePath(url);
    if (path) {
        result.path_ = path;
    }

    String query = ParseQuery(url);
    if (query) {
        result.query_ = query;
    }

    String fragment = ParseFragment(url);
    if (fragment) {
        result.fragment_ = fragment;
    }

    return result;
}
