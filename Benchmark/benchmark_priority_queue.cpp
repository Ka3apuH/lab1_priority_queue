//
// Created by kirill_kazarin on 23.02.2022.
//

#include <random>

#include "benchmark/benchmark.h"
#include "priority_queue.h"

void priority_queue_add_elements(size_t size_for){
    std::random_device randomDevice;
    h_work::priority_queue<unsigned int> pr_heap;

    for (size_t i = 0; i <size_for ; ++i) {
        pr_heap.add_element(randomDevice());
    }
}

static void BM_priority_queue_add_elements(benchmark::State& state) {

    for (auto _ : state) {
        priority_queue_add_elements(state.range(0));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_priority_queue_add_elements)
->RangeMultiplier(2)->Range(8<<10, 8<<15)->Complexity(benchmark::oLogN);


// Run the benchmark
BENCHMARK_MAIN();
