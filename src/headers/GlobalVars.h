#pragma once

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;
extern const char* SCR_TITLE;

extern float BgCol[4]; // Default background color



enum FontIndex : int {
	REG_FONT_INDEX = 0,
	SMALL_FONT_INDEX,
	TINY_FONT_INDEX,
};

//const float FONT_SIZE = 28.0f; // comic
const float FONT_SIZE = 20.0f; // comic
const float SMALL_FONT_SIZE = 13.0f;
const float TINY_FONT_SIZE = 10.0f;

constexpr const char* FONT_PATH_MAIN = "Fonts/comic.ttf";

constexpr const char* ROBOTO_REG_PATH = "Fonts/Roboto-Regular.ttf";
constexpr const char* FA_REG_PATH = "Fonts/FA-Regular-400.otf";
constexpr const char* FA_SOLID_PATH = "Fonts/FA-Solid-900.otf";
