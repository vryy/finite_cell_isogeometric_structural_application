set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("**** configuring KratosFiniteCellIsogeometricStructuralApplication ****")

######### add include directory here
include_directories( ${CMAKE_SOURCE_DIR}/kratos )
include_directories( ${CMAKE_SOURCE_DIR}/applications )
include_directories( ${CMAKE_SOURCE_DIR}/applications/FINITE_CELL_ISOGEOMETRIC_APPLICATION )
include_directories( ${CMAKE_SOURCE_DIR}/applications/isogeometric_application )
include_directories( ${CMAKE_SOURCE_DIR}/applications/structural_application )
#######################################################################

######### add compilation units here
set( KRATOS_FINITE_CELL_ISOGEOMETRIC_APPLICATION_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/finite_cell_isogeometric_structural_application.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/custom_python/finite_cell_isogeometric_structural_python_application.cpp
)
#######################################################################

## define library Kratos which defines the basic python interface
add_library(KratosFiniteCellIsogeometricStructuralApplication SHARED ${KRATOS_FINITE_CELL_ISOGEOMETRIC_APPLICATION_SOURCES})
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication KratosCore)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication KratosFiniteCellApplication)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication KratosFiniteCellStructuralApplication)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication KratosIsogeometricApplication)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication KratosStructuralApplication)
set_target_properties(KratosFiniteCellIsogeometricStructuralApplication PROPERTIES PREFIX "")
install(TARGETS KratosFiniteCellIsogeometricStructuralApplication DESTINATION libs )
#######################################################################

## changing the .dll suffix to .pyd for Windows compatibility
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set_target_properties(KratosFiniteCellIsogeometricStructuralApplication PROPERTIES SUFFIX .pyd)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
#######################################################################

## install application's python script if required
if(${INSTALL_PYTHON_FILES} MATCHES ON)
  get_filename_component (CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/python_scripts DESTINATION applications/${CURRENT_DIR_NAME}  FILES_MATCHING PATTERN "*.py"  PATTERN ".svn" EXCLUDE)
endif(${INSTALL_PYTHON_FILES} MATCHES ON)
#######################################################################

## Add to the KratosMultiphysics Python module
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/FiniteCellIsogeometricStructuralApplication.py" DESTINATION KratosMultiphysics )
#######################################################################
