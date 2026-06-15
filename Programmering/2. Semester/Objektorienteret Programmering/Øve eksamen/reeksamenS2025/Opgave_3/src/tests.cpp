#include "tests.h"
#include "abstract_ascii_art.h"
#include "letter_factory.h"
#include "ascii_letter.h"
#include "ascii_text.h"
#include <cassert>// if you want to use assertions

void test_abstract_ascii_art_render() {
    abstract_ascii_art_test test;
    test.render();
}

void test_ascii_letter_e() {
    ascii_letter letter(create_e());
    letter.render();
}

void test_ascii_text_exam() {
    ascii_text text;

    ascii_letter e(create_e());
    ascii_letter x(create_x());
    ascii_letter a(create_a());
    ascii_letter m(create_m());
    ascii_letter space(create_space());

    text.add(&e);
    text.add(&space);
    text.add(&x);
    text.add(&space);
    text.add(&a);
    text.add(&space);
    text.add(&m);

    text.render();
}