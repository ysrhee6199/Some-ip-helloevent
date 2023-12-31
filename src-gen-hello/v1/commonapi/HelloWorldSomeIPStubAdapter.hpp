/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_COMMONAPI_HELLO_WORLD_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_HELLO_WORLD_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/HelloWorldStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename _Stub = ::v1::commonapi::HelloWorldStub, typename... _Stubs>
class HelloWorldSomeIPStubAdapterInternal
    : public virtual HelloWorldStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< HelloWorldSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> HelloWorldSomeIPStubAdapterHelper;

    ~HelloWorldSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        HelloWorldSomeIPStubAdapterHelper::deinit();
    }

    void fireHelloStateAttributeChanged(const bool &_value);
    
    void fireHelloBroadcastEvent(const std::string &_message);

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::HelloWorldStub,
        CommonAPI::Version
    > getHelloWorldInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::HelloWorldStub,
        bool
    > getHelloStateAttributeStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::HelloWorldStub,
        std::tuple< std::string>,
        std::tuple< std::string>,
        std::tuple< CommonAPI::SomeIP::StringDeployment>,
        std::tuple< CommonAPI::SomeIP::StringDeployment>
    > sayHelloStubDispatcher;
    
    HelloWorldSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        HelloWorldSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< HelloWorldStub>(_stub)),
        getHelloWorldInterfaceVersionStubDispatcher(&HelloWorldStub::lockInterfaceVersionAttribute, &HelloWorldStub::getInterfaceVersion, false, true),
        getHelloStateAttributeStubDispatcher(
            &::v1::commonapi::HelloWorldStub::lockHelloStateAttribute,
            &::v1::commonapi::HelloWorldStub::getHelloStateAttribute,
            false,
            _stub->hasElement(0))
        ,
        sayHelloStubDispatcher(
            &HelloWorldStub::sayHello,
            false,
            _stub->hasElement(1),
            std::make_tuple(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)))
        
    {
        HelloWorldSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x2007) }, &getHelloStateAttributeStubDispatcher );
        HelloWorldSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7d00) }, &sayHelloStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>(0xFFFF, 0xFFFFFFFF, 0xFFFFFFFF);

        // Provided events/fields
        {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(0x1002));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x8235), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_EVENT, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE);
        }
        if (_stub->hasElement(0)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x1001)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0xa005), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE);
            fireHelloStateAttributeChanged(std::dynamic_pointer_cast< ::v1::commonapi::HelloWorldStub>(_stub)->getHelloStateAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void HelloWorldSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireHelloStateAttributeChanged(const bool &_value) {
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            bool
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0xa005),
        false,
        _value
    );
}

template <typename _Stub, typename... _Stubs>
void HelloWorldSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireHelloBroadcastEvent(const std::string &_message) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deployed_message(_message, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<CommonAPI::SomeIP::SerializableArguments<  CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment > 
    >>
        ::sendEvent(
            *this,
            CommonAPI::SomeIP::event_id_t(0x8235),
            false,
             deployed_message 
    );
}


template <typename _Stub, typename... _Stubs>
void HelloWorldSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void HelloWorldSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::commonapi::HelloWorldStub, typename... _Stubs>
class HelloWorldSomeIPStubAdapter
    : public HelloWorldSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    HelloWorldSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          HelloWorldSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_Hello_World_SOMEIP_STUB_ADAPTER_HPP_
