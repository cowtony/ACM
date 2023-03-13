class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool is_foo = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk, [this]{return is_foo;});

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            is_foo = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk, [this]{return !is_foo;});

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            is_foo = true;
            cv.notify_one();
        }
    }
};
