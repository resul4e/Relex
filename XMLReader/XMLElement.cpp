#include "XMLElement.h"
#include "XMLReader.h"

rlx::XMLElement_internal* rlx::XMLElement::operator->()
{
	return &(m_reader->m_elements[m_index]);
}
