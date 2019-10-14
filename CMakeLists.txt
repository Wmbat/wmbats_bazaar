cmake_minimum_required( VERSION 3.15 )
project( wmbats_bazaar )

option( test "Build all test." OFF )

add_library( wmbats_bazaar INTERFACE )

target_compile_features( wmbats_bazaar 
    INTERFACE 
        cxx_std_17 
)

target_link_libraries( wmbats_bazaar 
    INTERFACE 
)

target_include_directories( wmbats_bazaar 
    INTERFACE 
        "includes" 
)

if( test )
   add_subdirectory( external/googletest )
   add_subdirectory( test )
endif( test )
