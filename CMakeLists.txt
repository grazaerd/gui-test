cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

project(gui)
set(CMAKE_C_FLAGS "-O3 -fuse-ld=lld -falign-functions=16 -falign-labels=16 -falign-loops=16 -falign-jumps=16 -fno-common -fno-record-gcc-switches -DNDEBUG -static -fomit-frame-pointer -fno-asynchronous-unwind-tables -fno-unwind-tables -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,-s")
set(CMAKE_CXX_FLAGS "-O3 -fuse-ld=lld -falign-functions=16 -falign-labels=16 -falign-loops=16 -falign-jumps=16 -lstdc++ -fno-common -fno-record-gcc-switches -DNDEBUG -static -fomit-frame-pointer -fno-unwind-tables -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,-s")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(gui src/main.cpp)
set_target_properties(gui PROPERTIES LINK_FLAGS "-mwindows")

set(fltk "${CMAKE_CURRENT_SOURCE_DIR}/lib/fltk")

add_subdirectory(${fltk})

target_compile_options(gui PRIVATE -Wall -Wuse-after-free=3 -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough)

# remove warnings for third party libraries
target_compile_options(fltk PRIVATE -w)

target_include_directories(gui SYSTEM PRIVATE ${fltk})

target_link_libraries(gui PRIVATE fltk)
