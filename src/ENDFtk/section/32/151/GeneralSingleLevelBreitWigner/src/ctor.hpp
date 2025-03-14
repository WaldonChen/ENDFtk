//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
GeneralSingleLevelBreitWigner() = default;
#endif

/**
 *  @brief Constructor with scattering radius uncertainty
 *
 *  @param[in] awri      the atomic mass ratio
 *  @param[in] spi       the target spin value
 *  @param[in] ap        the scattering radius
 *  @param[in] dap       the scattering radius uncertainty data
 *  @param[in] nls       the number of l values
 *  @param[in] cshort    the short range covariance blocks
 *  @param[in] clong     the long range covariance blocks
 */
GeneralSingleLevelBreitWigner( double awri, double spi, double ap, double dap,
                               unsigned int nls,
                               std::vector< ShortRangeBreitWignerBlock >&& cshort,
                               std::vector< LongRangeCovarianceBlock >&& clong )
  try : GeneralCovarianceBase( awri, spi, ap, std::move( dap ), nls,
                               std::move( cshort ), std::move( clong ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the Single Level Breit-Wigner representation for "
               "the general covariance format (LCOMP = 1)" );
    throw;
  }

/**
 *  @brief Constructor without scattering radius uncertainty
 *
 *  @param[in] awri      the atomic mass ratio
 *  @param[in] spi       the target spin value
 *  @param[in] ap        the scattering radius
 *  @param[in] nls       the number of l values
 *  @param[in] cshort    the short range covariance blocks
 *  @param[in] clong     the long range covariance blocks
 */
GeneralSingleLevelBreitWigner( double awri, double spi, double ap, unsigned int nls,
                               std::vector< ShortRangeBreitWignerBlock >&& cshort,
                               std::vector< LongRangeCovarianceBlock >&& clong )
  try : GeneralCovarianceBase( awri, spi, ap, nls,
                               std::move( cshort ), std::move( clong ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the Single Level Breit-Wigner representation for "
               "the general covariance format (LCOMP = 1)" );
    throw;
  }

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
GeneralSingleLevelBreitWigner( Iterator& it, const Iterator& end, long& lineNumber,
                               int MAT, int MF, int MT )
  try : GeneralCovarianceBase( it, end, lineNumber, MAT, MF, MT ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the Single Level Breit-Wigner representation for "
               "the general covariance format (LCOMP = 1)" );
    throw;
  }
