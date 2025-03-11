#include <iostream>
#include <thread>
#include <shared_mutex>
#include <mutex>
#include <chrono>

/*std::mutex mtx;
int number = 0;
void increment() {
    mtx.lock();
    for (int i = 0; i != 1000000; i++) {
        number++;
    }
    mtx.unlock();
}
int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Number after t1 and t2 "<< number << std::endl;
    return 0;
}*/
/*std::shared_mutex mtx;
int shared_data=11;
void readData() {
    std::shared_lock<std::shared_mutex> lock(mtx);
    std::cout <<"Thread "<<std::this_thread::get_id()<<": "<<shared_data<<" entered mutex\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout <<"Thread "<<std::this_thread::get_id()<<": "<<shared_data<<" exited mutex\n";

}
void writeData(int n) {
    std::unique_lock<std::shared_mutex> lock(mtx);
    shared_data=n;
    std::cout << "Thread "<<std::this_thread::get_id()<<": "<<shared_data<<std::endl;
}
int main() {
    std::thread t1(readData);
    std::thread t2(writeData,42);
    std::thread t3(writeData,111);
    std::thread t4(readData);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}*/

/*std::mutex mtx;
void task() {
    std::lock_guard<std::mutex> lock(mtx); //простая обёртка над мьютексом ,его можно только закрыть
    std::cout << "captured resorce"<<std::endl;
}*/

/*std::mutex mtx;
void task() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "captured resorce"<<std::endl;
    lock.unlock();
}*/

/*std::mutex mtx;
void task() {
    std::unique_lock<std::mutex> lock(mtx,std::defer_lock);//смотри фото 11 марта
}*/

std::timed_mutex tmux;
void task(int id) {
    std::cout <<"Thread " << id <<" tries to acquirate lock\n";
    std::unique_lock<std::timed_mutex> lock(tmux,std::defer_lock);
    if(lock.try_lock_for(std::chrono::seconds(2))) {
        std::cout <<"Thread " << id <<" acquired lock\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout <<"Thread " << id <<" released lock\n";
    }else {
        std::cout <<"Thread " << id <<" failed to acquire lock\n";
    }


}
int main() {
    std::thread t1(task,1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread t2(task,2);
    t1.join();
    t2.join();
}
