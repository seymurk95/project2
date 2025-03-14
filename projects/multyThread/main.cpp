#include <iostream>
#include <thread>
#include<chrono>
#include<condition_variable>
#include<mutex>
#include<string>
/*int main() {
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads != 0) {
        std::cout <<num_threads << std::endl;
    }
}*/
/*void foo(int z) {
    for (int i = 0; i != z; i++) {
        std::cout << "Thread using function foo \n";

    }
}

class thread_obj {
public:
    void operator() (int x) {
        for (int i = 0; i != x; i++) {
            std::cout << "Thread using thread_obj \n";
        }
    }
};
class Base {
public:
    void foo() {
        std::cout << "Thread using member function foo() \n";
    }
    static void foo1() {
        std::cout << "Thread using member function foo1() \n";
    }
};

int main() {
    std::thread th1(foo,3);
    std::thread th2(thread_obj(),4);
    auto f = [](int x) {
        for (int i = 0; i != x; i++) {
            std::cout << "Thread using lambda\n";
        }
    };
    std::thread th3(f,3);
    Base b;
    std::thread th4(&Base::foo,&b);
    std::thread th5(&Base::foo1);
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();

}*/

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;
void worker_thread() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Worker thread started"<<std::endl;
    std::unique_lock lk(m);
    cv.wait(lk,[]{return ready;});
    std::cout<<"Worker thread inprocess"<<std::endl;
    data+=" after processing";
    processed = true;
    std::cout<<"Worker thread signals processing complete"<<std::endl;
    lk.unlock();
    cv.notify_one();
}

void master_thread() {
    std::cout<<"Master thread start"<<std::endl;
    data = "Example data";
    {
        std::lock_guard lk(m);
        ready = true;
        std::cout<<"Master thread signals data ready for processing"<<std::endl;

    }
    cv.notify_one();
    {
        std::unique_lock lk(m);
        cv.wait(lk,[]{return processed;});
    }
    std::cout<<"In master thread again. Data= "<<data<<std::endl;

}

int main() {
    std::thread worker { worker_thread };
    std::thread master { master_thread };
    worker.join();
    master.join();

}
