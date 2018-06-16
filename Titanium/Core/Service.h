#pragma once
#include <iostream>
#include "Event.h"
#include <boost/asio/io_service.hpp>
#include <iostream>
#include <thread>
#include <boost/bind.hpp>
#include <chrono>
namespace titanium {
	namespace core {

		using EventPtr = std::shared_ptr<core::IEvent>;

		class Service {
		public:
			template <class T>
			void post(const T& task);
			void worker_thread();
			void start();
			virtual void onEvent(IEvent* event) = 0 {}
			void stop();
		private:
			boost::asio::io_service _ios;
			boost::asio::io_service::work _work_ctrl{ _ios };
			std::unique_ptr<std::thread> _thPtr;
		};

		
	

	}
}