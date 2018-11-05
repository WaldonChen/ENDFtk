#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk.hpp"

using namespace njoy::ENDFtk;

// convenience typedefs
using AverageDecayEnergies = section::Type< 8, 457 >::AverageDecayEnergies;

std::string chunk();
std::string wrongNC();

SCENARIO( "AverageDecayEnergies" ) {

  GIVEN( "valid data for an AverageDecayEnergies" ) {

    std::tuple< double, double > halfLife = { 4.449622e+9, 6.311520e+7 };
    std::vector< std::tuple< double, double > > decayEnergies =
    { { 4.008322e+4, 4.128931e+3 },
      { 5.373671e+3, 3.660206e+2 },
      { 2.441003e+4, 6.191754e+2 } };

    THEN( "an AverageDecayEnergies can be constructed and members can be "
          "tested" ) {
      AverageDecayEnergies chunk( halfLife, std::move( decayEnergies ) );

      auto halfLife = chunk.halfLife();
      REQUIRE( 4.449622e+9 == Approx( std::get< 0 >( halfLife ) ) );
      REQUIRE( 6.311520e+7 == Approx( std::get< 1 >( halfLife ) ) );
      REQUIRE( 3 == chunk.numberDecayEnergies() );
      REQUIRE( 3 == chunk.decayEnergies().size() );
      auto lightParticle = chunk.decayEnergies()[0];
      REQUIRE( 4.008322e+4 == Approx( std::get< 0 >( lightParticle ) ) );
      REQUIRE( 4.128931e+3 == Approx( std::get< 1 >( lightParticle ) ) );
      auto electroMagnetic = chunk.decayEnergies()[1];
      REQUIRE( 5.373671e+3 == Approx( std::get< 0 >( electroMagnetic ) ) );
      REQUIRE( 3.660206e+2 == Approx( std::get< 1 >( electroMagnetic ) ) );
      auto heavyParticle = chunk.decayEnergies()[2];
      REQUIRE( 2.441003e+4 == Approx( std::get< 0 >( heavyParticle ) ) );
      REQUIRE( 6.191754e+2 == Approx( std::get< 1 >( heavyParticle ) ) );

      auto lightParticle2 = chunk.lightParticleDecayEnergy();
      REQUIRE( 4.008322e+4 == Approx( std::get< 0 >( lightParticle2 ) ) );
      REQUIRE( 4.128931e+3 == Approx( std::get< 1 >( lightParticle2 ) ) );
      auto electroMagnetic2 = chunk.electromagneticDecayEnergy();
      REQUIRE( 5.373671e+3 == Approx( std::get< 0 >( electroMagnetic2 ) ) );
      REQUIRE( 3.660206e+2 == Approx( std::get< 1 >( electroMagnetic2 ) ) );
      auto heavyParticle2 = chunk.heavyParticleDecayEnergy();
      REQUIRE( 2.441003e+4 == Approx( std::get< 0 >( heavyParticle2 ) ) );
      REQUIRE( 6.191754e+2 == Approx( std::get< 1 >( heavyParticle2 ) ) );

      REQUIRE( 2 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "a string representation of a valid AverageDecayEnergies" ) {

    std::string string = chunk();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1; 
      
    THEN( "an AverageDecayEnergies can be constructed and members can be "
          "tested" ) {
      AverageDecayEnergies chunk( begin, end, lineNumber, 3580, 8, 457 );

      auto halfLife = chunk.halfLife();
      REQUIRE( 4.449622e+9 == Approx( std::get< 0 >( halfLife ) ) );
      REQUIRE( 6.311520e+7 == Approx( std::get< 1 >( halfLife ) ) );

      REQUIRE( 3 == chunk.numberDecayEnergies() );
      REQUIRE( 3 == chunk.decayEnergies().size() );
      auto lightParticle = chunk.decayEnergies()[0];
      REQUIRE( 4.008322e+4 == Approx( std::get< 0 >( lightParticle ) ) );
      REQUIRE( 4.128931e+3 == Approx( std::get< 1 >( lightParticle ) ) );
      auto electroMagnetic = chunk.decayEnergies()[1];
      REQUIRE( 5.373671e+3 == Approx( std::get< 0 >( electroMagnetic ) ) );
      REQUIRE( 3.660206e+2 == Approx( std::get< 1 >( electroMagnetic ) ) );
      auto heavyParticle = chunk.decayEnergies()[2];
      REQUIRE( 2.441003e+4 == Approx( std::get< 0 >( heavyParticle ) ) );
      REQUIRE( 6.191754e+2 == Approx( std::get< 1 >( heavyParticle ) ) );

      auto lightParticle2 = chunk.lightParticleDecayEnergy();
      REQUIRE( 4.008322e+4 == Approx( std::get< 0 >( lightParticle2 ) ) );
      REQUIRE( 4.128931e+3 == Approx( std::get< 1 >( lightParticle2 ) ) );
      auto electroMagnetic2 = chunk.electromagneticDecayEnergy();
      REQUIRE( 5.373671e+3 == Approx( std::get< 0 >( electroMagnetic2 ) ) );
      REQUIRE( 3.660206e+2 == Approx( std::get< 1 >( electroMagnetic2 ) ) );
      auto heavyParticle2 = chunk.heavyParticleDecayEnergy();
      REQUIRE( 2.441003e+4 == Approx( std::get< 0 >( heavyParticle2 ) ) );
      REQUIRE( 6.191754e+2 == Approx( std::get< 1 >( heavyParticle2 ) ) );

      REQUIRE( 2 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "a valid instance of AverageDecayEnergies" ) {

    std::string string = chunk();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1; 
    AverageDecayEnergies chunk(begin, end, lineNumber, 3580, 8, 457 );

    THEN( "it can be printed" ) {
      std::string buffer;
      auto output = std::back_inserter( buffer );
      chunk.print( output, 3580, 8, 457 );
      REQUIRE( buffer == string );
    }
  } // GIVEN

  GIVEN( "data with a wrong number of decay energies" ) {

    std::tuple< double, double > halfLife = { 4.449622e+9, 6.311520e+7 };
    std::vector< std::tuple< double, double > > decayEnergies =
    { { 4.008322e+4, 4.128931e+3 },
      { 5.373671e+3, 3.660206e+2 },
      { 2.441003e+4, 6.191754e+2 },
      { 1., 20. } };

    THEN( "an exception is thrown" ) {

      REQUIRE_THROWS( AverageDecayEnergies( halfLife,
                                            std::move( decayEnergies ) ) );
    }
  } // GIVEN

  GIVEN( "a string representation with a wrong number of decay energies" ) {

    std::string string = wrongNC();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;

    THEN( "an exception is thrown" ) {

      REQUIRE_THROWS( AverageDecayEnergies( begin, end, lineNumber,
                                            3580, 8, 457 ) );
    }
  } // GIVEN
} // SCENARIO

std::string chunk() {
  return
    " 4.449622+9 6.311520+7          0          0          6          03580 8457     \n"
    " 4.008322+4 4.128931+3 5.373671+3 3.660206+2 2.441003+4 6.191754+23580 8457     \n";
}

std::string wrongNC() {
  return
    " 4.449622+9 6.311520+7          0          0          8          03580 8457     \n"
    " 4.008322+4 4.128931+3 5.373671+3 3.660206+2 2.441003+4 6.191754+23580 8457     \n"
    " 1.000000+0 2.000000+1                                            3580 8457     \n";
}
