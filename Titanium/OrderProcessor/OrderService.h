#pragma once
#include <iostream>
#include "ObjectId.h"
#include "OrderBook.h"
#include "OrderMatcher.h"
#include <set>
#include <iostream>
#include "Service.h"
#include "Event.h"
#include "Singleton.h"

#include "Observer.h"

namespace titanium {
	namespace op {

		class OrderService : public core::Service, public util::SingletonBase<OrderService>, public util::Observable<spOrder>
		{
		public:
			virtual void onEvent(core::spEvent event) override;
		
		};
	}
}
