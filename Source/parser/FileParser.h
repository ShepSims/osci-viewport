#pragma once

#include "FrameSource.h"
#include "../shape/Shape.h"
#include "../obj/WorldObject.h"
#include "../obj/Camera.h"
#include "../svg/SvgParser.h"
#include "../txt/TextParser.h"
#include "../lua/LuaParser.h"

class FileParser : public FrameSource {
public:
	FileParser();

	void parse(juce::String extension, std::unique_ptr<juce::InputStream>) override;
	std::vector<std::unique_ptr<Shape>> nextFrame() override;
	Vector2 nextSample() override;
	bool isSample() override;
	bool isActive() override;
	void disable() override;
	void enable() override;

	std::shared_ptr<WorldObject> getObject();
	std::shared_ptr<Camera> getCamera();
	std::shared_ptr<SvgParser> getSvg();
	std::shared_ptr<TextParser> getText();
	std::shared_ptr<LuaParser> getLua();

private:
	bool active = true;
	bool sampleSource = false;

	std::shared_ptr<WorldObject> object;
	std::shared_ptr<Camera> camera;
	std::shared_ptr<SvgParser> svg;
	std::shared_ptr<TextParser> text;
	std::shared_ptr<LuaParser> lua;
};