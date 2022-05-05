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
	auto el = reader.CreateElement(-1);
	EXPECT_FALSE(reader.Read("NON_EXISTING_PATH_NAME", el));
}

TEST(TXMLReader, ReadExisting)
{
	rlx::XMLReader reader;
	auto el = reader.CreateElement(-1);
	EXPECT_FALSE(reader.Read("../../../tests/testdata/testApp.gml", el));
	EXPECT_GT(el->m_children.size(), 0);
}