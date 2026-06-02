cmake_minimum_required (VERSION 3.21.1)

project(DynamicPageLayout VERSION 0.0.1 LANGUAGES C CXX ASM)

find_package(Qul)

qul_add_target(DynamicPageLayout QML_PROJECT DynamicPageLayout.qmlproject)

target_sources(DynamicPageLayout
  PRIVATE
  src/main.cpp
  src/widgetmanager.cpp
  src/clusterstate.cpp
)

target_include_directories(DynamicPageLayout PRIVATE
  src
)


if(QUL_PLATFORM MATCHES "^tviic2d6mlite")
  target_sources(DynamicPageLayout
    PRIVATE
    src/keymanager.cpp
    src/traveo_specific/board_config.cpp
  )

  target_include_directories(DynamicPageLayout PRIVATE
    src/traveo_specific
  )

  target_compile_definitions(DynamicPageLayout PRIVATE TVII_PLATFORM)

  # Reqd for GPIO pins for 6M Lite
  target_compile_definitions(DynamicPageLayout PRIVATE CYT4DNJBZS tviic2d6m CY_MCU_rev_c CY_327BGA_EVKLITE_rev_a RAW_JPEGS_QULRCC)

  list(APPEND CMAKE_MODULE_PATH ${QUL_PLATFORM_TARGET_DIR}/../common/cmake/modules)
  # Old path needed for platform compatibility checks after UL-5159 (renamed folder from tvii-shared to common)
  list(APPEND CMAKE_MODULE_PATH ${QUL_PLATFORM_TARGET_DIR}/../tvii-shared/cmake/modules)
  find_package(TVII-SDK REQUIRED COMPONENTS basic_graphics util freetype)

  target_include_directories(DynamicPageLayout PRIVATE
    ${TVII_SDK_INCLUDE_DIRS}
  )
endif()

app_target_setup_os(DynamicPageLayout)
