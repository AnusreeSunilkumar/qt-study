cmake_minimum_required(VERSION 3.19)
project(qt-4 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(qt-4
    main.cpp
)

target_link_libraries(qt-4
    PRIVATE
        Qt::Core
)

install(TARGETS qt-4
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
