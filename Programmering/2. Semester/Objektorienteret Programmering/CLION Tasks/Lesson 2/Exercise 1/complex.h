#ifndef COMPLEX_H
#define COMPLEX_H
#include    <ostream>

class complex {
    public:
        complex(const double x = 0, const double y = 0);
        complex add_ret_copy(const complex*) const;
        complex* add_to_this(std::ostream*) const;

    private:
        double x_;
        double y_;
};

#endif // COMPLEX_H
