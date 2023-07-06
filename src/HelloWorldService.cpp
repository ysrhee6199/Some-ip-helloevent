#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "HelloWorldStubImpl.hpp"
  
using namespace std;
  
int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<HelloWorldStubImpl> myService = std::make_shared<HelloWorldStubImpl>();
    bool test = true;
    runtime->registerService("local", "test", myService);
    std::cout << "Successfully Registered Service!" << std::endl;
 
    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        if(test){
            test = false;
            std::cout << "Send Attribute!!!" << std::endl;
            myService->setHelloStateAttribute(true);//while 문이 5초에 한번씩 돌면서 attribute를 set해준다.
        }else{
            test = true;
            std::cout << "Send BoradCastEvent!!!" << std::endl;
            myService->setHelloStateAttribute(false);//while 문이 5초에 한번씩 돌면서 attribute를 set해준다.
            myService->fireHelloBroadcastEvent("broadCast MSG");//while 문이 5초에 한번씩 BroadcstEvent를 발생 시킨다.
        }
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
  
    return 0;
 } 