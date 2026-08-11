cmake_minimum_required(VERSION 3.19)
project(exercise-5 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(exercise-5
    main.cpp
    test.h test.cpp
)

target_link_libraries(exercise-5
    PRIVATE
        Qt::Core
)

install(TARGETS exercise-5
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
