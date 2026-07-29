class Semaphore {
private:
    condition_variable cv;
    mutex m;
    int count;

public:
    Semaphore(int count) : count(count) {}

    void signal() {
        unique_lock<mutex> lock(m);
        count++;
        if (count >= 0)
            cv.notify_one();
    }

    void wait() {
        unique_lock<mutex> lock(m);
        count--;
        while (count < 0)
            cv.wait(lock);
    }
};

class DiningPhilosophers {
public:
    mutex m;
    Semaphore* fork[5];

    DiningPhilosophers() {
        for (int i = 0; i < 5; i++)
            fork[i] = new Semaphore(1);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        {
            unique_lock<mutex> lock(m);
            fork[(philosopher + 1) % 5]->wait();
            fork[philosopher]->wait();
        }

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        fork[(philosopher + 1) % 5]->signal();

        putRightFork();
        fork[philosopher]->signal();
    }
};