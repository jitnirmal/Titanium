#pragma once
#include "Event.h"
#include <memory>
#include "Order.h"
namespace titanium {
	namespace ordersInt {

		using ShOrderPtr = std::shared_ptr<op::Order> ;
		class OrderEvtIn : public core::IEvent
		{
		public:
			OrderEvtIn(ShOrderPtr data) :Data(data) {}
			ShOrderPtr Data;
		};

	}
}
