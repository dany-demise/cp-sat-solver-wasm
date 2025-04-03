#include <stdio.h>
#include <stdlib.h>

#include "or-tools/ortools/sat/cp_model.h"
#include "or-tools/ortools/sat/cp_model.pb.h"
#include "or-tools/ortools/sat/cp_model_solver.h"
#include "or-tools/ortools/util/sorted_interval_list.h"

namespace operations_research {
namespace sat {

void SimpleSatProgram() {
  CpModelBuilder cp_model;

  const Domain domain(0, 2);
  const IntVar x = cp_model.NewIntVar(domain).WithName("x");
  const IntVar y = cp_model.NewIntVar(domain).WithName("y");
  const IntVar z = cp_model.NewIntVar(domain).WithName("z");

  cp_model.AddNotEqual(x, y);

  // Solving part
  const CpSolverResponse response = Solve(cp_model.Build());

  if (response.status() == CpSolverStatus::OPTIMAL ||
      response.status() == CpSolverStatus::FEASIBLE) {
    // Get the solution values and print them
    printf("x = %lld\n", static_cast<long long>(SolutionIntegerValue(response, x)));
    printf("y = %lld\n", static_cast<long long>(SolutionIntegerValue(response, y)));
    printf("z = %lld\n", static_cast<long long>(SolutionIntegerValue(response, z)));
  } else {
    printf("No solution found.\n");
  }
}

}  // namespace sat
}  // namespace operations_research

int main() {
  operations_research::sat::SimpleSatProgram();
  return EXIT_SUCCESS;
}