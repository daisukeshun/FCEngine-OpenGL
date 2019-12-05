#pragma once
#include <GL/gl.h>
#ifndef VECTOR_H
#define VECTOR_H

class vec3{
	public:
		GLfloat x, y, z, w;
		GLfloat length;
		GLfloat array[3];
		vec3();
		vec3(GLfloat x, GLfloat y);
		vec3(GLfloat x, GLfloat y, GLfloat z);

		GLfloat dot(const vec3& vec);
		vec3 cross(const vec3& vec);
		vec3 cross(const vec3& a, const vec3& b);
		void normalize();

		void set();
		void set(GLfloat a, GLfloat b);
		void set(GLfloat a, GLfloat b, GLfloat c);

		vec3 operator+(const vec3& vec);
		vec3 operator-(const vec3& vec);
		vec3 operator*(const GLfloat num);
		vec3 operator/(const GLfloat num);

		vec3 operator+=(const vec3& vec);
		vec3 operator-=(const vec3& vec);
		vec3 operator*=(const GLfloat num);
		vec3 operator/=(const GLfloat num);

		bool operator==(const vec3& vec);
		bool operator!=(const vec3& vec);

		GLfloat * toArray();
};

#endif
