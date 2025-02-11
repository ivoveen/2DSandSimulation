#pragma once
#include "common.h"

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
		unsigned int* sand;

		int sandSize = 10;
		int collums = 0, rows = 0;

		//engine data
		Tmpl8::Surface* screen;
	};

