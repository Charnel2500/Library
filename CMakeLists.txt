cmake_minimum_required(VERSION 3.21.0)
project(CasinoGames VERSION 0.1.0 LANGUAGES CXX)

add_executable(Library 
    main.cpp
    book.cpp
    library.cpp
    reader.cpp
)

add_custom_target(clean_target
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/*.o ${CMAKE_BINARY_DIR}/Library
)

add_custom_target(pack
    COMMAND ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_BINARY_DIR}/Library.zip"
            "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/book.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/library.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/reader.cpp"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Creating source archive"
)

#commands cmake CMakeLists.txt; make; ./Library; make; make pack; make clean_target
