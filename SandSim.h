#pragma once
#include "common.h"

namespace Tmpl8 {
	class Surface;
}


	class SandSim
	{
	private:
		//sand sim data
		unsigned int* world;

		int collums = 0, rows = 0;

	public:
		SandSim(Tmpl8::Surface* screen);
		void Update(float dt);
		void Draw();
		void PlaceSand(int x, int y, int size = 1);


		//engine data
		Tmpl8::Surface* screen;
	};
	
	enum particleType
	{
		Air, Sand, Water
	};

	struct Particle{
		particleType id;
		Tmpl8::float2 vel{};
		uint32_t lifeTime = 0;
		Tmpl8::float4 color{};

		Particle(particleType pType) : id(pType) {};

	};

	

