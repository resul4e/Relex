#pragma once
#include <filesystem>
#include <vector>

#include "XMLElement.h"

namespace rlx
{
	class XMLElement;

	struct XMLAttribute_internal
	{
		const char* name;
		const char* value;
	};

	struct XMLElement_internal
	{
		XMLElement m_parent;
		std::vector<XMLElement> m_children;
		std::vector<int> m_attributes;
	};

	class XMLReader
	{
	public:
		XMLReader() = default;
		~XMLReader();

		bool Read(std::filesystem::path aPath, XMLElement& oRoot);

		XMLElement CreateElement(int aParent);

		//	private:

		XMLElement CreateElements(const char* line);


		friend class XMLElement;
		std::vector<XMLElement_internal> m_elements;
	};
}
