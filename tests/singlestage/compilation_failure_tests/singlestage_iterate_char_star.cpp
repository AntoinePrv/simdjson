#include <iostream>
#include "simdjson.h"

using namespace simdjson;

int main() {
    singlestage::parser parser;
#if COMPILATION_TEST_USE_FAILING_CODE
    const char* json;
    auto doc = parser.iterate(json, strlen(json));
#else
    auto json = "1"_padded;
    auto doc = parser.iterate(json);
#endif
    int64_t value;
    auto error = doc.get(value);
    if (error) { exit(1); }
    std::cout << value << std::endl;
}
