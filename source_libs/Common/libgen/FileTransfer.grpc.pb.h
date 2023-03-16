// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: FileTransfer.proto
#ifndef GRPC_FileTransfer_2eproto__INCLUDED
#define GRPC_FileTransfer_2eproto__INCLUDED

#include "FileTransfer.pb.h"

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

namespace File {

class FileTransfer final {
 public:
  static constexpr char const* service_full_name() {
    return "File.FileTransfer";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientWriterInterface< ::File::FileContent>> Upload(::grpc::ClientContext* context, ::File::FileId* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::File::FileContent>>(UploadRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::File::FileContent>> AsyncUpload(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::File::FileContent>>(AsyncUploadRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::File::FileContent>> PrepareAsyncUpload(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::File::FileContent>>(PrepareAsyncUploadRaw(context, response, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::File::FileContent>> Download(::grpc::ClientContext* context, const ::File::FileId& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::File::FileContent>>(DownloadRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::File::FileContent>> AsyncDownload(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::File::FileContent>>(AsyncDownloadRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::File::FileContent>> PrepareAsyncDownload(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::File::FileContent>>(PrepareAsyncDownloadRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void Upload(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::ClientWriteReactor< ::File::FileContent>* reactor) = 0;
      virtual void Download(::grpc::ClientContext* context, const ::File::FileId* request, ::grpc::ClientReadReactor< ::File::FileContent>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientWriterInterface< ::File::FileContent>* UploadRaw(::grpc::ClientContext* context, ::File::FileId* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::File::FileContent>* AsyncUploadRaw(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::File::FileContent>* PrepareAsyncUploadRaw(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::File::FileContent>* DownloadRaw(::grpc::ClientContext* context, const ::File::FileId& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::File::FileContent>* AsyncDownloadRaw(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::File::FileContent>* PrepareAsyncDownloadRaw(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    std::unique_ptr< ::grpc::ClientWriter< ::File::FileContent>> Upload(::grpc::ClientContext* context, ::File::FileId* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::File::FileContent>>(UploadRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::File::FileContent>> AsyncUpload(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::File::FileContent>>(AsyncUploadRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::File::FileContent>> PrepareAsyncUpload(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::File::FileContent>>(PrepareAsyncUploadRaw(context, response, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::File::FileContent>> Download(::grpc::ClientContext* context, const ::File::FileId& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::File::FileContent>>(DownloadRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::File::FileContent>> AsyncDownload(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::File::FileContent>>(AsyncDownloadRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::File::FileContent>> PrepareAsyncDownload(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::File::FileContent>>(PrepareAsyncDownloadRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void Upload(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::ClientWriteReactor< ::File::FileContent>* reactor) override;
      void Download(::grpc::ClientContext* context, const ::File::FileId* request, ::grpc::ClientReadReactor< ::File::FileContent>* reactor) override;
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
    ::grpc::ClientWriter< ::File::FileContent>* UploadRaw(::grpc::ClientContext* context, ::File::FileId* response) override;
    ::grpc::ClientAsyncWriter< ::File::FileContent>* AsyncUploadRaw(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncWriter< ::File::FileContent>* PrepareAsyncUploadRaw(::grpc::ClientContext* context, ::File::FileId* response, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::File::FileContent>* DownloadRaw(::grpc::ClientContext* context, const ::File::FileId& request) override;
    ::grpc::ClientAsyncReader< ::File::FileContent>* AsyncDownloadRaw(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::File::FileContent>* PrepareAsyncDownloadRaw(::grpc::ClientContext* context, const ::File::FileId& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Upload_;
    const ::grpc::internal::RpcMethod rpcmethod_Download_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Upload(::grpc::ServerContext* context, ::grpc::ServerReader< ::File::FileContent>* reader, ::File::FileId* response);
    virtual ::grpc::Status Download(::grpc::ServerContext* context, const ::File::FileId* request, ::grpc::ServerWriter< ::File::FileContent>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_Upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Upload() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::File::FileContent>* /*reader*/, ::File::FileId* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestUpload(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::File::FileId, ::File::FileContent>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Download : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Download() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_Download() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Download(::grpc::ServerContext* /*context*/, const ::File::FileId* /*request*/, ::grpc::ServerWriter< ::File::FileContent>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDownload(::grpc::ServerContext* context, ::File::FileId* request, ::grpc::ServerAsyncWriter< ::File::FileContent>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Upload<WithAsyncMethod_Download<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_Upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_Upload() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::File::FileContent, ::File::FileId>(
            [this](
                   ::grpc::CallbackServerContext* context, ::File::FileId* response) { return this->Upload(context, response); }));
    }
    ~WithCallbackMethod_Upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::File::FileContent>* /*reader*/, ::File::FileId* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::File::FileContent>* Upload(
      ::grpc::CallbackServerContext* /*context*/, ::File::FileId* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_Download : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_Download() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::File::FileId, ::File::FileContent>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::File::FileId* request) { return this->Download(context, request); }));
    }
    ~WithCallbackMethod_Download() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Download(::grpc::ServerContext* /*context*/, const ::File::FileId* /*request*/, ::grpc::ServerWriter< ::File::FileContent>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::File::FileContent>* Download(
      ::grpc::CallbackServerContext* /*context*/, const ::File::FileId* /*request*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_Upload<WithCallbackMethod_Download<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Upload() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::File::FileContent>* /*reader*/, ::File::FileId* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Download : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Download() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_Download() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Download(::grpc::ServerContext* /*context*/, const ::File::FileId* /*request*/, ::grpc::ServerWriter< ::File::FileContent>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Upload() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::File::FileContent>* /*reader*/, ::File::FileId* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestUpload(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_Download : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Download() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_Download() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Download(::grpc::ServerContext* /*context*/, const ::File::FileId* /*request*/, ::grpc::ServerWriter< ::File::FileContent>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDownload(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_Upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_Upload() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, ::grpc::ByteBuffer* response) { return this->Upload(context, response); }));
    }
    ~WithRawCallbackMethod_Upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::File::FileContent>* /*reader*/, ::File::FileId* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::grpc::ByteBuffer>* Upload(
      ::grpc::CallbackServerContext* /*context*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_Download : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_Download() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->Download(context, request); }));
    }
    ~WithRawCallbackMethod_Download() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Download(::grpc::ServerContext* /*context*/, const ::File::FileId* /*request*/, ::grpc::ServerWriter< ::File::FileContent>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* Download(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_Download : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_Download() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::File::FileId, ::File::FileContent>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::File::FileId, ::File::FileContent>* streamer) {
                       return this->StreamedDownload(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_Download() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Download(::grpc::ServerContext* /*context*/, const ::File::FileId* /*request*/, ::grpc::ServerWriter< ::File::FileContent>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedDownload(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::File::FileId,::File::FileContent>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_Download<Service > SplitStreamedService;
  typedef WithSplitStreamingMethod_Download<Service > StreamedService;
};

}  // namespace File


#endif  // GRPC_FileTransfer_2eproto__INCLUDED
