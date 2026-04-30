
class Counter {
    private:
        static int count_;
    public:
        Counter();
        static int get_count();
        static void reset_count();
};