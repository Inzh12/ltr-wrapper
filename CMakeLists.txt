cmake_minimum_required(VERSION 3.5)

project(ltr_wrapper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LTR_INCLUDE_PATH "C:/libc++/ltr/include")
set(LTR_LIB_PATH "C:/libc++/ltr/lib/mingw64")

set(CMAKE_INSTALL_PREFIX "C:/libc++/ltr_wrapper")

add_library(
    ltr_wrapper
    src/ltr212_wrapper.cpp
    src/ltr_exception.cpp
)

target_include_directories(ltr_wrapper PRIVATE ${LTR_INCLUDE_PATH})
target_link_directories(ltr_wrapper PRIVATE ${LTR_LIB_PATH})

target_link_libraries(ltr_wrapper ltr212api)

file(GLOB PUBLIC_HEADERS "src/*.h")
set_target_properties(ltr_wrapper PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

install(TARGETS ltr_wrapper
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include)

