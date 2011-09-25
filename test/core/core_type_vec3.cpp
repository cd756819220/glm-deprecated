///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2011 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2008-08-31
// Updated : 2011-09-19
// Licence : This source is under MIT License
// File    : test/core/type_vec3.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/glm.hpp>

static int test_vec3_operators()
{
	int Error = 0;
	
	{
		glm::vec3 A(1.0f);
		glm::vec3 B(1.0f);
		bool R = A != B;
		bool S = A == B;

		Error += (S && !R) ? 0 : 1;
	}

	{
		glm::vec3 A(1.0f, 2.0f, 3.0f);
		glm::vec3 B(4.0f, 5.0f, 6.0f);

		glm::vec3 C = A + B;
		Error += C == glm::vec3(5, 7, 9) ? 0 : 1;

		glm::vec3 D = B - A;
		Error += D == glm::vec3(3, 3, 3) ? 0 : 1;

		glm::vec3 E = A * B;
		Error += E == glm::vec3(4, 10, 18) ? 0 : 1;

		glm::vec3 F = B / A;
		Error += F == glm::vec3(4, 2.5, 2) ? 0 : 1;
	}

	return Error;
}

int test_vec3_size()
{
	int Error = 0;
	
	Error += sizeof(glm::vec3) == sizeof(glm::mediump_vec3) ? 0 : 1;
	Error += 12 == sizeof(glm::mediump_vec3) ? 0 : 1;
	Error += sizeof(glm::dvec3) == sizeof(glm::highp_vec3) ? 0 : 1;
	Error += 24 == sizeof(glm::highp_vec3) ? 0 : 1;
	Error += glm::vec3().length() == 3 ? 0 : 1;
	Error += glm::dvec3().length() == 3 ? 0 : 1;
	
	return Error;
}

int main()
{
	int Error = 0;

	Error += test_vec3_operators();
	Error += test_vec3_size();
	
	return Error;
}
