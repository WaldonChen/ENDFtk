/**
 *  @brief Constructor
 *
 *  @param[in] spi       the target spin value
 *  @param[in] ap        the scattering radius
 *  @param[in] lssf      the self-shielding only flag
 *  @param[in] lvalues   the l values and the resonance parameters
 */
EnergyIndependent( double spi, double ap, bool lssf,
                   std::vector< LValue >&& lvalues ) :
    // no need for a try ... catch: nothing can go wrong here
    spi_( spi ), ap_( ap ), lssf_( lad ),
    lvalues_( std::move( lvalues ) ) {}

private:
/**
 *  @brief Private intermediate constructor
 */
template< typename Iterator >
EnergyIndependent( ControlRecord&& cont,
                   Iterator& it, const Iterator& end, long& lineNumber,
                   int MAT, int MF, int MT ) :
  EnergyIndependent( cont.C1(), cont.C2(), cont.L1(),
                     readLValues( it, end, lineNumber,
                                  MAT, MF, MT, cont.N1() ) ) {}

protected:
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
EnergyIndependent( Iterator& it, const Iterator& end, long& lineNumber,
                   int MAT, int MF, int MT )
  try : EnergyIndependent( ControlRecord( it, end, lineNumber, MAT, MF, MT ),
                           it, end, lineNumber, MAT, MF, MT ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing unresolved resonance "
               "parameters in the Single Level Breit-Wigner representation "
               "with energy independent widths (without fission)" );
    throw;
  }
