# WebCam CMake config file
#
# This file sets the following variables:
# WebCam_FOUND - Always TRUE.
# WebCam_INCLUDE_DIRS - Directories containing the WebCam include files.
# WebCam_IDL_DIRS - Directories containing the WebCam IDL files.
# WebCam_LIBRARIES - Libraries needed to use WebCam.
# WebCam_DEFINITIONS - Compiler flags for WebCam.
# WebCam_VERSION - The version of WebCam found.
# WebCam_VERSION_MAJOR - The major version of WebCam found.
# WebCam_VERSION_MINOR - The minor version of WebCam found.
# WebCam_VERSION_REVISION - The revision version of WebCam found.
# WebCam_VERSION_CANDIDATE - The candidate version of WebCam found.

message(STATUS "Found WebCam-")
set(WebCam_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(WebCam_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Camera/OpenRTM-aist/2.0.1/Components/c++/Camera/include/webcam-"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(WebCam_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Camera/OpenRTM-aist/2.0.1/Components/c++/Camera/include/webcam-/idl")
set(WebCam_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Camera/OpenRTM-aist/2.0.1/Components/c++/Camera/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(WebCam_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Camera/OpenRTM-aist/2.0.1/Components/c++/Camera/include//idl")


if(WIN32)
    set(WebCam_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Camera/OpenRTM-aist/2.0.1/Components/c++/Camera//webcam.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(WebCam_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Camera/OpenRTM-aist/2.0.1/Components/c++/Camera//webcam.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(WebCam_DEFINITIONS ${<dependency>_DEFINITIONS})

set(WebCam_VERSION )
set(WebCam_VERSION_MAJOR )
set(WebCam_VERSION_MINOR )
set(WebCam_VERSION_REVISION )
set(WebCam_VERSION_CANDIDATE )

