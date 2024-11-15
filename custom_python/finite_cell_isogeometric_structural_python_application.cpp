//  see finite_cell_application/LICENSE.txt
//
//   Project Name:        Kratos
//   Last modified by:    $Author: hbui $
//   Date:                $Date: Jun 12, 2017 $
//   Revision:            $Revision: 1.0 $
//
//


// System includes


// External includes
#if defined(KRATOS_PYTHON)

// Project includes
#include "includes/define_python.h"
#include "finite_cell_isogeometric_structural_application.h"
#include "custom_python/add_custom_utilities_to_python.h"

namespace Kratos
{

namespace Python
{

    BOOST_PYTHON_MODULE(KratosFiniteCellIsogeometricStructuralApplication)
    {

        using namespace boost::python;

        class_<KratosFiniteCellIsogeometricStructuralApplication, KratosFiniteCellIsogeometricStructuralApplication::Pointer, bases<KratosApplication>, boost::noncopyable>
        ("KratosFiniteCellIsogeometricStructuralApplication");

    }

} // namespace Python.

} // namespace Kratos.

#endif // KRATOS_PYTHON
