#pragma once

#include <math.h>

union Vec2
{
	struct
	{
		float x, y;
	};

	struct
	{
		float w, b;
	};

	float e[2];
};

union Vec2int
{
	struct
	{
		int x, y;
	};

	struct
	{
		int w, b;
	};

	int e[2];
};

union Vec3
{
	struct
	{
		float x, y, z;
	};

	struct
	{
		float r, g, b;
	};

	struct
	{
		Vec2 vec2;
	};

	struct
	{
		float n;
		Vec2 vecz;
	};

	float e[3];
};

union Vec3int
{
	struct
	{
		int x, y, z;
	};

	struct 
	{
		Vec2int vec2;
	};

	struct 
	{
		int nothing;
		Vec2int v2;
	};

	float e[3];
};

union Vec4
{
	struct
	{
		float x, y, z, w;
	};

	struct
	{
		Vec3 vec3;
		float w;
	};

	struct
	{
		Vec2 f, s;
	};

	struct
	{
		float r, g, b, a;
	};

	struct
	{
		Vec3 vec3;
		float a;
	};

	float e[4];
};

union Mat4x4
{
	struct
	{
		float x1, x2, x3, x4;
		float y1, y2, y3, y4;
		float z1, z2, z3, z4;
	};

	struct
	{
		float r1, m1, n1, s1;
		float r2, m2, n2, s2;
		float r3, m3, n3, s3;
		float r4, m4, n4, s4;
	};

	float e[16];

	float e2[4][4];
};

union Quat 
{
	struct 
	{
		float w, x, y, z;
	};

	struct 
	{
		float align;
		Vec3 vec3;
	};

	float e[4];
};

struct Form
{
	Vec3 pos;
	Vec3 scale;
	Quat rot;
};

union Rect
{
	struct
	{
		Vec2 min, max;
	};

	struct
	{
		Vec2 center;
		Vec2 dimension;
	};

	struct
	{
		float center, top, bottom, right;
	};

	float e[4];

	float w();
	float h();
	float cx();
	float cy();
	Vec2  dim();
	Vec2  c();
	Vec2  bl();
	Vec2  l();
	Vec2  tl();
	Vec2  t();
	Vec2  tr();
	Vec2  r();
	Vec2  br();
	Vec2  b();

	Rect setC(Vec2 p);
	Rect setDim(Vec2 d);
	Rect setW(float p);
	Rect setH(float p);
	Rect setBL(Vec2 p);
	Rect setTL(Vec2 p);
	Rect setTR(Vec2 p);
	Rect setBR(Vec2 p);
	Rect setL(float p);
	Rect setT(float p);
	Rect setR(float p);
	Rect setB(float p);
	Rect rSetL(float p);
	Rect rSetT(float p);
	Rect rSetR(float p);
	Rect rSetB(float p);
	Rect expand(Vec2 dim);
	Rect expand(float s);
	Rect trans(Vec2 off);
	Rect addBL(Vec2 p);
	Rect addTL(Vec2 p);
	Rect addTR(Vec2 p);
	Rect addBR(Vec2 p);
	Rect addL(float p);
	Rect addT(float p);
	Rect addR(float p);
	Rect addB(float p);

	Rect expand(float l, float b, float r, float t);

	Rect cenDim();
	Rect minMax();

	bool empty();
	bool zero();

};

union Rectint {
	struct {
		Vec2int min;
		Vec2int max;
	};

	struct {
		Vec2int center;
		Vec2int dimension;
	};

	struct {
		int left;
		int bottom;
		int right;
		int top;
	};

	int e[4];

	float w();
	float h();
	float cx();
	float cy();
	Vec2int dim();
	Vec2int c();
};

union Rect3
{
	struct
	{
		Vec3 min;
		Vec3 max;
	};

	struct 
	{
		Vec3 center;
		Vec3 dimension;
	};

	float e[6];

};

union Rect3int
{
	struct 
	{
		Vec3int min, max;
	};
	
	struct
	{
		Vec3int center;
		Vec3int dimension;
	};

	float e[6];
};

//Vec2
inline Vec2 vec2(float a, float b) { return {a, b}; };
inline Vec2 vec2(float a) { return { a, a }; };

inline Vec2 vec2(Vec2int a) { return {a.x, a.y}; }
inline Vec2 vec2(Vec3 a) { return { a.x, a.y }; }

inline Vec2 operator*(Vec2 a, Vec2 b) { return { a.x * b.x, a.y * b.y }; };
inline Vec2 operator*(Vec2 a, float b) { return { a.x * b, a.y * b }; };
inline Vec2 operator*(float b, Vec2 a) { return { a.x*b, a.y*b }; };

inline Vec2& operator*=(Vec2&a, Vec2 b) { return a = a * b; };
inline Vec2& operator*=(Vec2&a, float b) { return a = a * b; };

inline Vec2 operator+(Vec2 a, Vec2 b) { return { a.x + b.x, a.y + b.y }; };
inline Vec2 operator+(Vec2 a, float b) { return { a.x + b, a.y + b }; };

inline Vec2& operator+=(Vec2& a, Vec2 b) { return a = a + b; };
inline Vec2& operator+=(Vec2& a, float b) { return a = a + b; };

inline Vec2 operator-(Vec2 a, Vec2 b) { return { a.x - b.x, a.y - b.y }; };
inline Vec2 operator-(Vec2 a, float b) { return { a.x - b, a.y - b }; };
inline Vec2 operator-(Vec2 a) { return { -a.x, -a.y }; };

inline Vec2& operator-=(Vec2& a, Vec2 b) { return a = a - b; };
inline Vec2& operator-=(Vec2& a, float b) { return a = a - b; };

inline Vec2 operator/(Vec2 a, Vec2 b) { return { a.x / b.x, a.y / b.y }; };
inline Vec2 operator/(Vec2 a, float b) { return { a.x / b, a.y / b }; };

inline Vec2& operator/=(Vec2& a, Vec2 b) { return a = a / b; };
inline Vec2& operator/=(Vec2& a, float b) { return a = a / b; };

inline bool operator==(Vec2 a, Vec2 b) { return (a.x == b.x) && (a.y == b.y); };
inline bool operator!=(Vec2 a, Vec2 b) { return !(a == b); };

inline Vec2 operator+(Vec2 a, Vec2int b) { return { a.x + b.x, a.y + b.y }; }


inline float dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; };
inline float dot(Vec2 a) { return a.x * a.x + a.y * a.y; };
inline float cross(Vec2 a, Vec2 b) { return a.x * b.y - a.y * b.x; };
inline float lenght(Vec2 a) { return sqrt(dot(a)); };
inline Vec2 norm(Vec2 a) { return a / lenght(a); };
inline float determ(Vec2 a, Vec2 b) { return cross(norm(a), norm(b)); };

inline float dotUnitToPercent(float dotProduct) { return 1 - acos(dotProduct) / M_PI_2; }

inline Vec2 clampMin();




