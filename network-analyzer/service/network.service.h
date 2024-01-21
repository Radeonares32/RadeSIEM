#pragma once
#include <grpc++/grpc++.h>
#include <grpcpp/server.h>
#include <grpcpp/server_context.h>
#include <grpcpp/support/status.h>
#include "../proto/network.grpc.pb.h"

using grpc::Server;
using grpc::Service;
using grpc::ServerBuilder;
using grpc::Status;
using grpc::Status;

class NetworkServiceImp final : public network::NetworkService::Service {
  public:
     Status NetworkData(grpc::ServerContext* context, grpc::ServerReaderWriter<network::Data,network::Data>* steam) override; 
} ;


