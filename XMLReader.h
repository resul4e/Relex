#pragma once
#include <filesystem>
#include <vector>

namespace rlx
{
	struct XMLElement;

	struct XMLAttribute_internal
	{
		const char* name;
		const char* value;
	};

	struct XMLElement_internal
	{
		int m_parent;
		std::vector<int> m_children;
		std::vector<int> m_attributes;
	};

	class XMLReader
	{
	public:
		XMLReader() = default;
		~XMLReader();

		bool Read(std::filesystem::path aPath, XMLElement& oRoot);

		int CreateElement(int aParent)
		{
			const int index = m_elements.size();

			auto el = new XMLElement_internal();
			el->m_parent = aParent;

			if(aParent != -1)
			{
				m_elements[aParent]->m_children.push_back(index);
			}


			m_elements.push_back(el);
			return index;
		}

//	private:
		friend struct XMLElement;
		std::vector<XMLElement_internal*> m_elements;
	};
}
