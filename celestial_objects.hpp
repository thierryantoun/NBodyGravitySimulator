#include <iostream>
#include <vector>
#include <cmath>

struct celestial_object {
    double mass;
    double x, y, z;      // Position
    double vx, vy, vz;   // Vitesse

    celestial_object(double mass, double x, double y, double z, double vx, double vy, double vz) 
        : mass(mass), x(x), y(y), z(z), vx(vx), vy(vy), vz(vz) {}
};

std::ostream& operator<<(std::ostream& os, const celestial_object& obj) {
    os << "Mass: " << obj.mass << ", Position: (" << obj.x << ", " << obj.y << ", " << obj.z << ")"<<", Vitesse: (" << obj.vx << ", " << obj.vy << ", " << obj.vz << ")";
    return os;
}

void updateForcesAndMove(std::vector<celestial_object>& celestial_objects, double G, double dt) {

    const size_t n = celestial_objects.size(); //number of celestial objects

    for (size_t i = 0; i < n; ++i) {

        double fx = 0, fy = 0, fz = 0; 

        for (size_t j = 0; j < n; ++j) {
            if (i == j) continue;
            double dx = celestial_objects[j].x - celestial_objects[i].x;
            double dy = celestial_objects[j].y - celestial_objects[i].y;
            double dz = celestial_objects[j].z - celestial_objects[i].z;
            double distance = sqrt(dx*dx + dy*dy + dz*dz);
            double force = G * celestial_objects[i].mass * celestial_objects[j].mass / (distance * distance);
            fx += force * dx / distance;
            fy += force * dy / distance;
            fz += force * dz / distance;
        }
        celestial_objects[i].vx += dt * fx / celestial_objects[i].mass;
        celestial_objects[i].vy += dt * fy / celestial_objects[i].mass;
        celestial_objects[i].vz += dt * fz / celestial_objects[i].mass;
    }

    for (auto& celestial_object : celestial_objects) {
        celestial_object.x += celestial_object.vx * dt;
        celestial_object.y += celestial_object.vy * dt;
        celestial_object.z += celestial_object.vz * dt;
    }
}