#include "ENDFtk/TapeIdentification.hpp"
#include "ENDFtk/StructureDivision.hpp"
#include "ENDFtk/HeadRecord.hpp"
#include "ENDFtk/TextRecord.hpp"
#include "ENDFtk/ControlRecord.hpp"
#include "ENDFtk/DirectoryRecord.hpp"
#include "ENDFtk/ListRecord.hpp"
#include "ENDFtk/InterpolationRecord.hpp"
#include "ENDFtk/TabulationRecord.hpp"
#include "ENDFtk/InterpolationSequenceRecord.hpp"

#ifndef ENDFTK_HPP
#define ENDFTK_HPP

#include <functional>
#include <unordered_map>
#include <complex>
#include <map>

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
#include <variant>
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif

#include <optional>
#include "range/v3/all.hpp"

#include "disco.hpp"
#include "boost/hana.hpp"
#include "Log.hpp"
#include "header-utilities.hpp"

namespace njoy {
namespace ENDFtk {

namespace hana = boost::hana;

inline namespace literals {

using namespace hana::literals;
}

#include "ENDFtk/resonanceParameters.hpp"

}
}

#include "ENDFtk/section/1.hpp"
#include "ENDFtk/section/2.hpp"
#include "ENDFtk/section/3.hpp"
#include "ENDFtk/section/4.hpp"
#include "ENDFtk/section/5.hpp"
#include "ENDFtk/section/6.hpp"
#include "ENDFtk/section/7.hpp"
#include "ENDFtk/section/8.hpp"
#include "ENDFtk/section/12.hpp"
#include "ENDFtk/section/13.hpp"


namespace njoy {
namespace ENDFtk {
#include "ENDFtk/file.hpp"
#include "ENDFtk/syntaxTree.hpp"
}
}

#endif // ENDFTK_HPP

#include "ENDFtk/isRedundant.hpp"
