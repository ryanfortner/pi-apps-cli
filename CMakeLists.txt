cmake_minimum_required(VERSION 3.16)

project(pi-apps_terminal-C_edition VERSION 0.0.3)

#functions.h
add_library(
	functions
	src/functions.h
	src/functions.c
)

add_executable(papm src/main.c)
target_link_libraries(papm PRIVATE functions)

#install target
install(
	#CODE "execute_process(COMMAND ./install_checks.sh)"
	TARGETS papm
	DESTINATION /usr/local/bin
)

# uninstall target
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
