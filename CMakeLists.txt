cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME my-project)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

set(VULKAN_SDK "C:/VulkanSDK/1.4.363.1")

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${VULKAN_SDK}/Include"
)

target_link_directories(${PROJECT_NAME}
    PRIVATE
        "${VULKAN_SDK}/Lib"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        stdc++exp
        vulkan-1
        volk
        shaderc_combined
        SDL3
)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
) 

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCES}
)