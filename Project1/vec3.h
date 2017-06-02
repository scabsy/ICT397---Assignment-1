#ifndef VEC3_H
#define VEC3_H

namespace Vector
{
	class vec3
	{
	public:
		vec3() : x(0), y(0), z(0) {}
		vec3(float nx, float ny, float nz)
		{
			x = nx;
			y = ny;
			z = nz;
		}
		float x;
		float y;
		float z;

		float getX() { return x; }
		float getY() { return y; }
		float getZ() { return z; }

		void setX(float f) { x = f; }
		void setY(float f) { y = f; }
		void setZ(float f) { z = f; }
		void set(float nx, float ny, float nz)
		{
			x = nx;
			y = ny;
			z = nz;
		}

		vec3 operator + (const vec3 &right)const
		{
			vec3 newVec;

			newVec.x = x + right.x;
			newVec.y = y + right.y;
			newVec.z = z + right.z;

			return newVec;
		}

		vec3 operator * (const float scale)const
		{
			vec3 newVec;
			newVec.x = x*scale;
			newVec.y = y*scale;
			newVec.z = z*scale;
			return newVec;
		}

		vec3 operator / (const float scale)const
		{
			vec3 newVec;
			newVec.x = x/scale;
			newVec.y = y/scale;
			newVec.z = z/scale;
			return newVec;
		}

	};
}

#endif