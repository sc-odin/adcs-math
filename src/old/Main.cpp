#include <iostream>
#include <memory>

#include "matplotlibcpp.h"
#include "open3d/Open3D.h"
#include "adcs/Constants.h"
#include "old/TrueEquatorMeanEquinox.h"
#include "old/DTM_12.h"
#include "old/EopSpw.h"
#include "old/MathTimeLib.h"
#include "adcs/MSIS_Vers.h"
#include "old/SGP4.h"
#include "adcs/SGP4DC.h"

#include "simulation/Simulation.h"
#include "old/ADCS.h"

namespace plt = matplotlibcpp;

using namespace open3d;
using adcs::simulation::Simulation;
using adcs::ADCS;

void runSimulation(Simulation * sim) {
    ADCS adcs(sim);
    adcs.run();
}

int main(int argc, char *argv[]) {
    Simulation sim;

    std::thread second(runSimulation, &sim);

    sim.run();
    second.join();

    return 0;
}

void test() {
	
}