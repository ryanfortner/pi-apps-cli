cmake_minimum_required(VERSION 3.10)

project("pi-apps-cli" VERSION 0.0.4 LANGUAGES C)

set(BIN "pi-apps")

add_compile_definitions(VER="${CMAKE_PROJECT_VERSION}")
add_compile_definitions(NAME="${CMAKE_PROJECT_NAME}")

add_library(functions STATIC
            src/functions.c
            src/include/functions.h
)

add_executable(${BIN} src/main.c)
target_link_libraries(${BIN} functions)

install(
  TARGETS ${BIN}
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
set(CPACK_PACKAGE_NAME "pi-apps-cli")
set(CPACK_PACKAGE_CONTACT "ryankfortner@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION "pi-apps terminal client")
set(CPACK_DEBIAN_PACKAGE_DEPENDS libc6)
set(CPACK_VERSION_MAJOR ${CMAKE_PROJECT_VERSION_MAJOR})
set(CPACK_VERSION_MINOR ${CMAKE_PROJECT_VERSION_MINOR})
set(CPACK_VERSION_PATCH ${CMAKE_PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
include(CPack)
