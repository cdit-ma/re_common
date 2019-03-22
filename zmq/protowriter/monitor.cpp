/* re_common
 * Copyright (C) 2016-2017 The University of Adelaide
 *
 * This file is part of "re_common"
 *
 * "re_common" is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * "re_common" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
 
#include "monitor.h"
#include <iostream>
#include <functional>

void zmq::Monitor::RegisterEventCallback(std::function<void(int, std::string)> fn){
    callback_ = fn;
}

zmq::Monitor::~Monitor(){
    std::cerr << "abort" << std::endl;
    abort();
    std::cerr << "abortd" << std::endl;
    if(future_.valid()){
        std::cerr << "future_.get();" << std::endl;
        future_.get();
        std::cerr << "abofuture_.ged();rt" << std::endl;
    }
}

void zmq::Monitor::MonitorThread(zmq::socket_t& socket, const int event_type){
    future_ = std::async(std::launch::async, &Monitor::MonitorThread_, this, std::ref(socket), event_type);
}

void zmq::Monitor::MonitorThread_(std::reference_wrapper<zmq::socket_t> socket, const int event_type){
    static std::atomic<int> monitor_count{0};
    
    try{
        std::string monitor_address{"inproc://monitor_" + std::to_string(monitor_count++)};
        
        init(socket.get(), monitor_address.c_str());

        std::cerr << "MONITORING BOIS" << std::endl;
        while(check_event(-1)){
            std::cerr << "GOT EVENTS" << std::endl;

        }
    }catch(const zmq::error_t& ex){
        std::cerr << "MonitorThread: " << ex.what() << std::endl;
    }
}

void zmq::Monitor::on_event(const zmq_event_t &event, const char* addr){
    std::cerr << addr << std::endl;
    if(callback_){
        callback_(event.event, std::string(addr));
    }
}

void zmq::Monitor::on_event_connected(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_connect_delayed(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_connect_retried(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_listening(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_bind_failed(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_accepted(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_accept_failed(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_closed(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_close_failed(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_disconnected(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_handshake_failed(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_handshake_succeed(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
void zmq::Monitor::on_event_unknown(const zmq_event_t &event, const char* addr){
    on_event(event, addr);
}
