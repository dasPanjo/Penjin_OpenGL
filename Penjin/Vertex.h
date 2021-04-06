#pragma once
#include "Vector4.h"
#include <iostream>
#include <string>

namespace Penjin {
	struct Vertex {
		/// <summary>The position of the vertex</summary>
		Vector3 position;
		/// <summary>The uv-coordinates of the vertex</summary>
		Vector2 uv;
		/// <summary>The normal-vector of the vertex</summary>
		Vector3 normal;
		/// <summary>The color of the vertex</summary>
		Vector4 color;

		/// <summary>Constructor</summary>
		/// <param name="position">The position of the vertex</param>
		/// <param name="uv">The ub-coordinates of the vertex</param>
		/// <param name="normal">The normal-vector of the vertex</param>
		/// <param name="color">The color of the vertex</param>
		Vertex(Vector3 position, Vector2 uv, Vector3 normal, Vector4 color)
			: position(position),
			uv(uv),
			normal(normal),
			color(color)
		{

		}

		friend std::ostream& operator<<(std::ostream& os, Vertex const& v) {
			return os << v.position;
		}
	};
}
