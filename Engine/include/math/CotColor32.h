#pragma once

#include "base/CotRule.h"

namespace Cot 
{
	class Color;
	class COT_API Color32 final
	{
	public:
		union
		{
			struct
			{
				uchar r, g, b, a;
			};
			uchar ToArray[4];
		};

		Color32();
		Color32(const uchar red, const uchar green, const uchar blue, const uchar alpha = 255);
		Color32(const uchar* arr);
		Color32(const Color32& color);
		Color32(const Color32&& color);
		Color32(const Color& color);
		~Color32();

		const Color32 operator+(const Color32& color) const;
		const Color32 operator-(const Color32& color) const;
		const Color32 operator*(const Color32& color) const;
		const Color32 operator/(const Color32& color) const;

		const Color32 operator+(float value) const;
		const Color32 operator-(float value) const;
		const Color32 operator*(float value) const;
		const Color32 operator/(float value) const;

		Color32& operator+=(const Color32& color);
		Color32& operator-=(const Color32& color);
		Color32& operator*=(const Color32& color);
		Color32& operator/=(const Color32& color);

		Color32& operator+=(float value);
		Color32& operator-=(float value);
		Color32& operator*=(float value);
		Color32& operator/=(float value);

		Color32& operator=(const Color32& color);
		Color32& operator=(const Color& color);

		bool operator==(const Color32& color) const;
		bool operator==(const Color& color) const;
		bool operator!=(const Color32& color) const;
		bool operator!=(const Color& color) const;

		bool operator<(const Color32&) = delete;
		bool operator>(const Color32&) = delete;
		Color32 operator-() = delete;

		const static Color32 White;
		const static Color32 Yellow;
		const static Color32 Blue;
		const static Color32 Green;
		const static Color32 Red;
		const static Color32 Magenta;
		const static Color32 Black;
		const static Color32 Orange;
		const static Color32 Gray;

	};

}