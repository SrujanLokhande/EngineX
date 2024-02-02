//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exVector2
{
	float x, y;

	exVector2 operator+(const exVector2& other)
	{
		return exVector2{ this->x + other.x, this->y + other.y };
	}
	exVector2 operator-(const exVector2& other)
	{
		return exVector2{ this->x - other.x, this->y - other.y };
	}
	exVector2 operator*(const exVector2& other)
	{
		return exVector2{ this->x * other.x, this->y * other.y };
	}
	exVector2 operator/(const exVector2& other)
	{
		return exVector2{ this->x / other.x, this->y / other.y };
	}


	exVector2 operator*(const float& other)
	{
		return exVector2{ this->x * other, this->y * other };
	}
	exVector2 operator/(const float& other)
	{
		return exVector2{ this->x / other, this->y / other };
	}

	exVector2& operator+=(const exVector2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	exVector2& operator-=(const exVector2& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	exVector2& operator*=(const exVector2& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
	exVector2& operator/=(const exVector2& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}
};



//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exIntegerVector2
{
	int x, y;
	exIntegerVector2 operator+(const exIntegerVector2& other)
	{
		return exIntegerVector2{ this->x + other.x, this->y + other.y };
	}
	exIntegerVector2 operator-(const exIntegerVector2& other)
	{
		return exIntegerVector2{ this->x - other.x, this->y - other.y };
	}
	exIntegerVector2 operator*(const exIntegerVector2& other)
	{
		return exIntegerVector2{ this->x * other.x, this->y * other.y };
	}
	exIntegerVector2 operator/(const exIntegerVector2& other)
	{
		return exIntegerVector2{ this->x / other.x, this->y / other.y };
	}


	exIntegerVector2 operator*(const int& other)
	{
		return exIntegerVector2{ this->x * other, this->y * other };
	}
	exIntegerVector2 operator/(const int& other)
	{
		return exIntegerVector2{ this->x / other, this->y / other };
	}

	exIntegerVector2& operator+=(const exIntegerVector2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	exIntegerVector2& operator-=(const exIntegerVector2& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	exIntegerVector2& operator*=(const exIntegerVector2& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
	exIntegerVector2& operator/=(const exIntegerVector2& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exColor
{
	unsigned char mColor[4];
};
