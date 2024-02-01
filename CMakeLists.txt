cmake_minimum_required(VERSION 3.5.2)
project(checker C)

set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

find_library(IIO_LIBRARY iio)   #Ищем библиотеку libiio. Не забудь ее sudo make install
#find_library(LIBWS_LIBRARY ws) #https://github.com/Theldus/wsServer

#message(LIBWS_LIBRARY="${LIBWS_LIBRARY}")

include(FetchContent)
FetchContent_Declare(
  wsServer
  GIT_REPOSITORY https://github.com/Theldus/wsServer.git
  #GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)

FetchContent_GetProperties(wsServer)

if(NOT wsServer_POPULATED)
  FetchContent_Populate(wsServer)
  message(wsServer_SOURCE_DIR="${wsServer_SOURCE_DIR}")
  message(wsServer_BINARY_DIR="${wsServer_BINARY_DIR}")
  #add_subdirectory(${wsServer_SOURCE_DIR} ${wsServer_BINARY_DIR})
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(include)
add_executable(checker src/main.c src/alg.c src/ws_server.c)

target_link_libraries(checker PUBLIC ${IIO_LIBRARY} ws m)  #{PUBLIC и m чтобы собиралось. ЧТобы подтянуть math
