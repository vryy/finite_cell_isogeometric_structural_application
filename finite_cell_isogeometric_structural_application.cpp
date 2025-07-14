//  see finite_cell_application/LICENSE.txt
//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: Feb 10, 2017$
//   Revision:            $Revision: 1.0 $
//
//


// System includes


// External includes


// Project includes
#include "finite_cell_isogeometric_structural_application.h"
#include "isogeometric_application/custom_geometries/geo_1d_bezier.h"
#include "finite_cell_application/custom_geometries/finite_cell_geo_2d_bezier.h"
#include "finite_cell_application/custom_geometries/finite_cell_geo_3d_bezier.h"

namespace Kratos
{
    KRATOS_CREATE_VARIABLE( double, FORCE_MAGNITUDE )

    KratosFiniteCellIsogeometricStructuralApplication::KratosFiniteCellIsogeometricStructuralApplication()
    : KratosApplication()
    , mKinematicLinearFiniteCellBezier2D( 0, Element::GeometryType::Pointer( new FiniteCellGeo2dBezier< Node<3> >() ) )
    , mKinematicLinearFiniteCellBezier3D( 0, Element::GeometryType::Pointer( new FiniteCellGeo3dBezier< Node<3> >() ) )
    , mExtrapolatedKinematicLinearFiniteCellBezier2D( 0, Element::GeometryType::Pointer( new FiniteCellGeo2dBezier< Node<3> >() ) )
    , mExtrapolatedKinematicLinearFiniteCellBezier3D( 0, Element::GeometryType::Pointer( new FiniteCellGeo3dBezier< Node<3> >() ) )
    , mExtrapolatedConstantStressKinematicLinearFiniteCellBezier2D( 0, Element::GeometryType::Pointer( new FiniteCellGeo2dBezier< Node<3> >() ) )
    , mExtrapolatedConstantStressKinematicLinearFiniteCellBezier3D( 0, Element::GeometryType::Pointer( new FiniteCellGeo3dBezier< Node<3> >() ) )
    // , mUnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier2D( 0, Element::GeometryType::Pointer( new FiniteCellGeo2dBezier< Node<3> >() ) )
    // , mUnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier3D( 0, Element::GeometryType::Pointer( new FiniteCellGeo3dBezier< Node<3> >() ) )
    , mLineForceWithFunctionBezier( 0, Element::GeometryType::Pointer( new Geo1dBezier< Node<3> >() ) )
    {}

    void KratosFiniteCellIsogeometricStructuralApplication::Register()
    {
        std::cout << "Initializing KratosFiniteCellIsogeometricStructuralApplication... " << std::endl;

        KRATOS_REGISTER_ELEMENT( "KinematicLinearFiniteCellBezier2D", mKinematicLinearFiniteCellBezier2D )
        KRATOS_REGISTER_ELEMENT( "KinematicLinearFiniteCellBezier3D", mKinematicLinearFiniteCellBezier3D )

        KRATOS_REGISTER_ELEMENT( "ExtrapolatedKinematicLinearFiniteCellBezier2D", mExtrapolatedKinematicLinearFiniteCellBezier2D )
        KRATOS_REGISTER_ELEMENT( "ExtrapolatedKinematicLinearFiniteCellBezier3D", mExtrapolatedKinematicLinearFiniteCellBezier3D )

        KRATOS_REGISTER_ELEMENT( "ExtrapolatedConstantStressKinematicLinearFiniteCellBezier2D", mExtrapolatedConstantStressKinematicLinearFiniteCellBezier2D )
        KRATOS_REGISTER_ELEMENT( "ExtrapolatedConstantStressKinematicLinearFiniteCellBezier3D", mExtrapolatedConstantStressKinematicLinearFiniteCellBezier3D )

        // KRATOS_REGISTER_ELEMENT( "UnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier2D", mUnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier2D )
        // KRATOS_REGISTER_ELEMENT( "UnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier3D", mUnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier3D )

        KRATOS_REGISTER_CONDITION( "LineForceWithFunctionBezier", mLineForceWithFunctionBezier )
    }

} // namespace Kratos

