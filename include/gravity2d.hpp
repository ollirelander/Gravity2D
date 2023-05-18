#ifndef GRAVITY2D_HPP
#define GRAVITY2D_HPP

#include <vector>

#include "vec2.hpp"
#include "SFML/Graphics.hpp"

namespace gravity2d {
	using namespace vec2;

	struct alignas(32) particle_t {
		vec2f_t position;
		vec2f_t velocity;
		vec2f_t force;

		float mass;
		bool fixed;
	};

	enum class particle_pattern_t {
		circle
	};

	struct cell_t {
		vec2u_t position;
		vec2f_t avarage_force;

		std::vector<particle_t*> particles;
	};

	class particle_cell_map_t /*: sf::Drawable*/ {
	public:
		void create(
			const vec2u_t& map_size,
			const vec2u_t& cell_amount,
			std::size_t particle_amount,
			float particle_mass,
			particle_pattern_t particle_pattern = particle_pattern_t::circle
		) noexcept;

		void update() noexcept;
	private:
		vec2u_t cell_size;
		vec2u_t cell_map_size;
		vec2u_t map_size;

		std::vector<cell_t> cell_map;
		std::vector<particle_t> particles;
	};
}

#endif
