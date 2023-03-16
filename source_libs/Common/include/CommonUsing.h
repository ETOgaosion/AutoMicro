#pragma once

#define using_grpc using grpc::Server; \
using grpc::ServerBuilder; \
using grpc::ServerContext; \
using grpc::Status; \
using grpc::Channel; \
using grpc::ClientContext

#define using_verilog_parser using namespace ::VerilogParser

#define using_liberty using namespace ::Liberty

#define using_common_types using namespace ::Common::Types

#define using_common using namespace ::iSTA_Proto::Common

#define using_config using namespace ::Config

#define using_design_objs using namespace ::DesignObjects

#define using_sta_structure using namespace ::StaStructure

#define using_rc using namespace ::Rc

#define using_sdc using namespace ::Sdc
