#include <cassert>

#include "VBadCov.h"


void step(VBadCov& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

int main(void) {
  VBadCov model;

  model.select = 1;
  model.clk = 0;
  model.eval();

  for(model.a = 0; model.a < 2; ++model.a) {
    for(model.b = 0; model.b < 2; ++model.b) {
      step(model);
      assert(model.c == (model.a & model.b));
    }
  }

  Verilated::threadContextp()->coveragep()->write();
}
