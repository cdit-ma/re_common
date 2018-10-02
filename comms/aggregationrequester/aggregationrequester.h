#ifndef AGGSERVER_REQUESTER_H
#define AGGSERVER_REQUESTER_H

#include <string>
#include <memory>

#include <proto/aggregationmessage/aggregationmessage.pb.h>
#include <zmq/protorequester/protorequester.hpp>

namespace AggServer{
    class Requester{
        public:
            Requester(const std::string& aggregation_broker_endpoint);
            std::unique_ptr<AggServer::PortLifecycleResponse> GetPortLifecycle(const AggServer::PortLifecycleRequest& request);
        private:
            zmq::ProtoRequester requester_;
    };
};

#endif //AGGSERVER_REQUESTER_H