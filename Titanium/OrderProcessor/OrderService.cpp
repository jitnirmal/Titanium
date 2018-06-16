#include "OrderService.h"
#include "OrderEvtIn.h"

namespace titanium {
	namespace op {
		void OrderService::onEvent(core::IEvent* event)
		{
			auto OrderEvt = static_cast<ordersInt::OrderEvtIn*>(event);
			auto order = *(OrderEvt->Data);
			
			notifyAllObservers(order);
		}
	}
}