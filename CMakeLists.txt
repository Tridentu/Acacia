cmake_minimum_required(VERSION 3.8)

project(Acacia)

set(QT_MIN_VERSION "5.15.2")
set(KF5_MIN_VERSION "5.86.0")

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
  Core
  Widgets
)


find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    I18n
    XmlGui
)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

file(GLOB ACACIA_SRCS src/*.cpp)
file(GLOB ACACIA_HDRS src/*.h src/*.hpp)

add_executable(acacia ${ACACIA_SRCS})

target_link_libraries(acacia
  Qt5::Widgets
  KF5::CoreAddons
  KF5::I18n
  KF5::XmlGui
)

install(TARGETS acacia ${KDE_INSTALL_TARGET_DEFAULT_ARGS})
install(PROGRAMS acacia.desktop DESTINATION ${XDG_APPS_INSTALL_DIR})
install(FILES acacia.notifyrc DESTINATION ${KNOTIFYRC_INSTALL_DIR})
