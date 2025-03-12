#include <iostream>
#include<semaphore>
#include<thread>
std::counting_semaphore<10> semaphore(3);
void worker(int id) {
    semaphore.acquire();
    std::cout <<"Thread "<< id << " acquired semaphore" << std::endl;
    semaphore.release();
    std::cout <<"Thread "<< id << " released semaphore" << std::endl;
}
int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
