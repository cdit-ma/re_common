#include "aggregationrequester.h"

AggServer::Requester::Requester(const std::string& aggregation_broker_endpoint):
    requester_(aggregation_broker_endpoint)
{
}

std::unique_ptr<AggServer::PortLifecycleResponse> AggServer::Requester::GetPortLifecycle(const AggServer::PortLifecycleRequest& request){
    auto reply = requester_.SendRequest<PortLifecycleRequest, PortLifecycleResponse>("GetPortLifecycle", request, 5000);
    try{
        return std::move(reply.get());
    }catch(const zmq::RMIException& ex){
        throw std::invalid_argument(ex.what());
    }catch(const zmq::TimeoutException& ex){
        throw std::runtime_error(ex.what());
    }
}