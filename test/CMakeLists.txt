cmake_minimum_required( VERSION 3.15 )
project( unit_test )

enable_testing( ) 

add_executable( unit_test )

target_link_libraries( unit_test
   PRIVATE
      wmbats_bazaar
      gtest
      gtest_main
)

target_sources( unit_test
   PRIVATE
      main.cpp
)
