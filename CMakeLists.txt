#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6)

#Name of the project
project(ice)

# make cmake aware that we have all our header files in the
# include subdirectory (the include path should contain that)
include_directories(../include)
SET(G++_COVERAGE_COMPILE_FLAGS "`mysql_config --include`")
SET(G++_COVERAGE_COMPILE_FLAGS "`mysql_config --libs`")
SET(G++_COVERAGE_LINK_FLAGS    "`mysql_config --include`")
SET(G++_COVERAGE_LINK_FLAGS    "`mysql_config --libs`")
# find_package can include third party packages into cmake
# the pkgconfig tool is included which is used by some libraries
# to find out how they should be used whne compiling
# e.g.,  try on the command line: pkg-config --cflags glib-2.0
find_package(PkgConfig REQUIRED)

# now that we can use pkg-config, let's use it to find everything
# about glib-2.0; everything that is found will be
# prefixed by GLIB_PKG
pkg_check_modules(GTKMM gtkmm-3.0)

#Specify the version being used as well as the language

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /usr/local/Cellar/mysql/5.7.20)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysql)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib)

# the _FOUND postfix will be set if the package has actually been found
if(${GTKMM_FOUND})
  #print message for user:
  #message(STATUS "Found:glib-2.0")
  #make sure "include directories" contains the glib header directories
  include_directories(${GTKMM_INCLUDE_DIRS})
  #make sure "link directories" contains the glib library directories
  link_directories(${GTKMM_LIBRARY_DIRS})
else()
  #print message for user:
  message(FATAL_ERROR "gtkmm+-3.0 not found. It is required. exiting.")
endif()

#Could manually add the sources using the set command as follows:
#set(SOURCES src/global.cpp src/worker_thread.cpp src/main.cpp)
# but we can just use the following to add all cpp files:
file(GLOB SOURCES "*.cpp")

#This tells cmake to create the executable based on those sources
add_executable(ice ${SOURCES})

# tells cmake to use the required libraries (in this case glib)
target_link_libraries (ice ${GTKMM_LIBRARIES} curl mysqlcppconn)
target_compile_features(ice PRIVATE cxx_range_for)
file(GLOB GLADE_FILES "src/*.glade")
file(COPY ${GLADE_FILES} DESTINATION ".")
