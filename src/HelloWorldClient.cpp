#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldProxy.hpp>
  
using namespace v1::commonapi;
  
int main() {
    std::shared_ptr <CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<HelloWorldProxy<>> myProxy = runtime->buildProxy<HelloWorldProxy>("local", "test");
  
    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
  
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    myProxy->sayHello("Bob", callStatus, returnMessage);//서버의 함수를 호출 (method call)
    std::cout << "Got message: '" << returnMessage << "'\n";
 
    myProxy->getHelloStateAttribute().getChangedEvent().subscribe([&](const bool value) {//attribute 이벤트를 등록시킴
        std::cout << "getHelloStateAttribute value : " << value << std::endl;
    });
    myProxy->getHelloBroadcastEvent().subscribe([&](const std::string &value) {//broadcast 이벤트를 등록시킴
        std::cout << "getHelloBroadcastEvent value : " << value << std::endl;
    });
 
    while (true) {
        std::cout << "client Waiting for calls... (Abort with CTRL+C)" << std::endl;
 
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
     
    return 0;
} 
