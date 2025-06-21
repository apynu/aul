cmake_minimum_required(VERSION 3.10)

project(templ VERSION 1.0 LANGUAGES CXX)

include_directories("${CMAKE_CURRENT_LIST_DIR}/include")

set(SOURCES 
	"src/templ.cpp"
)

# create shared lib
add_library(templ_shared SHARED ${SOURCES})
set_target_properties(templ_shared PROPERTIES OUTPUT_NAME "templ")

# create static lib
add_library(templ_static STATIC ${SOURCES})
set_target_properties(templ_static PROPERTIES OUTPUT_NAME "templ")

install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib")
install(TARGETS templ_shared templ_static
	LIBRARY DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib"
        ARCHIVE DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib")

add_executable(templ_test
		"test/templ_test.cpp"
)

target_link_libraries(templ_test PRIVATE templ_static)
target_include_directories(templ_test PRIVATE ../lib/include)

# add ctest support
enable_testing()
add_test(NAME templ_test COMMAND templ_test)
