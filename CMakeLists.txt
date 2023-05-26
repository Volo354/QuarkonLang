cmake_minimum_required(VERSION 3.24)
project(QuarkonCompiler)

set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG PATHS Dependencies/llvm/llvm-project/llvm/build NO_DEFAULT_PATH)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(QuarkonCompiler main.cpp compiler/src/Tokenization.h compiler/src/ASTNode.h compiler/src/Parser.h compiler/src/CodeGeneration.h)

llvm_map_components_to_libnames(llvm_libs support core irreader)

target_link_libraries(QuarkonCompiler ${llvm_libs})

