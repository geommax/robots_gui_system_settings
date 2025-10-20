cmake_minimum_required(VERSION 3.19)
project(system_settings LANGUAGES CXX)

set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(system_settings
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    headers/style_sheet.h
    resources/fonts/rom_fonts.qrc
    resources/icons/rom_icons.qrc
)

target_link_libraries(system_settings
    PRIVATE
        Qt::Core
    Qt::Gui
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS system_settings
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET system_settings
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
