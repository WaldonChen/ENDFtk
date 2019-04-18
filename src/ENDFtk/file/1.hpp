template<>
class Type< 1 > : public Base< Type< 1 > >,
                  public SpecialBase< Type< 1 > > {

  friend SpecialBase< Type< 1 > >;

  /* MF1 has a limited number of possible sections */
  static constexpr auto optionalSections =
    hana::make_tuple( 452_c, 455_c, 456_c, 458_c, 460_c );

  /* convenience typedefs */
  using Map =
    decltype
    ( hana::make_map
      ( hana::make_pair
        ( 451_c, std::declval< section::Type< 1, 451 > >() ) /*,
        hana::make_pair
        ( 452_c, std::declval< std::optional< section::Type< 1, 452 > > >() ),
        hana::make_pair
        ( 455_c, std::declval< std::optional< section::Type< 1, 455 > > >() ),
        hana::make_pair
        ( 456_c, std::declval< std::optional< section::Type< 1, 456 > > >() ),
        hana::make_pair
        ( 458_c, std::declval< std::optional< section::Type< 1, 458 > > >() ),
        hana::make_pair
        ( 460_c, std::declval< std::optional< section::Type< 1, 460 > > >() ) )
        */
        ) );

  /* fields */
  Map sectionMap;

  /* static functions */
  #include "ENDFtk/file/1/src/read.hpp"
  // #include "ENDFtk/file/1/src/fill.hpp"

public :

  #include "ENDFtk/file/1/src/ctor.hpp"

  bool
  hasSection( int sectionNo ) const {

    switch( sectionNo ) {

      case 451: return true;
      /*
      case 452: return this->sectionMap[ 452_c ];
      case 455: return this->sectionMap[ 455_c ];
      case 456: return this->sectionMap[ 456_c ];
      case 458: return this->sectionMap[ 458_c ];
      case 460: return this->sectionMap[ 460_c ];
      */
      default: return false;
    }
  }

  static constexpr int fileNumber() { return 1; }

  #include "ENDFtk/file/1/src/print.hpp"
};
