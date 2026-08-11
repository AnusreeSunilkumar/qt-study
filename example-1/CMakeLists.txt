cmake_minimum_required(VERSION 3.19)
project(example-1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(example-1
    main.cpp
    test.h test.cpp
)

target_link_libraries(example-1
    PRIVATE
        Qt::Core
)

install(TARGETS example-1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
