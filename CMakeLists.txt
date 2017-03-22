#################################################
# cmake file for building DQMCore package
# @author Eté Rémi
# Copyright (c) CNRS / IPNL
CMAKE_MINIMUM_REQUIRED( VERSION 2.6 FATAL_ERROR )
#################################################

###############################
# project name
PROJECT( DQMLoggerQtGui )

SET( ${PROJECT_NAME}_VERSION_MAJOR 0 )
SET( ${PROJECT_NAME}_VERSION_MINOR 0 )
SET( ${PROJECT_NAME}_VERSION_PATCH 0 )

###############################
# Require C++11
INCLUDE( CheckCXXCompilerFlag )

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)

IF( COMPILER_SUPPORTS_CXX11 )
  SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ELSE()
	MESSAGE( SEND_ERROR "DQMCore requires C++11 support. Please upgrade your compiler !" )
ENDIF()

###############################
# Dependencies
LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
INCLUDE( default_settings )

# ----- Find Threads for multithreading -----
FIND_PACKAGE( Threads REQUIRED )

# ----- Find DQMCore package -----
FIND_PACKAGE( DQMCore REQUIRED )
INCLUDE_DIRECTORIES( ${DQMCore_INCLUDE_DIRS} )
LINK_LIBRARIES( ${DQMCore_LIBRARIES} )
ADD_DEFINITIONS ( ${DQMCore_DEFINITIONS} )

# ----- Find DQMNet package -----
FIND_PACKAGE( DQMNet REQUIRED )
INCLUDE_DIRECTORIES( ${DQMNet_INCLUDE_DIRS} )
LINK_LIBRARIES( ${DQMNet_LIBRARIES} )
ADD_DEFINITIONS ( ${DQMNet_DEFINITIONS} )

# ----- Find Qt4 package -----
SET( QT_ROOT_DIR $ENV{QTDIR} )
SET( QT_QMAKE_EXECUTABLE ${QT_ROOT_DIR}/bin/qmake )

FIND_PACKAGE( Qt4 COMPONENTS QtCore QtGui QtNetwork REQUIRED )
INCLUDE_DIRECTORIES( ${QT_INCLUDE_DIRS} )
ADD_DEFINITIONS ( ${QT_DEFINITIONS} )
INCLUDE( ${QT_USE_FILE} )

INCLUDE_DIRECTORIES( BEFORE include )

# require proper c++
ADD_DEFINITIONS( "-pedantic -Wunused-value -O2" )
ADD_DEFINITIONS("-Wno-long-long -Wreturn-type -Werror")

QT4_WRAP_CPP(
  MOC_SRCS
  include/MainWindow.h
)

AUX_SOURCE_DIRECTORY( src SRCS )
ADD_EXECUTABLE( dqm4hep-qt-logging-gui ${SRCS} ${MOC_SRCS} )
TARGET_LINK_LIBRARIES( dqm4hep-qt-logging-gui ${QT_LIBRARIES} )

INSTALL(
    TARGETS dqm4hep-qt-logging-gui
    RUNTIME DESTINATION bin
)

###############################
# display some variables and write them to cache
DISPLAY_STD_VARIABLES()
