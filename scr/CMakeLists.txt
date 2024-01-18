cmake_minimum_required(VERSION 3.5)

project(Klinet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS Sql)


set(PROJECT_SOURCES
        main.cpp
        globals.h
        #login UI
        logindialog.h
        logindialog.cpp
        logindialog.ui
        #admin UI

        #resources
        images.qrc

        #student creator
        studentcreator.cpp
        studentcreator.h
        studentcreator.ui
        #student view
        studentview.h
        studentview.ui
        studentview.cpp
        #student editor
        studentedit.cpp
        studentedit.h
        studentedit.ui
        #damin view
        adminview.cpp
        adminview.h
        adminview.ui
        #contact creator
        contactcreator.cpp
        contactcreator.ui
        contactcreator.h
        #contact editor
        contactedit.h
        contactedit.ui
        contactedit.cpp
        #contact editor searcher
        contactedit_search.cpp
        contactedit_search.h
        contactedit_search.ui
        #contact delete
        contactdelete.cpp
        contactdelete.h
        contactdelete.ui
        #add new score entry
        add_new_score.cpp
        add_new_score.h
        add_new_score.ui
        #delete socre
        delete_score.cpp
        delete_score.h
        delete_score.ui
        #edit score
        edit_score.cpp
        edit_score.h
        edit_score.ui
        #help
        help.cpp
        help.h
        help.ui
        #find_pswd
        find_pswd.cpp
        find_pswd.h
        find_pswd.ui






)




if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Klinet
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Klinet APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Klinet SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Klinet
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Klinet PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Klinet PRIVATE Qt6::Sql)

set_target_properties(Klinet PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Klinet)
endif()
