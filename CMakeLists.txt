cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set the project name
project(CppShopManagement VERSION 0.1
													DESCRIPTION "A simple shop management application developed with Modern C++."
													LANGUAGES CXX)

include_directories(include)

# set the files
set(SOURCES
	main.cpp
	src/Address.cpp
	src/Customer.cpp
	src/Helper.cpp
	src/Manager.cpp
	src/Person.cpp
	src/Product.cpp
	src/Shop.cpp
	src/User.cpp
	include/Address.h
	include/Customer.h
	include/Header.h
	include/Helper.h
	include/Manager.h
	include/Person.h
	include/Product.h
	include/Shop.h
	include/User.h)

add_executable(CppShopManagement ${SOURCES})

install(TARGETS CppShopManagement DESTINATION bin)