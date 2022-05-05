project("ReXML")

add_library("${PROJECT_NAME}"  STATIC  
                        "XMLElement.h"
                        "XMLElement.cpp"
                        "XMLReader.h"
                        "XMLReader.cpp")

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)
set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD_REQUIRED ON)