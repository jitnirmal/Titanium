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

		using spEvent = std::shared_ptr<core::IEvent>;

		class Service {
		public:
			template <class T>
			void post(const T& task) {
				_ios.post(task);
			}
			
			void worker_thread();
			void start();
			virtual void onEvent(spEvent event) = 0 {}
			void stop();
		private:
			boost::asio::io_service _ios;
			boost::asio::io_service::work _work_ctrl{ _ios };
			std::unique_ptr<std::thread> _thPtr;
		};

		
	

	}
}
