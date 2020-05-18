#include <iostream>

struct Vec2
{
	double x;
	double y;

	Vec2 operator-(const Vec2 &rhs) const
	{
		return Vec2{ x - rhs.x , y - rhs.y };
	}

	Vec2 operator-() const
	{
		return Vec2{ -x, -y };
	}

	Vec2 operator-(double val) const
	{
		return Vec2{ x - val, y - val };
	}

	Vec2 operator+(const Vec2 &rhs) const
	{
		return Vec2{ x + rhs.x , y + rhs.y };
	}

	Vec2 operator+(double val) const
	{
		return Vec2{ x + val , y + val };
	}

	Vec2 operator*(const Vec2 &rhs) const
	{
		return Vec2{ x * rhs.x, y * rhs.y };
	}

	Vec2 operator*(double val) const
	{
		return Vec2{ x * val, y * val };
	}

	Vec2 operator/(const Vec2 &rhs) const
	{
		return Vec2{ x / rhs.x, y / rhs.y };
	}

	Vec2 operator/(double val) const
	{
		return Vec2{ x/val , y/val};
	}

	friend std::ostream &operator<<( std::ostream &output, const Vec2 &v ) {
		output << "(" << v.x << "," << v.y << ")";
		return output;
	}
};


struct Image
{
	double *data;
	size_t width;
	size_t height;
	Image( size_t w, size_t h )
	{
		width = w;
		height = h;
		data = new double[ w * h ];
	}

	double &operator()(size_t x, size_t y)
	{
		return data[ x + y * width ];
	}
};

int main()
{
	Vec2 u{1,1};
	Vec2 v{4,6};
	Vec2 d = -(u+v)*(u-v) / (v*u*2);
	std::cout << d;

	Image img = Image(16, 16);

	// How to get pixel at position (9,12)?
	double val1 = img.data[ 9 + 12 * img.width ];
	// Or
	double val2 = img(9, 12);
	// Modify
	img(9, 9) = 1.0;
}
