#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6)

#Name of the project
project(main)
set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /usr/local/Cellar/mysql/5.7.20)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysql)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib)
add_executable(main main.cpp)
target_link_libraries(main curl mysqlcppconn)
target_compile_features(main PRIVATE cxx_range_for)
