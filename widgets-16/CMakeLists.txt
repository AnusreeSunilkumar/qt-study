cmake_minimum_required(VERSION 3.19)
project(widgets-16 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

qt_add_executable(widgets-16
    WIN32 MACOSX_BUNDLE
    main.cpp
    dialog.cpp
    dialog.h
    dialog.ui
    resources.qrc
    selections.h selections.cpp selections.ui
)

target_link_libraries(widgets-16
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS widgets-16
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET widgets-16
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
