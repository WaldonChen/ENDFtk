/**
 *  @brief Constructor
 *
 *  @param[in] order          the order of the (square) correlation matrix
 *  @param[in] i              the i coordinates
 *  @param[in] j              the j coordinates
 *  @param[in] correlations   the correlation values
 *  @param[in] ndigits        the number of digits for compacting (default = 6)
 */
CompactCorrelationMatrix( unsigned int order,
                          std::vector< unsigned int >&& i,
                          std::vector< unsigned int >&& j,
                          std::vector< double >&& correlations,
                          unsigned int ndigits = 6 )
  try : nnn_( order ), i_( std::move( i ) ), j_( std::move( j ) ),
        correlations_( std::move( correlations ) ),
        ndigits_( ndigits ) {

    verifySize( this->i_.size(), this->j_.size(), this->correlations_.size() );
    verifyDigits( this->ndigits_ );
  }
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing a compact correlation "
               "matrix" );
    throw;
  }

private:

/**
 *  @brief Private intermediate constructor
 */
CompactCorrelationMatrix( unsigned int order,
                          std::tuple< std::vector< unsigned int >,
                                      std::vector< unsigned int >,
                                      std::vector< double > >&& data,
                          unsigned int ndigits ) :
  CompactCorrelationMatrix(
      order,
      std::move( std::get< 0 >( data ) ),
      std::move( std::get< 1 >( data ) ),
      std::move( std::get< 2 >( data ) ),
      ndigits ) {}

/**
 *  @brief Private intermediate constructor
 */
template< typename Iterator >
CompactCorrelationMatrix( ControlRecord&& cont,
                          Iterator& begin,
                          const Iterator& end,
                          long& lineNumber,
                          int MAT, int MF, int MT ) :
  CompactCorrelationMatrix(
      verifyUnsigned( cont.L2(), "NNN" ),
      readMatrixElements( begin, end, lineNumber, MAT, MF, MT,
                          verifyUnsigned( cont.L1(), "NDIGITS" ),
                          verifyUnsigned( cont.N1(), "NM" ) ),
      verifyUnsigned( cont.L1(), "NDIGITS" ) ) {}

public:

/**
 *  @brief Constructor (from a buffer)
 *
 *  @tparam Iterator        a buffer iterator
 *
 *  @param[in] it           the current position in the buffer
 *  @param[in] end          the end of the buffer
 *  @param[in] lineNumber   the current line number
 *  @param[in] MAT          the expected MAT number
 *  @param[in] MF           the expected MF number
 *  @param[in] MT           the expected MT number
 */
template< typename Iterator >
CompactCorrelationMatrix( Iterator& it, const Iterator& end, long& lineNumber,
                          int MAT, int MF, int MT ) :
  // no try ... catch: exceptions will be handled in the derived class
  CompactCorrelationMatrix( ControlRecord( it, end, lineNumber, MAT, MF, MT ),
                            it, end, lineNumber, MAT, MF, MT ) {

    Log::info( "Encountered error while constructing a compact correlation "
               "matrix" );
    throw;
  }
