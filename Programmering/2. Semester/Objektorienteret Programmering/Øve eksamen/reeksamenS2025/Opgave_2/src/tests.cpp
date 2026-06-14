#include "tests.h"
#include "logger.h"
#include <cassert>

#include "logger_template.h"
#include "log_entry.h"
// In this test, assertions are used. You can choose not to use this test tool
// but test the same facts by print-out in the next tests
void test_log() {
    logger l;
    l.log("2020:12:12:12:11", "mylog1");
    l.log("2020:12:12:12:12", "mylog2");
    l.log("2020:12:12:12:13", "mylog3");
    l.log("2020:12:12:12:14", "mylog3");
    assert(l.count() == 4);
    auto contains = l.contains("mylog3");
    assert(contains.size() == 2);
    assert(contains[0].first == "2020:12:12:12:13");
    assert(contains[1].first == "2020:12:12:12:14");
    assert(contains[0].second == "mylog3");
    assert(contains[1].second == "mylog3");
    l.print();
}

void test_log_template_string() {
    logger_template<std::string> l;
    l.log("2020:12:12:12:11", "mylog1");
    l.log("2020:12:12:12:12", "mylog2");
    l.log("2020:12:12:12:13", "mylog3");
    l.log("2020:12:12:12:14", "mylog3");
    assert(l.count() == 4);
    auto contains = l.contains("mylog3");
    assert(contains.size() == 2);
    assert(contains[0].first == "2020:12:12:12:13");
    assert(contains[1].first == "2020:12:12:12:14");
    assert(contains[0].second == "mylog3");
    assert(contains[1].second == "mylog3");
    l.print();
}

void test_log_template_log_entry() {
    logger_template<log_entry> l;

    l.log("2020:12:12:12:11", {"2020:12:12:12:11", "DEBUG", "myapp", "mylog1"});
    l.log("2020:12:12:12:12", {"2020:12:12:12:12", "DEBUG", "myapp", "mylog2"});
    l.log("2020:12:12:12:13", {"2020:12:12:12:13", "DEBUG", "myapp", "mylog3"});
    l.log("2020:12:12:12:14", {"2020:12:12:12:14", "DEBUG", "myapp", "mylog4"});

    assert(l.count() == 4);
    l.print();
}