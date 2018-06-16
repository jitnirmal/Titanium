#include "Trade.h"

namespace titanium {
	namespace op {

		Trade::Trade(long signedQty,
			double price,
			Order* origin)
			: _signedQty(signedQty),
			_price(price),
			_origin(origin)
		{
		}

		Trade::~Trade()
		{
		}
	}
}