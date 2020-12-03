#ifndef NJOY_ENDFTK_SECTION_1_452
#define NJOY_ENDFTK_SECTION_1_452

// system includes

// other includes
#include "ENDFtk/section.hpp"

namespace njoy {
namespace ENDFtk {
namespace section {

  /**
   *  @class
   *  @brief MF1 MT452 - unimplemented
   */
  template<>
  class Type< 1, 452 > : protected NotImplementedYet< Type< 1, 452 > > {

    friend NotImplementedYet< Type< 1, 452 > >;

  public:

    Type() : NotImplementedYet() {};
    template< typename Iterator >
    Type( HEAD& head, Iterator& begin, const Iterator& end,
          long& lineNumber, int MAT ) :
      NotImplementedYet( head, begin, end,
                         lineNumber, MAT ) {};

    /**
     *  @brief Return the MF number of the section
     */
    static constexpr int fileNumber() { return 1; }

    /**
     *  @brief Return the MT number of the section
     */
    static constexpr int sectionNumber() { return 452; }

    using NotImplementedYet::MF;
    using NotImplementedYet::MT;
    using NotImplementedYet::print;
  };

} // section namespace
} // ENDFtk namespace
} // njoy namespace

#endif
