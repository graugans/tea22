cmake_minimum_required (VERSION 3.10.2)

# Set the project name to your project name, template isn't very descriptive
project (exercise-005 VERSION 0.0.1 LANGUAGES CXX)
string(TIMESTAMP BUILD_DATE "%Y-%m-%dT%H:%M:%S")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include dependencies
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(Catch2 3 REQUIRED)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/config.h" @ONLY)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include") # add the output path to the include PATH


# Specify the paths
set(INPUT_IMAGE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/assets/image.jpg")       # Path to the JPG image
set(GENERATED_HEADER_PATH "${CMAKE_CURRENT_BINARY_DIR}/include/image.h")    # Output header file path

# Add a custom command to run the Python script
add_custom_command(
    OUTPUT ${GENERATED_HEADER_PATH}
    COMMAND ${CMAKE_COMMAND} -E env python3 ${CMAKE_CURRENT_SOURCE_DIR}/jpg_to_header.py ${INPUT_IMAGE_PATH} ${GENERATED_HEADER_PATH}
    DEPENDS ${INPUT_IMAGE_PATH}
    COMMENT "Generating header file from image..."
)

# Add a custom target that depends on the generated header file
add_custom_target(generate_image_header ALL DEPENDS ${GENERATED_HEADER_PATH})

# add the executable
add_executable(${PROJECT_NAME} main.cpp ${GENERATED_HEADER_PATH})


# Include the generated header in the project

add_dependencies(${PROJECT_NAME} generate_image_header)
# Add libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
                                        fmt::fmt
                                        CLI11::CLI11)