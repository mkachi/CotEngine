#pragma once

#include "base/CotRule.h"

namespace Cot 
{
	class Color32;
	class COT_API Color final
	{
	public:
		union
		{
			struct
			{
				float r, g, b, a;
			};
			float ToArray[4];
		};

		Color();
		Color(const float red, const float green, const float blue, const float alpha = 1.0f);
		Color(const float* array);
		Color(const Color& color);
		Color(const Color&& color);
		Color(const Color32& color);
		~Color();

		const Color operator+(const Color& color) const;
		const Color operator-(const Color& color) const;
		const Color operator*(const Color& color) const;
		const Color operator/(const Color& color) const;

		const Color operator+(const float value) const;
		const Color operator-(const float value) const;
		const Color operator*(const float value) const;
		const Color operator/(const float value) const;

		Color& operator+=(const Color& color);
		Color& operator-=(const Color& color);
		Color& operator*=(const Color& color);
		Color& operator/=(const Color& color);

		Color& operator+=(const float value);
		Color& operator-=(const float value);
		Color& operator*=(const float value);
		Color& operator/=(const float value);

		Color& operator=(const Color& color);
		Color& operator=(const Color32& color);

		bool operator==(const Color& color) const;
		bool operator!=(const Color& color) const;
		bool operator==(const Color32& color) const;
		bool operator!=(const Color32& color) const;

		bool operator<(const Color&) = delete;
		bool operator>(const Color&) = delete;
		Color operator-() = delete;

		const static Color White;
		const static Color Yellow;
		const static Color Blue;
		const static Color Green;
		const static Color Red;
		const static Color Magenta;
		const static Color Black;
		const static Color Orange;
		const static Color Gray;

	};
}