set(target ${TESTS})

file(GLOB "*.h*")
file(GLOB "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/gtest")


add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${matrixlib})