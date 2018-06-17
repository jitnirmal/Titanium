#pragma once
#include "Order.h"
#include "ObjectId.h"
#include <map>

namespace titanium {
	namespace op {

		class Trade
		{
		public:
			Trade(long signedQty,
				double price,
				spOrder& spOrd);

			virtual ~Trade();
			long getSignedQty() const;
			double getPrice() const;
			spOrder Trade::getOrigin() const;
			
		private:
			long _signedQty;
			double _price;
			spOrder _spOriginOrder;

		};

		inline long Trade::getSignedQty() const
		{
			return _signedQty;
		}

		inline double Trade::getPrice() const
		{
			return _price;
		}

		inline spOrder Trade::getOrigin() const
		{
			return _spOriginOrder;
		}



	
	}
}
