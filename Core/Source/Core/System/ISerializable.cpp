#include "ISerializable.hpp"

Core::ISerializable::ISerializable()
{
	m_Data = std::stringstream();
}

Core::ISerializable::ISerializable(const ISerializable& orig)
{
	m_Data = std::stringstream();
}

const Core::ISerializable& Core::ISerializable::operator=(const ISerializable& rhs)
{
	m_Data = std::stringstream();
	return *this;
}

void Core::ISerializable::clearData()
{
	m_Data.clear();
}

void Core::ISerializable::enterSubField(std::string subField)
{
	m_Data << std::string(m_SubFieldCount, ' ') << subField << ":\n";
	m_SubFieldCount++;
}

void Core::ISerializable::exitSubField()
{
	m_SubFieldCount--;
	m_SubFieldCount = std::max(m_SubFieldCount, 0);
}
