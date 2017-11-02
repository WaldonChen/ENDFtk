template< typename BufferIterator, typename Int >
static auto read( hana::true_,
		  Int sectionNo,
		  StructureDivision& structureDivision,
		  BufferIterator& begin,
		  const BufferIterator& end,
		  long& lineNumber,
		  int MAT ){
  if ( structureDivision.tail.MT != sectionNo ){
    Log::error("Required section not found");
    Log::info("Line number: {}", lineNumber - 1 ); 
    Log::info("Expected section number (MT): {}", sectionNo.value );
    throw std::runtime_error( "file::Type<1>::read" );
  }
  
  auto p =
    hana::make_pair( sectionNo,
		     section::Type< sectionNo.value >
		     ( structureDivision, begin, end, lineNumber, MAT ) );
  
  try{
    structureDivision = StructureDivision( begin, end, lineNumber );
  } catch( std::exception& e ) {
    Log::info( "Error while reading structure division"
	       " following section number (MT) {}", sectionNo.value );
    throw e;
  }

  return p;
}

template< typename BufferIterator, typename Int >
static auto read( hana::false_,
		  Int sectionNo,
		  StructureDivision& structureDivision,
		  BufferIterator& begin,
		  const BufferIterator& end,
		  long& lineNumber,
		  int MAT ){
  auto p = 
    hana::make_pair( sectionNo,
		     structureDivision.tail.MT == sectionNo.value ?
		     std::make_optional
		     ( section::Type< sectionNo.value >
		       ( structureDivision, begin, end, lineNumber ) ) :
		     std::nullopt );

  try{
    structureDivision = StructureDivision( begin, end, lineNumber );
  } catch( std::exception& e ) {
    Log::info( "Error while reading structure division following section {}",
	       sectionNo.value );
    throw e;
  }
  
  return p;
}

template< typename Pair, typename BxoufferIterator >
static auto read( Pair&& p,
		  StructureDivision& structureDivision,
		  BufferIterator& begin,xo
		  const BufferIterator& end,
		  long& lineNumber,
		  int MAT ){
  return read( hana::first(p),
	       hana::second(p),
	       structureDivision, begin, end, lineNumber, MAT );
}

template< typename BufferIterator >
static auto read( StructureDivision& structureDivision,
		  BufferIterator& begin,
		  const BufferIterator& end,
		  long& lineNumber,
		  int MAT ){
  return hana::unpack( sections, [&]( auto&&... pairs ){
      return
	hana::make_map
	( read( pairs, structureDivision, begin, end, lineNumber, MAT )... );
    } );
}
