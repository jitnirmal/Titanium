#pragma once
#include <set>

namespace titanium {
	namespace util {

		template<class TEvent>
		class Observer
		{
		public:
			Observer() {};
			virtual ~Observer() {};

			virtual void onEvent(TEvent&) = 0;

		};

		template<class TEvent>
		class Observable
		{
		public:
			Observable() {};
			virtual ~Observable() {};

			void addObserver(Observer<TEvent>& observer) {
				_observers.insert(&observer);
			}
			void removeObserver(Observer<TEvent>& observer) {
				_observers.erase(&observer);
			}

		protected:
			using Observers = std::set<Observer<TEvent>*>;

			void notifyAllObservers(TEvent& evt) const {
				for (const auto& observer : _observers)
				{
					observer->onEvent(evt);
				}
			}

			bool hasObservers() {
				return !_observers.empty();
			}
			Observers _observers;
		};



	}
}