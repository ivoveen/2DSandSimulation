#include "SandSim.h"
#include "precomp.h"

SandSim::SandSim(Surface* screen) {
	this->screen = screen;

	sand = (uint*)MALLOC64(SCRWIDTH * SCRHEIGHT * sizeof(uint));

	//init sand grid
	for (int i = 0; i < SCRWIDTH; i++) {
		for (int j = 0; j < SCRHEIGHT; j++) {
			*(sand + i + j * SCRWIDTH) = 0;
		}
	}
	collums = SCRWIDTH / sandSize;
	rows = SCRHEIGHT / sandSize;

}
void SandSim::Update(float dt) {

}

void SandSim::PlaceSand(int x, int y, int size) {
	if(size == 0) size = sandSize;

	for (int i = x - size; i < x + size; i++) {
		for (int j = y - size; j < y + size; j++) {

			if (i >= 0 && i < SCRWIDTH && j >= 0 && j < SCRHEIGHT) {
				*(sand + i + j * SCRWIDTH) = 0xffffff;
			}
		}
	}

}

void SandSim::Draw() {
	int halfSandSize = static_cast<int>(floor(sandSize / 2));

	//draw sand grid
	for (int i = 0; i < SCRWIDTH; i++) {
		for (int j = 0; j < SCRHEIGHT; j++) {
			if (*(sand + i + j * SCRWIDTH) != 0) {
				screen->Bar(i - halfSandSize, j - halfSandSize, i + halfSandSize, j + halfSandSize, *(sand + i + j * SCRWIDTH));
			}

		}
	}
}
