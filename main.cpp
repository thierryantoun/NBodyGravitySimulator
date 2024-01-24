#include "celestial_objects.hpp"

int main() {

    double G = 6.67430e-11; 
    double dt = 1.0; 

    std::vector<celestial_object> celestial_objects = {
        celestial_object(1.0, 0, 0, 0, 0, 0, 0),celestial_object(2.0,0,0,0,0,0,0) 
    };

    // Boucle de simulation
    for (int t = 0; t < 1000; ++t) {
        updateForcesAndMove(celestial_objects, G, dt);
    }

    std::cout<<celestial_objects[2]<<"\n";

    return 0;
}