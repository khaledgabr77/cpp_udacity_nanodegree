#include <iostream>
#include <thread>
#include <future>

void modifyMessage(std::promise<std::string> && prms, std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));   // simulate work
    std::string modifiedMessage = message + " has been modified";
    prms.set_value(modifiedMessage);
}

int main() {
    // define message
    std::string messageToThread = "My message";

    // create promise and future
    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    // start thread and pass promise as an argument
    std::thread t(modifyMessage, std::move(prms), messageToThread);

    // print original message
    std::cout << "Original message from the main(): " << messageToThread << std::endl;

    // retrieve modified message via future and print to the console
    std::string messageFromThread = ftr.get();
    std::cout << "Modified messgae from the thread(): " << messageFromThread << std::endl;

    // thread barrier
    t.join();

    return 0;
}