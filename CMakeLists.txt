cmake_minimum_required(VERSION 2.8)

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

project(CppShopManagement)

include_directories(include)

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