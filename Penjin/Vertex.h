#pragma once
#include "Vector4.h"
#include <iostream>
#include <string>

namespace Penjin {
	struct Vertex {
		/// <summary>The position of the vertex</summary>
		float x, y, z;
		/// <summary>The uv-coordinates of the vertex</summary>
		float u, v;
		/// <summary>The normal-vector of the vertex</summary>
		float normX, normY, normZ;
		/// <summary>The color of the vertex</summary>
		float r, g, b, a;

		/// <summary>Constructor</summary>
		/// <param name="position">The position of the vertex</param>
		/// <param name="uv">The ub-coordinates of the vertex</param>
		/// <param name="normal">The normal-vector of the vertex</param>
		/// <param name="color">The color of the vertex</param>
		Vertex(Vector3 position, Vector2 uv, Vector3 normal, Vector4 color)
			: x(position.x),
			y(position.y),
			z(position.z),
			u(uv.x),
			v(uv.y),
			normX(normal.x),
			normY(normal.y),
			normZ(normal.z),
			r(color.x),
			g(color.y),
			b(color.z),
			a(color.w)
		{

		}

	};
}
