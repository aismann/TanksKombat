#ifndef  _ENGINE_H_
#define  _ENGINE_H_

#include "axys.h"
#include "Math\Pos2.h"
#include <string>
#include <array>
#include <sstream>

#define GAME_TITLE "Tanks Kombat"
#define GAME_VERSION "1.0.15"

static const int DESIGN_WIDTH = 640;
static const int DESIGN_HEIGHT = 480;
static const int TILE_SIZE = 32;
static const bool DISPLAY_STATS = false;

static const float JOYSTICK_SCALE = 0.6f;

#if AX_TARGET_PLATFORM == AX_PLATFORM_WINRT
static const ax::Point JOYSTICK_OFFSET = ax::Point(40, 8);
#else
static const ax::Point JOYSTICK_OFFSET = ax::Point(8, 8);
#endif

static const ax::Point FIRE_BUTTON_OFFSET = ax::Point(8, 48);

#define FONT_MAIN "fonts/main_font.png", 17, 16, ' '
#define FONT_LOGO "fonts/logo_font.png", 32, 32, ' '

#ifndef NDEBUG
#define SCENE_TRANSITION false
#define PATHFINDING_DEBUG false
#else
#define SCENE_TRANSITION true
#define PATHFINDING_DEBUG false
#endif

static const char* UD_FULLSCREEN = "fullscreen";
static const char* UD_SCREEN_WIDTH = "screenWidth";
static const char* UD_SCREEN_HEIGHT = "screenHeight";
static const char* UD_MUSIC_VOLUME = "musicVolume";
static const char* UD_SOUND_VOLUME = "soundVolume";
static const char* UD_MUSIC_ENABLED = "musicEnabled";
static const char* UD_SOUND_ENABLED = "soundEnabled";

static const ax::Color3B LIGHTGREEN_COLOR = ax::Color3B(66, 99, 0);
static const ax::Color3B DARKGREEN_COLOR = ax::Color3B(20, 30, 20);

static const int MAX_TEAMS_COUNT = 4;
static const int GRID_MAX_WIDTH = 20;
static const int GRID_MAX_HEIGHT = 14;

//#if (AX_TARGET_PLATFORM == AX_PLATFORM_ANDROID)
//#define stdp stdPatchForMinGW
//#elif (AX_TARGET_PLATFORM == AX_PLATFORM_WIN32)
//#define stdp std
//#else
//#define stdp std
//#endif

static const char* BACKGROUND_MUSIC = "music/main.ogg";

struct TouchEventsFunc
{
	int id;
	std::function<bool(ax::Touch*, ax::Event*)> onTouchBegan;
	std::function<void(ax::Touch*, ax::Event*)> onTouchMoved;
	std::function<void(ax::Touch*, ax::Event*)> onTouchEnded;
	std::function<void(ax::Touch*, ax::Event*)> onTouchCancelled;
};

struct KeyboardEventsFunc
{
	int id;
	std::function<bool(ax::EventKeyboard::KeyCode, ax::Event*)> onKeyPressed;
	std::function<bool(ax::EventKeyboard::KeyCode, ax::Event*)> onKeyReleased;
};

struct Settings
{
	bool fullscreen;
	ax::Size windowsSize;

	int musicVolume;
	int soundVolume;
	bool musicEnabled;
	bool soundEnabled;
};

struct GameSettings
{
	enum class TankType
	{
		NONE = 0, HUMAN, CPU
	};

	enum class MapType
	{
		RANDOM = 0, CA_CAVE, FILE
	};

	enum class MapSize
	{
		SMALL = 0, MEDIUM, LARGE
	};

	std::array<TankType, MAX_TEAMS_COUNT> tankTypes = std::array<TankType, MAX_TEAMS_COUNT> {
		TankType::HUMAN, TankType::CPU, TankType::NONE, TankType::NONE
	};
	MapType mapType = MapType::RANDOM;
	MapSize mapSize = MapSize::MEDIUM;
	std::string map;
	std::string currentGameMode;
};

struct GameMode
{
	int startLives = 5;
	int startAmmo = 20;
	float ghostTime = 3.0f;
	float newBonusTime = 5.0f;
	int ammoInBonus = 10;

	static GameMode createFromDict(const ax::ValueMap& dict);
	void writeToDict(ax::ValueMap& dict) const;
};

enum class LayerZOrder
{
	BACKGROUND = 0, GRID, GROUND, WALL, OBJECTS, HUD, MODAL_DIALOGS
};

enum class Team
{
	RED = 0, BLUE, GREEN, YELLOW
};

const std::array<ax::Color3B, MAX_TEAMS_COUNT> teamColors = {
	ax::Color3B(255, 128, 128), ax::Color3B(128, 128, 255),
	ax::Color3B(255, 128, 255), ax::Color3B(255, 255, 128)
};

enum class TankAction
{
	MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, FIRE
};

using KeyMap = std::map<ax::EventKeyboard::KeyCode, TankAction>;

class BaseScene;

class Engine
{
public:
	static Engine* getInstance();
	static void destroyInstance();

	struct Settings Settings;
	struct GameSettings GameSettings;
	struct GameMode GameMode;

	void launchGame();
	void enterBackground();
	void enterForeground();
	void loadSettings();
	void saveSettings() const;

	void playSound(const std::string& filePath) const;
	void stopAllSound();
	void playMusic(const std::string& filePath);
	void stopMusic() const;
	void setMusicVolume(float volume) const;

	BaseScene* getCurrentScene() const;

	template<typename T> T* getCurrentScene() const // where T : BaseScene
	{
		return dynamic_cast<T*>(getCurrentScene());
	}

	std::vector<std::string> getGameModes() const;
	void setGameMode(const std::string& modeName);

	void setEnableRecursiveCascading(ax::Node* node, bool enable);

	bool isActionExist(Team team, ax::EventKeyboard::KeyCode code) const;
	TankAction getActionForKey(Team team, ax::EventKeyboard::KeyCode code) const;
private:
	static Engine* _instance;

	ax::ValueMap _modes;
	ax::SpriteBatchNode* _spriteBatch;
	int _bgMusicId = -1;

	std::array<KeyMap, MAX_TEAMS_COUNT> _keymaps;

	Engine();
	void loadGameModes();
	static std::array<KeyMap, MAX_TEAMS_COUNT> createKeyMaps();
	void pauseAudio();
	void resumeAudio();
};

#endif // _ENGINE_H_
