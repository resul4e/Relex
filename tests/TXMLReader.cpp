#include <gtest/gtest.h>
#include "XMLReader.h"
#include "XMLElement.h"

TEST(TXMLReader, Construct)
{
	rlx::XMLReader reader;
}

TEST(TXMLReader, ReadNonExisting)
{
	rlx::XMLReader reader;
	rlx::XMLDocument doc;
	EXPECT_FALSE(reader.Read("NON_EXISTING_PATH_NAME", doc));
}

TEST(TXMLReader, ReadExisting)
{
	rlx::XMLReader reader;
	rlx::XMLDocument doc;
	EXPECT_FALSE(reader.Read("../../../tests/testdata/testApp.gml", doc));
	EXPECT_GT(doc->m_children.size(), 0);
}