//  see finite_cell_application/LICENSE.txt
//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: Jun 12, 2017 $
//   Revision:            $Revision: 1.0 $
//
//

#if !defined(KRATOS_FINITE_CELL_ISOGEOMETRIC_STRUCTURAL_APPLICATION_H_INCLUDED)
#define KRATOS_FINITE_CELL_ISOGEOMETRIC_STRUCTURAL_APPLICATION_H_INCLUDED


// System includes
#include <string>
#include <iostream>


// External includes


// Project includes
#include "includes/define.h"
#include "includes/variables.h"
#include "includes/kratos_application.h"
#include "structural_application/custom_elements/kinematic_linear.h"
// #include "structural_application/custom_elements/unsaturated_soils_element_2phase_small_strain.h"
#include "finite_cell_structural_application/custom_elements/extrapolated_kinematic_linear.h"
#include "finite_cell_structural_application/custom_elements/extrapolated_constant_stress_kinematic_linear.h"
#include "finite_cell_structural_application/custom_conditions/line_force_with_function.h"

namespace Kratos
{

    ///@name Kratos Globals
    ///@{

    ///@}
    ///@name Type Definitions
    ///@{

    ///@}
    ///@name Enum's
    ///@{

    ///@}
    ///@name Functions
    ///@{

    ///@}
    ///@name Kratos Classes
    ///@{

    /// Short class definition.
    /** Detail class definition.
    */
    class KratosFiniteCellIsogeometricStructuralApplication : public KratosApplication
    {
    public:
        ///@name Type Definitions
        ///@{

        /// Pointer definition of KratosMultiphaseApplication
        KRATOS_CLASS_POINTER_DEFINITION(KratosFiniteCellIsogeometricStructuralApplication);

        ///@}
        ///@name Life Cycle
        ///@{

        /// Default constructor.
        KratosFiniteCellIsogeometricStructuralApplication();

        /// Destructor.
        virtual ~KratosFiniteCellIsogeometricStructuralApplication(){}

        ///@}
        ///@name Operators
        ///@{


        ///@}
        ///@name Operations
        ///@{

        void Register() override;

        ///@}
        ///@name Access
        ///@{


        ///@}
        ///@name Inquiry
        ///@{


        ///@}
        ///@name Input and output
        ///@{

        /// Turn back information as a string.
        std::string Info() const override
        {
            return "Finite Cell Method for structural simulation";
        }

        /// Print information about this object.
        void PrintInfo(std::ostream& rOStream) const override
        {
            rOStream << Info();
            PrintData(rOStream);
        }

        ///// Print object's data.
        void PrintData(std::ostream& rOStream) const override
        {
            rOStream << "in KratosFiniteCellIsogeometricStructuralApplication:";
            KRATOS_WATCH(KratosComponents<VariableData>::GetComponents().size());
            rOStream << "Variables:" << std::endl;
            KratosComponents<VariableData>().PrintData(rOStream);
            rOStream << std::endl;
            rOStream << "Elements:" << std::endl;
            KratosComponents<Element>().PrintData(rOStream);
            rOStream << std::endl;
            rOStream << "Conditions:" << std::endl;
            KratosComponents<Condition>().PrintData(rOStream);
        }


        ///@}
        ///@name Friends
        ///@{


        ///@}

    protected:
        ///@name Protected static Member Variables
        ///@{


        ///@}
        ///@name Protected member Variables
        ///@{


        ///@}
        ///@name Protected Operators
        ///@{


        ///@}
        ///@name Protected Operations
        ///@{


        ///@}
        ///@name Protected  Access
        ///@{


        ///@}
        ///@name Protected Inquiry
        ///@{


        ///@}
        ///@name Protected LifeCycle
        ///@{


        ///@}

    private:
        ///@name Static Member Variables
        ///@{


        ///@}
        ///@name Member Variables
        ///@{

        const KinematicLinear mKinematicLinearFiniteCellBezier2D;
        const KinematicLinear mKinematicLinearFiniteCellBezier3D;

        const ExtrapolatedKinematicLinear mExtrapolatedKinematicLinearFiniteCellBezier2D;
        const ExtrapolatedKinematicLinear mExtrapolatedKinematicLinearFiniteCellBezier3D;

        const ExtrapolatedConstantStressKinematicLinear mExtrapolatedConstantStressKinematicLinearFiniteCellBezier2D;
        const ExtrapolatedConstantStressKinematicLinear mExtrapolatedConstantStressKinematicLinearFiniteCellBezier3D;

        // const UnsaturatedSoilsElement_2phase_SmallStrain mUnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier2D;
        // const UnsaturatedSoilsElement_2phase_SmallStrain mUnsaturatedSoilsElement2PhaseSmallStrainFiniteCellBezier3D;

        const LineForceWithFunction mLineForceWithFunctionBezier;

        ///@}
        ///@name Private Operators
        ///@{


        ///@}
        ///@name Private Operations
        ///@{


        ///@}
        ///@name Private  Access
        ///@{


        ///@}
        ///@name Private Inquiry
        ///@{


        ///@}
        ///@name Un accessible methods
        ///@{


        /// Assignment operator.
        KratosFiniteCellIsogeometricStructuralApplication& operator=(KratosFiniteCellIsogeometricStructuralApplication const& rOther);

        /// Copy constructor.
        KratosFiniteCellIsogeometricStructuralApplication(KratosFiniteCellIsogeometricStructuralApplication const& rOther);


        ///@}

    }; // Class KratosFiniteCellIsogeometricStructuralApplication

    ///@}


    ///@name Type Definitions
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    ///@}


} // namespace Kratos

#endif // KRATOS_FINITE_CELL_STRUCTURAL_APPLICATION_H_INCLUDED defined

