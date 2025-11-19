message("**** configuring KratosFiniteCellIsogeometricStructuralApplication ****")

######### add compilation units here
set( KRATOS_FINITE_CELL_ISOGEOMETRIC_APPLICATION_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/finite_cell_isogeometric_structural_application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/custom_python/finite_cell_isogeometric_structural_python_application.cpp
)
#######################################################################

## define library Kratos which defines the basic python interface
add_library(KratosFiniteCellIsogeometricStructuralApplication SHARED ${KRATOS_FINITE_CELL_ISOGEOMETRIC_APPLICATION_SOURCES})
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication PRIVATE KratosCore)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication PRIVATE KratosFiniteCellApplication)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication PRIVATE KratosFiniteCellStructuralApplication)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication PRIVATE KratosIsogeometricApplication)
target_link_libraries(KratosFiniteCellIsogeometricStructuralApplication PRIVATE KratosStructuralApplication)
target_compile_definitions(KratosFiniteCellIsogeometricStructuralApplication PRIVATE KRATOS_CORE=IMPORT)
target_compile_definitions(KratosFiniteCellIsogeometricStructuralApplication PRIVATE FINITE_CELL_ISOGEOMETRIC_APPLICATION=EXPORT)
target_compile_definitions(KratosFiniteCellIsogeometricStructuralApplication PRIVATE FINITE_CELL_APPLICATION=IMPORT)
target_compile_definitions(KratosFiniteCellIsogeometricStructuralApplication PRIVATE FINICEL_CELL_STRUCTURAL_APPLICATION=IMPORT)
target_compile_definitions(KratosFiniteCellIsogeometricStructuralApplication PRIVATE ISOGEOMETRIC_APPLICATION=IMPORT)
target_compile_definitions(KratosFiniteCellIsogeometricStructuralApplication PRIVATE STRUCTURAL_APPLICATION=IMPORT)
set_target_properties(KratosFiniteCellIsogeometricStructuralApplication PROPERTIES PREFIX "")
install(TARGETS KratosFiniteCellIsogeometricStructuralApplication DESTINATION libs )
#######################################################################

## changing the .dll suffix to .pyd for Windows compatibility
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set_target_properties(KratosFiniteCellIsogeometricStructuralApplication PROPERTIES SUFFIX .pyd)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# changing the .dylib suffix to .so
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set_target_properties(KratosFiniteCellIsogeometricStructuralApplication PROPERTIES SUFFIX .so)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
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
