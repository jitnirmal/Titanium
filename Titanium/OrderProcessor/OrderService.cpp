#include "OrderService.h"
#include "OrderEvtIn.h"

namespace titanium {
	namespace op {
		void OrderService::onEvent(core::spEvent spEvt)
		{
			auto OrderEvt = static_cast<ordersInt::OrderEvtIn*>(&(*spEvt));
			auto spOrder = OrderEvt->Data;
			
			notifyAllObservers(spOrder);
		}
	}
}