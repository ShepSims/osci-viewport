#pragma once

#include <vector>
#include <memory>
#include "../shape/Shape.h"

class FrameSource {
public:
	virtual void parse() = 0;
	virtual std::vector<std::unique_ptr<Shape>> next() = 0;
	virtual bool isActive() = 0;
	virtual void disable() = 0;
	virtual void enable() = 0;
};