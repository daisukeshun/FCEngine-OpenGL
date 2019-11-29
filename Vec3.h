#ifndef VECTOR_H
#define VECTOR_H

class vec3{
	public:
		float x, y, z, w;
		float length;
		float array[3];
		vec3();
		vec3(float x, float y);
		vec3(float x, float y, float z);

		float dot(const vec3& vec);
		vec3 cross(const vec3& vec);
		vec3 cross(const vec3& a, const vec3& b);
		void normalize();

		void set();
		void set(float a, float b);
		void set(float a, float b, float c);

		vec3 operator+(const vec3& vec);
		vec3 operator-(const vec3& vec);
		vec3 operator*(const float num);
		vec3 operator/(const float num);

		vec3 operator+=(const vec3& vec);
		vec3 operator-=(const vec3& vec);
		vec3 operator*=(const float num);
		vec3 operator/=(const float num);

		bool operator==(const vec3& vec);
		bool operator!=(const vec3& vec);

		float * toArray();
};

#endif
