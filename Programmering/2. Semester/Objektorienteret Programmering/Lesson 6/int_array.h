#include <string>
class int_array {
public:
    int_array(int initial_size, int re_alloc_size);
    ~int_array();
    int_array(const int_array&);
	int_array& operator=(const int_array&);
    void push_back(int);

    [[nodiscard]] std::string to_string() const;

    [[nodiscard]] int get_size() const;

    [[nodiscard]] int get_array_size() const;

    [[nodiscard]] int get_re_alloc_size() const;
private:
    int size_;
    int head_;
    int re_alloc_size_;
    int *array_;
};