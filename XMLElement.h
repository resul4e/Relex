#pragma once

namespace rlx
{
	struct XMLElement_internal;
	class XMLReader;

	struct XMLElement
	{
		XMLElement_internal* operator->();

	private:
		int m_index;
		XMLReader* m_reader;
	};
}