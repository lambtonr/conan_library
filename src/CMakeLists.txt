add_library(conan_library 
            HelloWorld.cpp   HelloWorld.hpp)

target_link_libraries(conan_library 
        PRIVATE project_warnings 
                project_options )
            
target_include_directories(conan_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})        

set_target_properties(conan_library PROPERTIES PUBLIC_HEADER "HelloWorld.hpp")
install(TARGETS conan_library DESTINATION "."
        PUBLIC_HEADER DESTINATION include
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )