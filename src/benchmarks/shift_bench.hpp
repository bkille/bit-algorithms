#include <benchmark/benchmark.h>
#include <random>
#include <math.h>


auto BM_BitShiftLeft = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = ceil(float(total_bits) / digits);
    container_type bitcont = make_random_container<container_type>(container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    auto n = bit::distance(first, last) / 2 + 3;
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::shift_left(first, last, n));
        benchmark::ClobberMemory();
    }
};

auto BM_BitShiftLeft_UU = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = ceil(float(total_bits) / digits);
    container_type bitcont = make_random_container<container_type>(container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont)) + 1;
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont)) - 1;
    auto n = bit::distance(first, last) / 2 + 3;
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::shift_left(first, last, n));
        benchmark::ClobberMemory();
    }
};

auto BM_BoolShiftLeft = [](benchmark::State& state, auto input) {
    using container_type = std::vector<bool>;
    using num_type = typename container_type::value_type;
    unsigned int container_size = std::get<2>(input);
    container_type cont = make_random_container<container_type>(container_size); 
    auto first = cont.begin();
    auto last = cont.end();
    auto n = std::distance(first, last) / 2 + 3;
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::word_shift_left(first, last, n));
        benchmark::ClobberMemory();
    }
};

auto BM_BitShiftRight = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = ceil(float(total_bits) / digits);
    container_type bitcont = make_random_container<container_type>(container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    auto n = bit::distance(first, last) / 2 + 3;
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::shift_right(first, last, n));
        benchmark::ClobberMemory();
    }
};

auto BM_BitShiftRight_UU = [](benchmark::State& state, auto input) {
    using container_type = typename std::tuple_element<0, decltype(input)>::type;
    using word_type = typename std::tuple_element<1, decltype(input)>::type;
    unsigned int total_bits = std::get<2>(input);
    auto digits = bit::binary_digits<word_type>::value;
    auto container_size = ceil(float(total_bits) / digits);
    container_type bitcont = make_random_container<container_type>(container_size); 
    auto first = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont)) + 2;
    auto last = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont)) - 3;
    auto n = bit::distance(first, last) / 2 + 3;
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::shift_right(first, last, n));
        benchmark::ClobberMemory();
    }
};

auto BM_BoolShiftRight = [](benchmark::State& state, auto input) {
    using container_type = std::vector<bool>;
    using num_type = typename container_type::value_type;
    unsigned int container_size = std::get<2>(input);
    container_type cont = make_random_container<container_type>(container_size); 
    auto first = cont.begin();
    auto last = cont.end();
    auto n = std::distance(first, last) / 2 + 3;
    for (auto _ : state) {
        benchmark::DoNotOptimize(bit::word_shift_right(first, last, n));
        benchmark::ClobberMemory();
    }
};
