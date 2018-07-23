#include "ctranslate2/utils.h"

#include <mkl.h>

namespace ctranslate2 {

  void init(size_t num_threads) {
    // Set "enhanced performance" VML mode (see
    // https://software.intel.com/en-us/mkl-developer-reference-c-vm-data-types-accuracy-modes-and-performance-tips)
    vmlSetMode(VML_EP);
    if (num_threads > 0) {
      set_num_threads(num_threads);
    }
  }

  void set_num_threads(size_t num_threads) {
    mkl_set_num_threads(num_threads);
  }

  bool support_avx2() {
    return mkl_cbwr_get_auto_branch() >= MKL_CBWR_AVX2;
  }

}