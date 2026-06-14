#include "tests.h"
#include "unique_sorted_collector.h"
#include "data_collector.h"
#include "json_collector.h"
#include "csv_unique_sorted_collector.h"
#include <iostream>

void test_unique_sorted_collector() {
    unique_sorted_collector_test collector;
    collector.receive(3);
    collector.receive(6);
    collector.receive(1);
    collector.receive(2);
    collector.receive(6);
    collector.receive(1);
    std::cout << collector.print();
}


void test_csv_unique_sorted_collector() {
    csv_unique_sorted_collector collector(200);
    collector.receive(53);
    collector.receive(5);
    collector.receive(35);
    collector.receive(4);
    collector.receive(445);
    collector.receive(2);
    collector.receive(4);
    collector.receive(35);
    std::cout << collector.print();


}

void test_json_collector() {
    json_collector collector("Temperatur", 50, 200);
    collector.receive(55);
    collector.receive(13);
    collector.receive(133);
    collector.receive(199);
    collector.receive(550);
    collector.receive(67);
    std::cout << collector.print();

}