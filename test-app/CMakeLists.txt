cmake_minimum_required(VERSION 3.16)

project(test-app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 COMPONENTS Quick OpenGL REQUIRED)

qt_add_executable(apptest-app
    main.cpp
    ${CMAKE_TOOLCHAIN_FILE}
)

qt_add_qml_module(apptest-app
    URI test-app
    VERSION 1.0
    QML_FILES main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apptest-app PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apptest-app
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptest-app
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS apptest-app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
