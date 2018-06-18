#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <filesystem>

namespace fs = std::experimental::filesystem;

namespace titanium {
	namespace ordersInt {

		class csvReader {
		private:
			std::string _fileName;
			const char _delim;
		public:
			csvReader(const std::string& fileName, const char delim = ',');
			std::vector<std::vector<std::string>> getData();
		};

	
	} // ordersInt end
} // titanium end