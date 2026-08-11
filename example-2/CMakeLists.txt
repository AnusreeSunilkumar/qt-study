cmake_minimum_required(VERSION 3.19)
project(example-2 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(example-2
    main.cpp
)

target_link_libraries(example-2
    PRIVATE
        Qt::Core
)

install(TARGETS example-2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
