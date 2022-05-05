#pragma once

namespace rlx
{
	struct XMLElement_internal;
	class XMLReader;

	class XMLElement
	{
		friend class XMLReader;
		XMLElement(XMLReader* aReader = nullptr, int aIndex = -1) :m_index(aIndex), m_reader(aReader) {}
	public:
		XMLElement_internal* operator->();

	private:
		int m_index = -1;
		XMLReader* m_reader;
	};
}