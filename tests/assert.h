#ifndef ASSERT_V8_H_
#define ASSERT_V8_H_

#include <iostream>

#define ASSERT_EQUAL(a, b) do { \
    std::cout << a << " == " << b << " : "; \
    if (a != b) { \
        std::cout << "FAILED (" <<  __FILE__ << ":" << __LINE__ << ")" << std::endl; \
    } else { \
        std::cout << "OK" << std::endl; \
    } \
} while (0)

#define ASSERT_NOT_EQUAL(a, b) do { \
    std::cout << a << " != " << b << " : "; \
    if (a == b) { \
        std::cout << "FAILED (" <<  __FILE__ << ":" << __LINE__ << ")" << std::endl; \
    } else { \
        std::cout << "OK" << std::endl; \
    } \
} while (0)

#define ASSERT_STR_EQUAL(a, b) do { \
    std::cout << a << " == " << b << " : "; \
    if (strcmp(a, b) != 0) { \
        std::cout << "FAILED (" <<  __FILE__ << ":" << __LINE__ << ")" << std::endl; \
    } else { \
        std::cout << "OK" << std::endl; \
    } \
} while (0)

inline std::ostream& operator<<(std::ostream& os, const uint8_t data) {
    os << unsigned(data);
    return os;
}

#endif /* ASSERT_V8_H_ */
