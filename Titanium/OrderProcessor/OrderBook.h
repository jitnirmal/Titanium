#pragma once
#include "Order.h"
#include "ObjectId.h"
#include <map>

namespace titanium {
	namespace op {

		class OrderBook 
		{
		public:

			OrderBook() = default;
			virtual ~OrderBook() = default;

			void addOrder(const spOrder& order);
			void removeOrder(const spOrder& order);
			
			Order* getOrderById(util::UID) const;
		

			const OrderSet& buyOrders() const;
			const OrderSet& sellOrders() const;

			bool isEmpty() const;


		private:

			OrderSet _buyOrders;
			OrderSet _sellOrders;

		};



		inline const OrderSet& OrderBook::buyOrders() const
		{
			return _buyOrders;
		}

		inline const OrderSet& OrderBook::sellOrders() const
		{
			return _sellOrders;
		}

	
	}
}
