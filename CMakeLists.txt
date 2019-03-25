cmake_minimum_required( VERSION 3.11 )
project( wmbats_bazaar )

add_subdirectory( external/spdlog )

add_library( wmbats_bazaar INTERFACE )

# Declare the library's C++ version
target_compile_features( wmbats_bazaar INTERFACE cxx_std_17 )

target_link_libraries( wmbats_bazaar INTERFACE spdlog )

target_sources( wmbats_bazaar
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/source/wmbat's_bazaar/delegate.hpp"
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/source/wmbat's_bazaar/file_io.hpp"
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/source/wmbat's_bazaar/message.hpp" )

target_include_directories( wmbats_bazaar INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/source" )