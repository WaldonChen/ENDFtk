#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk.hpp"

using namespace njoy::ENDFtk;

std::string& cachedTape();
std::string getFile( int MF );

SCENARIO( "Testing generic case using file 3" ){
  std::string file3string = getFile( 3 );
  GIVEN( "a string representation of of File 3" ){
    WHEN( "a file::Type<3> is constructed from the string" ){
      auto begin = file3string.begin();
      auto end = file3string.end();
      long lineNumber = 0;
      
      StructureDivision division( begin, end, lineNumber);
      REQUIRE_NOTHROW( file::Type<3>(division, begin, end, lineNumber ) );
    }
    WHEN( "a file::Type<3> is constructed from a syntaxTree" ){
      auto begin = file3string.begin();
      auto start = file3string.begin();
      auto end = file3string.end();
      long lineNumber = 0;

      StructureDivision division( begin, end, lineNumber);
      syntaxTree::File< std::string::iterator > 
          fileTree( asHead( division ), start, begin, end, lineNumber );
      THEN( "a file::Type<3> can be constructed" ){
        REQUIRE_NOTHROW( fileTree.parse< 3 >( lineNumber ) );
      }
    }
    WHEN( "a file::Type<3> is constructed from the string twice" ){
      std::string twice(file3string.begin(), file3string.end()-81);
      twice += file3string;
      auto begin = twice.begin();
      auto end = twice.end();
      long lineNumber = 0;
      StructureDivision division( begin, end, lineNumber);
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( file::Type<3>(division, begin, end, lineNumber ) );
      }
    }
  } // GIVEN
} // SCENARIO

std::string& cachedTape(){
  static std::string tape =
    njoy::utility::slurpFileToMemory( "n-001_H_001.endf" );
  return tape;
}

std::string getFile( int MF ){
  auto begin = cachedTape().begin();
  auto end = cachedTape().end();
  syntaxTree::Tape< std::string::iterator > tapeTree( begin, end );
  auto fileTree = tapeTree.materialNumber( 125 ).front().fileNumber( MF );
  return std::string( fileTree.buffer().begin(), fileTree.buffer().end() );
}
