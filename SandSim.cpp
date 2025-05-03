#include "precomp.h"
#include "SandSim.h"
#include "tmpl8math.h"

SandSim::SandSim(Surface* screen) {
	this->screen = screen;
	collums = SCRWIDTH;
	rows = SCRHEIGHT;
	world = (uint*)MALLOC64(collums * rows * sizeof(uint));

	//init sand grid as 0
	for (int i = 0; i < collums; i++) {
		for (int j = 0; j < rows; j++) {
			*(world + i + j * collums) = 0;
		}
	}
}

void SandSim::Update(float dt) {
	for (int j = 0; j < rows; j++)
	{
		for (int i = collums -1; i > 0; i--)
		{
			unsigned int id = *(world + i + j * collums);
			switch (id)
			{
			default:
				break;
			case particleType::Air:
				break;
			case particleType::Sand:
				if (j == rows-1) break;

				if (*(world + i + (j + 1) * collums) == 0) {
					*(world + i + (j + 1) * collums) = *(world + i + j * collums);
					*(world + i + j * collums) = 0;
				}

				break;
			case particleType::Water:

				break;

			}
		}
	}
}

void SandSim::PlaceSand(int x, int y, int brushSize) {
	for (int i = x - brushSize; i < x + brushSize; i++) {
		for (int j = y - brushSize; j < y + brushSize; j++) {

			if (i >= 0 && i < collums && j >= 0 && j < rows) {
				*(world + i + j * collums) = 1;
			}
		}
	}

}

void SandSim::Draw() {
	
	//draw sand grid
	for (int i = 0; i < collums; i++) {
		for (int j = 0; j < rows; j++) {
			if (*(world + i + j * collums) != 0) {
				screen->Plot(i, j, 0xFFFFFF);
			}

		}
	}
}
