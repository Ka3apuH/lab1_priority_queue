//
// Created by kirill_kazarin on 23.02.2022.
//
#include "priority_queue.h"
#include <queue>

#ifndef LAB1_TEST_H
#define LAB1_TEST_H

class Test_priority_queue : public ::testing::Test {
protected:
    void SetUp() override {
        test_heap = h_work::priority_queue<int>(
                std::vector<int>{1,2,45,32,123,553,24,23,13,422}
                );
    }
    void TearDown() override {
        test_heap.clear();
    }

    std::priority_queue<int> real_heap;
    h_work::priority_queue<int> test_heap;
    std::random_device randomDevice;
};
#endif //LAB1_TEST_H
