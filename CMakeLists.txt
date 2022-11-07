cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

project(color_sequence)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#enable_testing()
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/BFSTraversal.h
        ${INC_DIR}/DFSTraversal.h
        ${INC_DIR}/Engine.h
        ${INC_DIR}/Matrix.h
        ${INC_DIR}/ReadInput.h
        ${INC_DIR}/TraversalArray.h
        ${INC_DIR}/Validations.h
        
        ${SRC_DIR}/main.c
        ${SRC_DIR}/BFSTraversal.c
        ${SRC_DIR}/DFSTraversal.c
        ${SRC_DIR}/Engine.c
        ${SRC_DIR}/Matrix.c
        ${SRC_DIR}/ReadInput.c
        ${SRC_DIR}/TraversalArray.c
        ${SRC_DIR}/Validations.c
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

find_path(test_1 ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_1)
#add_test(test_1 ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_1)
#add_test(test_2 ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_2)
#add_test(test_3 ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_3)
#add_test(test_4 ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_4)

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
