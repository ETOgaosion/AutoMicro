// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: LibertyReader.proto
// Original file comments:
// [START declaration]
#ifndef GRPC_LibertyReader_2eproto__INCLUDED
#define GRPC_LibertyReader_2eproto__INCLUDED

#include "LibertyReader.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace Liberty {

// [START service]
class LibertyReaderService final {
 public:
  static constexpr char const* service_full_name() {
    return "Liberty.LibertyReaderService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status loadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::Common::Types::BoolMsg* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::BoolMsg>> AsyncloadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::BoolMsg>>(AsyncloadLibertyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::BoolMsg>> PrepareAsyncloadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::BoolMsg>>(PrepareAsyncloadLibertyRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void loadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg* request, ::Common::Types::BoolMsg* response, std::function<void(::grpc::Status)>) = 0;
      virtual void loadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg* request, ::Common::Types::BoolMsg* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::BoolMsg>* AsyncloadLibertyRaw(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::BoolMsg>* PrepareAsyncloadLibertyRaw(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status loadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::Common::Types::BoolMsg* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::BoolMsg>> AsyncloadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::BoolMsg>>(AsyncloadLibertyRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::BoolMsg>> PrepareAsyncloadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::BoolMsg>>(PrepareAsyncloadLibertyRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void loadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg* request, ::Common::Types::BoolMsg* response, std::function<void(::grpc::Status)>) override;
      void loadLiberty(::grpc::ClientContext* context, const ::Common::Types::StringMsg* request, ::Common::Types::BoolMsg* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::Common::Types::BoolMsg>* AsyncloadLibertyRaw(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Common::Types::BoolMsg>* PrepareAsyncloadLibertyRaw(::grpc::ClientContext* context, const ::Common::Types::StringMsg& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_loadLiberty_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status loadLiberty(::grpc::ServerContext* context, const ::Common::Types::StringMsg* request, ::Common::Types::BoolMsg* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_loadLiberty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_loadLiberty() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_loadLiberty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status loadLiberty(::grpc::ServerContext* /*context*/, const ::Common::Types::StringMsg* /*request*/, ::Common::Types::BoolMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestloadLiberty(::grpc::ServerContext* context, ::Common::Types::StringMsg* request, ::grpc::ServerAsyncResponseWriter< ::Common::Types::BoolMsg>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_loadLiberty<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_loadLiberty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_loadLiberty() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::Common::Types::StringMsg, ::Common::Types::BoolMsg>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::Common::Types::StringMsg* request, ::Common::Types::BoolMsg* response) { return this->loadLiberty(context, request, response); }));}
    void SetMessageAllocatorFor_loadLiberty(
        ::grpc::MessageAllocator< ::Common::Types::StringMsg, ::Common::Types::BoolMsg>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::Common::Types::StringMsg, ::Common::Types::BoolMsg>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_loadLiberty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status loadLiberty(::grpc::ServerContext* /*context*/, const ::Common::Types::StringMsg* /*request*/, ::Common::Types::BoolMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* loadLiberty(
      ::grpc::CallbackServerContext* /*context*/, const ::Common::Types::StringMsg* /*request*/, ::Common::Types::BoolMsg* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_loadLiberty<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_loadLiberty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_loadLiberty() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_loadLiberty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status loadLiberty(::grpc::ServerContext* /*context*/, const ::Common::Types::StringMsg* /*request*/, ::Common::Types::BoolMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_loadLiberty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_loadLiberty() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_loadLiberty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status loadLiberty(::grpc::ServerContext* /*context*/, const ::Common::Types::StringMsg* /*request*/, ::Common::Types::BoolMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestloadLiberty(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_loadLiberty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_loadLiberty() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->loadLiberty(context, request, response); }));
    }
    ~WithRawCallbackMethod_loadLiberty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status loadLiberty(::grpc::ServerContext* /*context*/, const ::Common::Types::StringMsg* /*request*/, ::Common::Types::BoolMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* loadLiberty(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_loadLiberty : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_loadLiberty() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::Common::Types::StringMsg, ::Common::Types::BoolMsg>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::Common::Types::StringMsg, ::Common::Types::BoolMsg>* streamer) {
                       return this->StreamedloadLiberty(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_loadLiberty() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status loadLiberty(::grpc::ServerContext* /*context*/, const ::Common::Types::StringMsg* /*request*/, ::Common::Types::BoolMsg* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedloadLiberty(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Common::Types::StringMsg,::Common::Types::BoolMsg>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_loadLiberty<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_loadLiberty<Service > StreamedService;
};

}  // namespace Liberty


#endif  // GRPC_LibertyReader_2eproto__INCLUDED