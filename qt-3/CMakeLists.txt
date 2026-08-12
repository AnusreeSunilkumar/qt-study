cmake_minimum_required(VERSION 3.19)
project(qt-3 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(qt-3
    main.cpp
    test.h test.cpp
)

target_link_libraries(qt-3
    PRIVATE
        Qt::Core
)

install(TARGETS qt-3
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
