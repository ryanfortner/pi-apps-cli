cmake_minimum_required(VERSION 3.16)

project(pi-apps-cli VERSION 0.0.2)

set(PIAPPSCLI_ROOT ${CMAKE_SOURCE_DIR})

add_library(
	functions
	src/functions.h
	src/functions.c
)

add_executable(pi-apps src/main.c)
target_link_libraries(pi-apps PRIVATE functions)

install(
	#CODE "execute_process(COMMAND ./install_checks.sh)"
	TARGETS pi-apps
	DESTINATION /usr/local/bin
)

if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ryan Fortner")
set(CPACK_PACKAGE_CONTACT "ryankfortner@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION "pi-apps terminal client written in c")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6")
set(CPACK_PACKAGE_HOMEPAGE_URL, "https://github.com/ryanfortner/pi-apps-cli")
file(STRINGS "${PIAPPSCLI_ROOT}/src/functions.h" TEMP_STRING REGEX "VER_MAJOR\\s*")
string(REGEX REPLACE "VER_MAJOR" "" TEMP_STRING ${TEMP_STRING})
string(REGEX MATCH "[0-9]" VER_MAJOR ${TEMP_STRING})
file(STRINGS "${PIAPPSCLI_ROOT}/src/functions.h" TEMP_STRING REGEX "VER_MINOR\\s*")
string(REGEX REPLACE "VER_MINOR" "" TEMP_STRING ${TEMP_STRING})
string(REGEX MATCH "[0-9]" VER_MINOR ${TEMP_STRING})
file(STRINGS "${PIAPPSCLI_ROOT}/src/functions.h" TEMP_STRING REGEX "VER_REVISION\\s*")
string(REGEX REPLACE "VER_REVISION" "" TEMP_STRING ${TEMP_STRING})
string(REGEX MATCH "[0-9]" VER_REVISION ${TEMP_STRING})
set(CPACK_PACKAGE_VERSION_MAJOR ${VER_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VER_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VER_REVISION})
set(CPACK_RESOURCE_FILE_LICENSE "${PIAPPSCLI_ROOT}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${PIAPPSCLI_ROOT}/README.md")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
INCLUDE(CPack)