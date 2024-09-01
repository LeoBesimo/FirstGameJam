#include "Serializer.hpp"

Core::Serializer::Serializer()
{
}

Core::Serializer::~Serializer()
{
}

void Core::Serializer::saveFile(std::string fileName)
{
	std::ofstream file(fileName, std::ios::out | std::ostream::binary);
	for (std::string& data : m_Data)
	{
		size_t stringSize = data.size();
		file.write(reinterpret_cast<const char*>(&stringSize), sizeof(size_t));
		file.write(&data[0], stringSize);
	}

	file.close();
}

std::vector<std::string> Core::Serializer::loadFile(std::string fileName)
{
	std::vector<std::string> data;
	std::ifstream file(fileName, std::ios::in | std::ostream::binary);

	std::string::size_type size;
	std::string temp;

	while (!file.eof())
	{

		//if (file.eof()) break;
		file.read(reinterpret_cast<char*>(&size), sizeof(size));
		temp.resize(size);
		file.read(&temp[0], size);
		data.push_back(temp);
	}

	file.close();

	data.pop_back();

	return data;
}

void Core::Serializer::addData(std::string data)
{
	//data.pop_back();
	m_Data.push_back(data);
}
