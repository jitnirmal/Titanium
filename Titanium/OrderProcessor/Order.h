#pragma once
#include <iostream>
#include "ObjectId.h"
#include "OrderDef.h"
#include <set>
#include <iostream>  
#include <memory>  

namespace titanium {
	namespace op {

		
		class Order;
		using spOrder = std::shared_ptr<Order>;

		class IdComparator
		{
		public:
			bool operator()(const spOrder, const spOrder) const;
		};

		using OrderSet = std::set<spOrder, IdComparator>;


		class Order 
		{
		public:

			Order()=default;
			virtual ~Order() = default;

			bool isAlive() const noexcept;
			void SetAlive(bool status)  noexcept;
			long getMarketQty() const noexcept;
			void setMarketQty(long qty) noexcept;
			TxnType getTxnType() const noexcept;
			void setTxnType(TxnType type) noexcept;
			double getMarketPrice() const noexcept;
			void setMarketPrice(double price) noexcept;
			util::UID getUniqueId() const noexcept;
			void setUniqueId(util::UID uid) noexcept;
			
			std::string getTxnTypeAsString() const noexcept;

			OrderDef& orderDef();
			friend std::ostream& operator<<(std::ostream& os, const Order& order);
		protected:
			// static order description
			OrderDef	_orderDef;
			bool		_isAlive;
			double   	_marketPrice;
			long		_marketQty;
			util::UID	_uniqueID;
			TxnType     _txnType;
			friend class IdComparator;
		}; 


		inline bool Order::isAlive() const noexcept
		{
			return _isAlive;
		}
	
		inline long Order::getMarketQty() const noexcept
		{
			return _marketQty;
		}
		
		inline void Order::setMarketQty(long qty) noexcept
		{
			_marketQty = qty;
		}

		inline double Order::getMarketPrice() const noexcept
		{
			return _marketPrice;
		}
		inline void Order::setMarketPrice(double price) noexcept
		{
			_marketPrice = price;
		}

		inline void Order::SetAlive(bool status) noexcept
		{
			_isAlive = status;
		}
		inline TxnType Order::getTxnType() const noexcept
		{
			return _txnType;
		}
		inline void Order::setTxnType(TxnType type) noexcept
		{
			_txnType = type;
		}
		inline util::UID  Order::getUniqueId() const noexcept
		{
			return _uniqueID;
		}
		inline void  Order::setUniqueId(util::UID uid) noexcept
		{
			_uniqueID = uid;
		}
	}
}
