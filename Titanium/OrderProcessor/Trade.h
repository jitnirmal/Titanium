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
				Order* origin = NULL);

			virtual ~Trade();
			long getSignedQty() const;
			double getPrice() const;
			Order* Trade::getOrigin() const;
			
		private:
			long _signedQty;
			double _price;
			Order* _origin;

		};

		inline long Trade::getSignedQty() const
		{
			return _signedQty;
		}

		inline double Trade::getPrice() const
		{
			return _price;
		}

		inline Order* Trade::getOrigin() const
		{
			return _origin;
		}



	
	}
}
