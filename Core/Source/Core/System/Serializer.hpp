#pragma once

#include "ISerializable.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

namespace Core
{
	class Serializer
	{
	public:
		Serializer();
		~Serializer();

		void saveFile(std::string fileName);	
		std::vector<std::string> loadFile(std::string fileName);

		void addData(std::string data);

	private:
		std::vector<std::string> m_Data;

	};
}