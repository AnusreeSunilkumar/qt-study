cmake_minimum_required(VERSION 3.19)
project(mainwindow-2 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

qt_add_executable(mainwindow-2
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    resources.qrc
    dialog.h dialog.cpp dialog.ui
)

target_link_libraries(mainwindow-2
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS mainwindow-2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET mainwindow-2
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
