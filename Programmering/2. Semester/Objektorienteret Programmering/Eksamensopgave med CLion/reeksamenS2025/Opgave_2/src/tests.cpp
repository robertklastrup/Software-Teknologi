#include "tests.h"
#include "logger.h"
#include <cassert>
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

}

void test_log_template_log_entry() {

}