#include <iostream>
#include <string>
#include <limits> // Added for std::numeric_limits
#include <utility>

static inline std::pair<float, float> get_float() {
    float f_, _f;
    std::cout << "[provide two floats]: ";
    std::cin >> f_ >> _f;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining newline character

    return std::make_pair(f_, _f);
}

static inline std::pair<int, int> get_int() {
    int f_, _f;
    std::cout << "[provide two ints]: ";
    std::cin >> f_ >> _f;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining newline character

    return std::make_pair(f_, _f);
}

static inline const char* get_word() {
    static std::string word;
    std::cout << "[provide a string]: ";
    std::getline(std::cin, word);
    return word.c_str();
}

template <typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

template<typename T2>
T2 div(T2 num, T2 num_) {
    std::cout << "[division of]: " << num << " & " << num_ << "\n";
    return num / num_;
}

int main(/*int argc, char* argv[]*/) {
    const char* word = get_word();
    //print(word);

    std::pair<int, int>nums = get_int();
    std::pair<float, float>nums_ = get_float();

    auto i = div(std::get<0>(nums), std::get<1>(nums));
    print(i);

    auto j = div(std::get<0>(nums_), std::get<1>(nums_));
    print(j);

    return EXIT_SUCCESS;
}
