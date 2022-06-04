#pragma once
#include <filesystem>
#include <vector>

#include "XMLElement.h"

namespace rlx
{
	class XMLElement;

	struct XMLDocument
	{
		XMLElement& Root() const;

		XMLReader* m_reader;
		size_t m_prolog = INVALID_ELEMENT_INDEX;
		size_t m_root = INVALID_ELEMENT_INDEX;
	};

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

		bool Read(std::filesystem::path aPath, XMLDocument& oDocument);

		XMLElement CreateElement(size_t aParent);

		//	private:

		XMLElement CreateElements(std::ifstream& aStr);


		friend class XMLElement;
		std::vector<XMLElement> m_elements;
		std::vector<XMLElement_internal> m_internalElements;
	};
}
