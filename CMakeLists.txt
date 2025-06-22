cmake_minimum_required(VERSION 3.10)

project(aul VERSION 1.0 LANGUAGES CXX)

include_directories("${CMAKE_CURRENT_LIST_DIR}/include")

set(SOURCES
	src/vector.cpp
)

# create shared lib
add_library(aul_shared SHARED ${SOURCES})
set_target_properties(aul_shared PROPERTIES OUTPUT_NAME "aul")

# create static lib
add_library(aul_static STATIC ${SOURCES})
set_target_properties(aul_static PROPERTIES OUTPUT_NAME "aul")

install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib")
install(TARGETS aul_shared aul_static
	LIBRARY DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib"
        ARCHIVE DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib")

add_executable(aul_test
	test/aul_test.cpp
)

target_link_libraries(aul_test PRIVATE aul_static)
target_include_directories(aul_test PRIVATE ../lib/include)

# add ctest support
enable_testing()
add_test(NAME aul_test COMMAND aul_test)
