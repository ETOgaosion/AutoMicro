// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: RcNet.proto
// Original file comments:
// [START declaration]
#ifndef GRPC_RcNet_2eproto__INCLUDED
#define GRPC_RcNet_2eproto__INCLUDED

#include "RcNet.pb.h"

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

namespace Rc {

// [START service]
class RcNetService final {
 public:
  static constexpr char const* service_full_name() {
    return "Rc.RcNetService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status readSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::Common::Types::ULongList* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::ULongList>> AsyncreadSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::ULongList>>(AsyncreadSpefRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::ULongList>> PrepareAsyncreadSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::ULongList>>(PrepareAsyncreadSpefRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void readSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair* request, ::Common::Types::ULongList* response, std::function<void(::grpc::Status)>) = 0;
      virtual void readSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair* request, ::Common::Types::ULongList* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::ULongList>* AsyncreadSpefRaw(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Common::Types::ULongList>* PrepareAsyncreadSpefRaw(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status readSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::Common::Types::ULongList* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::ULongList>> AsyncreadSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::ULongList>>(AsyncreadSpefRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::ULongList>> PrepareAsyncreadSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Common::Types::ULongList>>(PrepareAsyncreadSpefRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void readSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair* request, ::Common::Types::ULongList* response, std::function<void(::grpc::Status)>) override;
      void readSpef(::grpc::ClientContext* context, const ::Common::Types::StrIntPair* request, ::Common::Types::ULongList* response, ::grpc::ClientUnaryReactor* reactor) override;
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
    ::grpc::ClientAsyncResponseReader< ::Common::Types::ULongList>* AsyncreadSpefRaw(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Common::Types::ULongList>* PrepareAsyncreadSpefRaw(::grpc::ClientContext* context, const ::Common::Types::StrIntPair& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_readSpef_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status readSpef(::grpc::ServerContext* context, const ::Common::Types::StrIntPair* request, ::Common::Types::ULongList* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_readSpef : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_readSpef() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_readSpef() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status readSpef(::grpc::ServerContext* /*context*/, const ::Common::Types::StrIntPair* /*request*/, ::Common::Types::ULongList* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestreadSpef(::grpc::ServerContext* context, ::Common::Types::StrIntPair* request, ::grpc::ServerAsyncResponseWriter< ::Common::Types::ULongList>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_readSpef<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_readSpef : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_readSpef() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::Common::Types::StrIntPair, ::Common::Types::ULongList>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::Common::Types::StrIntPair* request, ::Common::Types::ULongList* response) { return this->readSpef(context, request, response); }));}
    void SetMessageAllocatorFor_readSpef(
        ::grpc::MessageAllocator< ::Common::Types::StrIntPair, ::Common::Types::ULongList>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::Common::Types::StrIntPair, ::Common::Types::ULongList>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_readSpef() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status readSpef(::grpc::ServerContext* /*context*/, const ::Common::Types::StrIntPair* /*request*/, ::Common::Types::ULongList* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* readSpef(
      ::grpc::CallbackServerContext* /*context*/, const ::Common::Types::StrIntPair* /*request*/, ::Common::Types::ULongList* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_readSpef<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_readSpef : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_readSpef() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_readSpef() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status readSpef(::grpc::ServerContext* /*context*/, const ::Common::Types::StrIntPair* /*request*/, ::Common::Types::ULongList* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_readSpef : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_readSpef() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_readSpef() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status readSpef(::grpc::ServerContext* /*context*/, const ::Common::Types::StrIntPair* /*request*/, ::Common::Types::ULongList* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestreadSpef(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_readSpef : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_readSpef() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->readSpef(context, request, response); }));
    }
    ~WithRawCallbackMethod_readSpef() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status readSpef(::grpc::ServerContext* /*context*/, const ::Common::Types::StrIntPair* /*request*/, ::Common::Types::ULongList* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* readSpef(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_readSpef : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_readSpef() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::Common::Types::StrIntPair, ::Common::Types::ULongList>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::Common::Types::StrIntPair, ::Common::Types::ULongList>* streamer) {
                       return this->StreamedreadSpef(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_readSpef() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status readSpef(::grpc::ServerContext* /*context*/, const ::Common::Types::StrIntPair* /*request*/, ::Common::Types::ULongList* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedreadSpef(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Common::Types::StrIntPair,::Common::Types::ULongList>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_readSpef<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_readSpef<Service > StreamedService;
};

}  // namespace Rc


#endif  // GRPC_RcNet_2eproto__INCLUDED
