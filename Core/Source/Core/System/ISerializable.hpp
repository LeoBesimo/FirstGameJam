#pragma once
#include <string>
#include <sstream>

namespace Core
{
	template <typename T>
	concept Streamable = requires(std::ostream os, T value)
	{
		{ os << value };
	};

	class ISerializable
	{
	public:

		ISerializable();
		ISerializable(const ISerializable& orig);
		const ISerializable& operator=(const ISerializable& rhs);

		void clearData();

		void enterSubField(std::string subField);
		void serializeData(std::string id, Streamable auto data)
		{
			m_Data << std::string(m_SubFieldCount, ' ') << id << ": " << data << "\n";
		}

		void exitSubField();
		virtual std::string serialize() = 0;

	protected:
		std::stringstream m_Data;
		
	private:
		int m_SubFieldCount = 0;
	};
}