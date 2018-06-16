#include "Service.h"

namespace titanium {
	namespace core {
		
		

	
		void Service::worker_thread() {
			_ios.run();
		}

		void Service::start() {
			_thPtr = std::make_unique<std::thread>(&Service::worker_thread, this);
		}

		void Service::stop() {
			_ios.stop();
		}
		
	

	
	}
}
