#include "gravity2d.hpp"

#include <iostream>

constexpr inline float PIf = 3.14159265359;

constexpr inline std::size_t to_index1d(std::size_t x, std::size_t y, std::size_t width) noexcept {
    return y * width + x;
}

namespace gravity2d {
    void particle_cell_map_t::create(
        const vec2u_t& real_map_size,
        const vec2u_t& cell_amount,
        std::size_t particle_amount,
        float particle_mass,
        particle_pattern_t particle_pattern
    ) noexcept {
        cell_size = vec2u_t{
            std::floorf(static_cast<float>(real_map_size.x) / static_cast<float>(cell_amount.x)),
            std::floorf(static_cast<float>(real_map_size.y) / static_cast<float>(cell_amount.y))
        };

        cell_map_size = cell_amount;
        map_size = cell_size * cell_amount;

        cell_map.resize(cell_amount.x * cell_amount.y);
        particles.resize(particle_amount);

        auto particles_it = particles.begin();
        std::size_t particles_per_cell = particle_amount / (cell_amount.x * cell_amount.y);


        for (std::size_t y = 0; y < cell_map_size.y; ++y) {
            for (std::size_t x = 0; x < cell_map_size.x; ++x) {
                cell_t& current_cell = cell_map[to_index1d(x, y, cell_amount.x)];

                current_cell.position = vec2u_t{ x, y } * cell_size;
                current_cell.avarage_force = vec2f_t{ 0.0f, 0.0f };

                switch (particle_pattern) {
                case particle_pattern_t::circle: {
                    vec2u_t center = current_cell.position + (cell_size / 2);
                    std::uint32_t radius = cell_size.x / 2;

                    float angle = 0.0;
                    float next_angle = 2.0f * PIf / static_cast<float>(particles_per_cell);

                    current_cell.particles.resize(particles_per_cell);

                    for (particle_t*& particle : current_cell.particles) {
                        particle = &(*particles_it++);

                        particle->position.x = std::roundf(center.x + radius * std::cosf(angle));
                        particle->position.y = std::roundf(center.y + radius * std::cosf(angle));

                        particle->velocity = { 0.0f, 0.0f };
                        particle->force = { 0.0f, 0.0f };

                        particle->mass = particle_mass;
                        particle->fixed = false;

                        angle += next_angle;
                    }
                } break;
                default: return;
                }
            }
        }
    }

    void particle_cell_map_t::update() noexcept {

    }
}