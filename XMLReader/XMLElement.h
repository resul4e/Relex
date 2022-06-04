#pragma once
#include <limits>

namespace rlx
{
	constexpr size_t INVALID_ELEMENT_INDEX = std::numeric_limits<size_t>::max();

	struct XMLElement_internal;
	class XMLReader;

	class XMLElement
	{
		friend class XMLReader;
		XMLElement(XMLReader* aReader = nullptr, size_t aIndex = -1) :m_index(aIndex), m_reader(aReader) {}
	public:
		XMLElement_internal* operator->();

	private:
		size_t m_index = INVALID_ELEMENT_INDEX;
		XMLReader* m_reader;
	};
}
