#include "Service.h"

namespace titanium {
	namespace core {
		
		template <class T>
		void Service::post(const T& task) {
				_ios.post(task);
		}
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
