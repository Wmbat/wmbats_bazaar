cmake_minimum_required( VERSION 3.15 )
project( wmbats_bazaar )

add_subdirectory( external/spdlog )

add_library( wmbats_bazaar INTERFACE )

target_compile_features( wmbats_bazaar 
    INTERFACE 
        cxx_std_17 
)

target_link_libraries( wmbats_bazaar 
    INTERFACE 
        spdlog 
)

target_include_directories( wmbats_bazaar 
    INTERFACE 
        "includes" 
)