cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( Catch2
    GIT_REPOSITORY  https://github.com/catchorg/Catch2
    GIT_TAG         3f0283de7a9c43200033da996ff9093be3ac84dc # tag: v3.3.2
    )

FetchContent_Declare( fast_float
    # GIT_REPOSITORY  https://github.com/fastfloat/fast_float
    # GIT_TAG         f476bc713fda06fbd34dc621b466745a574b3d4c # tag: v6.1.1
    URL               https://github.com/fastfloat/fast_float/archive/refs/tags/v8.0.0.tar.gz
    URL_MD5           c18c85224181b42da65e945152746e41
    DOWNLOAD_DIR      ${CMAKE_SOURCE_DIR}/downloads
    DOWNLOAD_NAME     fast_float-v8.0.0.tar.gz
    )

FetchContent_Declare( pybind11
    GIT_REPOSITORY  https://github.com/pybind/pybind11
    GIT_TAG         5b0a6fc2017fcc176545afe3e09c9f9885283242 # tag: v2.10.4
    )

FetchContent_Declare( range-v3
    # GIT_REPOSITORY  https://github.com/ericniebler/range-v3
    # GIT_TAG         4989f3e9ff2efee1852942bb9328ef121369ba02 # tag: 0.11.0
    URL             https://github.com/ericniebler/range-v3/archive/refs/tags/0.12.0.tar.gz
    URL_MD5         373a795e450fd1c8251df624be784710
    DOWNLOAD_DIR    ${CMAKE_SOURCE_DIR}/downloads
    DOWNLOAD_NAME   range-v3-v0.12.0.tar.gz
    )

FetchContent_Declare( spdlog
    # GIT_REPOSITORY  https://github.com/gabime/spdlog
    # GIT_TAG         ad0e89cbfb4d0c1ce4d097e134eb7be67baebb36 # tag: v1.11.0
    URL             https://github.com/gabime/spdlog/archive/refs/tags/v1.15.1.tar.gz
    URL_MD5         3a8f758489a1bf21403eabf49e78c3a4
    DOWNLOAD_DIR    ${CMAKE_SOURCE_DIR}/downloads
    DOWNLOAD_NAME   spdlog-v1.15.1.tar.gz
    )
set( SPDLOG_BUILD_PIC CACHE INTERNAL BOOL ON )

FetchContent_Declare( tools
    # GIT_REPOSITORY  https://github.com/njoy/tools
    # GIT_TAG         368dbd9bd44754de616c46ffed0f80d2d16d8360 # tag: v0.3.0
    URL             https://github.com/WaldonChen/ENDFtk-tools/archive/refs/tags/v0.4.3.tar.gz
    URL_MD5         0d6df3ba1178a2ef853aefe188351aea
    DOWNLOAD_DIR    ${CMAKE_SOURCE_DIR}/downloads
    DOWNLOAD_NAME   tools-v0.4.3.tar.gz
    )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    # fast_float
    range-v3
    # spdlog
    tools
    )
