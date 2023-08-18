
add_executable(${PROJECT_NAME} main.cpp grid.cpp block.cpp tetromino.cpp game.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/include)

set(GRAPHICLIBS sfml-graphics sfml-window sfml-system)
target_link_libraries(${PROJECT_NAME} PRIVATE ${GRAPHICLIBS})
