#include "marian.h"
#include "translator/translator.h"
#include "translator/beam_search.h"

int main(int argc, char** argv) {
  using namespace marian;

  auto options = New<Config>(argc, argv, true, true);
  
  auto task = New<TranslateMultiGPU<BeamSearch>>(options);
  
  boost::timer::cpu_timer timer;
  task->run();
  LOG(info, "Total time: {}", timer.format());
  
  return 0;

}