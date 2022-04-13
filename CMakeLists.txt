cmake_minimum_required(VERSION 3.16)

# uncomment to set a default CXX standard for the external tools like clang-tidy and cppcheck
# and the targets that do not specify a standard.
# If not set, the latest supported standard for your compiler is used
# You can later set fine-grained standards for each target using `target_compile_features`
# Note: linking together projects compiled with different C++ standards may work, but
# it is not recommended because of possible issues with ABI
set(CMAKE_CXX_STANDARD 11)

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

# Note: by default ENABLE_DEVELOPER_MODE is True
# This means that all analysis (sanitizers, static analysis)
# is enabled and all warnings are treated as errors
# if you want to switch this behavior, change TRUE to FALSE
set(ENABLE_DEVELOPER_MODE TRUE CACHE BOOL "Enable 'developer mode'")

# Change this to false if you want to disable warnings_as_errors in developer mode
set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

# Set the project name to your project name
project(timeUtils 
        VERSION "0.0.1" 
        LANGUAGES CXX)

include(${_project_options_SOURCE_DIR}/src/DynamicProjectOptions.cmake)

# enable conan for this project
set(ENABLE_CONAN_DEFAULT ON)

# generate version using project_options
generate_version_file()

# Initialize project_options variable related to this project
# This overwrites `project_options` and sets `project_warnings`
# This also accepts the same arguments as `project_options`.
dynamic_project_options()

# add the cxx standard to project options
target_compile_features(project_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})

option(ENABLE_TESTING "Enable Test Builds" ON)

# Adding the src:
add_subdirectory(src)

if(ENABLE_TESTING)
  enable_testing()
  message("Building Tests. Be sure to check out test/constexpr_tests for constexpr testing")
  add_subdirectory(test)
endif()

