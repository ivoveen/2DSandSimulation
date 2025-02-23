#include "SandSim.h"
#include "precomp.h"

SandSim::SandSim(Surface* screen) {
	this->screen = screen;

	map = (uint*)MALLOC64(SCRWIDTH * SCRHEIGHT * sizeof(uint));

	//init sand grid

	memset(map, 0, SCRWIDTH * SCRHEIGHT * sizeof(uint));
	collums = SCRWIDTH / sandSize;
	rows = SCRHEIGHT / sandSize;

}
void SandSim::Update(float dt) {
	
	std::sort(sandParticles.begin(), sandParticles.end(), [](const SandParticle& a, const SandParticle& b) {
		return a.y > b.y; 
	});

	for (int i = 0; i < sandParticles.size(); i++) {
		auto& particle = sandParticles[i];

		if (particle.y < SCRHEIGHT - 1) {
			if (*(map + particle.x + (particle.y + 1) * SCRWIDTH) <= 0) {
				//sand falls when nothing is below it.

				*(map + particle.x + (particle.y + 1) * SCRWIDTH) = particle.color;
				*(map + particle.x + particle.y * SCRWIDTH) = 0;
				particle.y++;

			}
		}
	}

}

void SandSim::PlaceSand(int x, int y, int size) {
	if(size == 0) size = sandSize;
	int halfSandSize = static_cast<int>(floor(size / 2));

	auto x1 = x - halfSandSize;
	auto y1 = y - halfSandSize;
	auto x2 = x + halfSandSize;
	auto y2 = y + halfSandSize;
	// clipping
	if (x1 < 0) x1 = 0;
	if (x2 >= SCRWIDTH) x2 = SCRWIDTH - 1;
	if (y1 < 0) y1 = 0;
	if (y2 >= SCRHEIGHT) y2 = SCRWIDTH - 1;

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			//dont put sand particles in the same spot.
			if(*(map + i + j * SCRWIDTH) <= 0){
				sandParticles.push_back(SandParticle(i, j, 0xffffff));
			}			
		}
	}

}

void SandSim::Draw() {
	//draw sand grid
	for (int i = 0; i < sandParticles.size(); i++) {
		int x = sandParticles[i].x;
		int y = sandParticles[i].y;
		unsigned int color = sandParticles[i].color;

		*(map + x + y * SCRWIDTH) = color;
		screen->Plot(x,y,color);
	}
		
	
}
