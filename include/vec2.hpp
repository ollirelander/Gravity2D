#ifndef VEC2_HPP
#define VEC2_HPP

#include <type_traits>

namespace vec2 {
	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class vec2_t {
	public:
		constexpr vec2_t(T first = 0, T second = 0) noexcept
			: x(static_cast<T>(first)), y(static_cast<T>(second)) {}

		template<typename T2>
		constexpr vec2_t(T2 first = 0, T2 second = 0) noexcept
			: x(static_cast<T>(first)), y(static_cast<T>(second)) {}

		template<typename T2>
		constexpr vec2_t<T> operator+(const vec2_t<T2>& other) const noexcept {
			return { x + static_cast<T>(other.x), y + static_cast<T>(other.y) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator+(T2 num) const noexcept {
			return { x + static_cast<T>(num), y + static_cast<T>(num) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator-(const vec2_t<T2>& other) const noexcept {
			return { x - static_cast<T>(other.x), y - static_cast<T>(other.y) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator-(T2 num) const noexcept {
			return { x - static_cast<T>(num), y - static_cast<T>(num) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator*(const vec2_t<T2>& other) const noexcept {
			return { x * static_cast<T>(other.x), y * static_cast<T>(other.y) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator*(T2 num) const noexcept {
			return { x * static_cast<T>(num), y * static_cast<T>(num) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator/(const vec2_t<T2>& other) const noexcept {
			return { x / static_cast<T>(other.x), y / static_cast<T>(other.y) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator/(T2 num) const noexcept {
			return { x / static_cast<T>(num), y / static_cast<T>(num) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator%(const vec2_t<T2>& other) const noexcept {
			return { x % static_cast<T>(other.x), y % static_cast<T>(other.y) };
		}

		template<typename T2>
		constexpr vec2_t<T> operator%(T2 num) const noexcept {
			return { x % static_cast<T>(num), y % static_cast<T>(num) };
		}

		T x, y;
	};

	using vec2u_t = vec2_t<std::uint32_t>;
	using vec2i_t = vec2_t<std::int32_t>;
	using vec2f_t = vec2_t<float>;
}

#endif
