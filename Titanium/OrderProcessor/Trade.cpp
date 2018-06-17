#include "Trade.h"

namespace titanium {
	namespace op {

		Trade::Trade(long signedQty,
			double price,
			spOrder& origin)
			: _signedQty(signedQty),
			_price(price),
			_spOriginOrder(origin)
		{
		}

		Trade::~Trade()
		{
		}
	}
}