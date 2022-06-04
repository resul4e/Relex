
project("main")

find_package(PugiXML CONFIG REQUIRED)

#Add the main executable.
add_executable("${PROJECT_NAME}" 
                        "main.cpp")

#target_link_libraries("${PROJECT_NAME}" "ReXML")
target_link_libraries("${PROJECT_NAME}" pugixml)

#Set the main executable as the startup project
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")
set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)
set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD_REQUIRED ON)