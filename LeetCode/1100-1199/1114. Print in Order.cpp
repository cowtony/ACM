class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock lk(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        count++;
        lk.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock lk(m);
        cv.wait(lk, [this]{return count == 1;});

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        count++;
        lk.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock lk(m);
        cv.wait(lk, [this]{return count == 2;});

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lk.unlock();
    }
  
  private:
    mutex m;
    condition_variable cv;
    int count = 0;
};
