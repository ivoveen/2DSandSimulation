#pragma once
#include "common.h"
#include <vector>
namespace Tmpl8 {
	class Surface;

}

	class SandSim
	{
	public:
		SandSim(Tmpl8::Surface* screen);
		void Update(float dt);
		void Draw();
		void PlaceSand(int x, int y, int size = 0);

	private:
		//sand sim data

		struct SandParticle {
			SandParticle(int x, int y, unsigned int color) : x(x), y(y), color(color) {};
			int x, y;
			unsigned int color;
		};
		unsigned int* map;
		std::vector<SandParticle> sandParticles;
		int sandSize = 10;
		int collums = 0, rows = 0;

		//engine data
		Tmpl8::Surface* screen;
	};

