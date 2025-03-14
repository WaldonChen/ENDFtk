#ifndef NJOY_ENDFTK_SECTION_1_TABULATEDMULTIPLICITY
#define NJOY_ENDFTK_SECTION_1_TABULATEDMULTIPLICITY

// system includes

// other includes
#include "ENDFtk/macros.hpp"
#include "ENDFtk/TabulationRecord.hpp"

namespace njoy {
namespace ENDFtk {
namespace section{

  /**
   *  @class
   *  @brief Energy dependent fission multiplicity
   *
   *  This class is defined outside of any of the fission multiplicity
   *  section::Type instances since this component is common to all of them.
   *
   *  See ENDF102, section 1.2 for more information.
   */
  class ENDFTK_PYTHON_EXPORT TabulatedMultiplicity : protected TabulationRecord {

  public:

    /* constructors */
    #include "ENDFtk/section/1/TabulatedMultiplicity/src/ctor.hpp"

    /* methods */

    /**
     *  @brief Return the fission multiplicity representation type
     */
    static constexpr int LNU() { return 2; }

    /**
     *  @brief Return the fission multiplicity representation type
     */
    int representation() const { return this->LNU(); }

    /**
     *  @brief Return the incident energy values
     */
    auto E() const { return TabulationRecord::x(); }

    /**
     *  @brief Return the incident energy values
     */
    auto energies() const { return this->E(); }

    /**
     *  @brief Return the fission multiplicity values
     */
    auto NU() const { return TabulationRecord::y(); }

    /**
     *  @brief Return the fission multiplicity values
     */
    auto multiplicities() const { return this->NU(); }

    using TabulationRecord::NP;
    using TabulationRecord::NR;
    using TabulationRecord::numberPoints;
    using TabulationRecord::numberInterpolationRegions;
    using TabulationRecord::INT;
    using TabulationRecord::NBT;
    using TabulationRecord::interpolants;
    using TabulationRecord::boundaries;
    using TabulationRecord::NC;
    using TabulationRecord::print;
  };

} // section namespace
} // ENDFtk namespace
} // njoy namespace

#endif
