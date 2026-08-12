cmake_minimum_required(VERSION 3.19)
project(qt-6 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(qt-6
    main.cpp
    cat.h cat.cpp
    toy.h toy.cpp
)

target_link_libraries(qt-6
    PRIVATE
        Qt::Core
)

install(TARGETS qt-6
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
