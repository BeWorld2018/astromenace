/************************************************************************************

	AstroMenace (Hardcore 3D space shooter with spaceship upgrade possibilities)
	Copyright (c) 2006-2018 Mikhail Kurinnoi, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <http://www.gnu.org/licenses/>.


	Web Site: http://www.viewizard.com/
	Project: https://github.com/viewizard/astromenace
	E-mail: viewizard@viewizard.com

*************************************************************************************/

#ifndef STRUCT_H
#define STRUCT_H




//------------------------------------------------------------------------------------
// возможные состояния... для прорисовки и обхода
//------------------------------------------------------------------------------------
enum class eMenuStatus {
	// основное меню
	MAIN_MENU = 1,

	// игра, рассматриваем как еще одно "меню"
	GAME,

	// лучшие результаты
	TOP_SCORES,
	// настройка интерфейса
	INTERFACE,
	// настройка
	OPTIONS,
	// настройка управления
	CONFCONTROL,
	// настройки быстродействия
	OPTIONS_ADVANCED,
	// информация об игре и т.п.
	INFORMATION,
	// кто делал игру
	CREDITS,
	// профайл
	PROFILE,
	// настройка сложности
	DIFFICULTY,
	// выбор миссии
	MISSION,
	// мастерская покупка-усовершенствование корабля
	WORKSHOP
};


// меню настроек в игре (когда уже запустили прохождение миссии)
enum class eGameMenuStatus {
	// основное меню игры
	GAME_MENU = 1,
	// основное меню настроек
	OPTIONS,
	// меню продвинутых настроек
	OPTIONS_ADVANCED,
	// меню настройки интерфейса
	INTERFACE,
	// меню настройки управления
	CONFCONTROL
};


// commands, that should be executed after rendering cycle
enum class eCommand {
	DO_NOTHING = 0,

	// основное меню
	SWITCH_TO_MAIN_MENU = 1,

	// игра
	SWITCH_TO_GAME,

	// лучшие результаты
	SWITCH_TO_TOP_SCORES,
	// настройка интерфейса
	SWITCH_TO_INTERFACE,
	// настройка
	SWITCH_TO_OPTIONS,
	// настройка управления
	SWITCH_TO_CONFCONTROL,
	// настройки быстродействия
	SWITCH_TO_OPTIONS_ADVANCED,
	// информация об игре и т.п.
	SWITCH_TO_INFORMATION,
	// кто делал игру
	SWITCH_TO_CREDITS,
	// профайл
	SWITCH_TO_PROFILE,
	// настройка сложности
	SWITCH_TO_DIFFICULTY,
	// выбор миссии
	SWITCH_TO_MISSION,
	// мастерская покупка-усовершенствование корабля
	SWITCH_TO_WORKSHOP,

	// выключаем воркшоп (готовимся к переходу на игру) (ранее 99)
	TURN_OFF_WORKSHOP_MENU,
	// переход игра-меню (выбор миссии) (ранее 100)
	SWITCH_FROM_GAME_TO_MISSION_MENU,
	// переход игра-главное меню (ранее 101)
	SWITCH_FROM_GAME_TO_MAIN_MENU
};



// -1 - загрузка меню с логотипом
// 0 - загрузка меню без логотипа
// 1 - загрузка игры
enum class eLoading {
	InitialValue	= -2,	// initial value for variables (some fake, not used loading trigger)
	MenuWithLogo	= -1,	// loading menu with logo at game launch
	Menu		=  0,
	Game		=  1
};





enum class eDialogBox {
	None			= -1,	// none
	QuitFromGame		=  0,	// хотим выйти или нет?
	ProfileCreationError	=  1,	// в профайле все занято, не можем создать новую запись
	DeleteProfile		=  2,	// удаление профайла - запрос
	RepairShip		=  3,	// неполный ремонт (не достаточно денег)
	QuitNoSave		=  4,	// хотим выйти или нет?, с предупреждением, что не все сохраним
	QuiToMenuNoSave		=  41,	// выход из игры в меню (основное) с предупреждением, что не все сохраним
	RestartLevelNoSave	=  5,	// хотим рестарт игры?, с предупреждением, что не все сохраним
	ShowShipInfo		=  6,	// вывод данных по кораблю
	ShowWeaponsInfo		=  7,	// вывод данных по оружию
	ShowSystemsInfo		=  8,	// вывод данных по системам
	ProfileTipsAndTricks	=  9,	// подсказки на меню профилей
	ShipyardTipsAndTricks	= 10,	// подсказки на меню шипъярд
	SystemsTipsAndTricks	= 11,	// подсказки на меню системы
	WeaponryTipsAndTricks	= 12,	// подсказки на меню оружейная
	ShortkeyTipsAndTricks	= 13,	// подсказки на горячие клавиши в игре
	StartMissionSecondTime	= 14,	// подсказка, если пытаемся по второму разу пройти миссию
	ChoseLanguage		= 16,	// спрашиваем какой язык при первом старте игры
	RestartOnOptionsChanged	= 17,	// при изменении настроек в самой игре спрашиваем, с предупреждением, что не все сохраним
	RestartOnAdvOptChanged	= 18	// при изменении продвинутых настроек в самой игре, с предупреждением, что не все сохраним
};








//------------------------------------------------------------------------------------
// для выбора в списке режимов разрешения
//------------------------------------------------------------------------------------
struct sVideoModes {
	// ширина
	int W;
	// высота
	int H;
	// битность палитры
	int BPP;
};





//------------------------------------------------------------------------------------
// структура данных профайла игрока
//------------------------------------------------------------------------------------
struct sGameProfile {
	bool	Used;

	char	Name[128];
	// замедление снарядов NPC ... 1-3...
	uint8_t	NPCWeaponPenalty;
	// ум. защиты NPC объектов
	uint8_t	NPCArmorPenalty;
	// "замедление" наведения NPC ... 1-4
	uint8_t	NPCTargetingSpeedPenalty;
	// 0-ограничено, 1-нет
	uint8_t	LimitedAmmo;
	// 0-может быть уничтожено, 1-нет
	uint8_t	DestroyableWeapon;
	// 1-аркада, 0-симулятор
	uint8_t	WeaponTargetingMode;
	// 1-аркада, 0-симулятор
	uint8_t	SpaceShipControlMode;


	uint8_t	Ship;
	uint8_t	ShipHullUpgrade;
	float	ShipHullCurrentStrength;

	uint8_t	Weapon[6];
	int	WeaponAmmo[6];
	// для каждого
	// 1-только примари, 2 только секондари, 3 оба
	uint8_t	WeaponControl[6];
	// доп. управление, 0-нет, 1-клава,2-мышка,3-джойст
	uint8_t	WeaponAltControl[6];
	uint8_t	WeaponAltControlData[6];
	// для каждого слота - текущее положение оружия
	float	WeaponSlotYAngle[6];



	uint8_t	EngineSystem;
	uint8_t	TargetingSystem;
	uint8_t	AdvancedProtectionSystem;
	uint8_t	PowerSystem;
	uint8_t	TargetingMechanicSystem;

	uint8_t	Difficulty;

	int	Money;
	int	Experience;


	// как стрелять // 1 - как и раньше, все вместе... 2 - поочереди
	uint8_t	PrimaryWeaponFireMode;
	uint8_t	SecondaryWeaponFireMode;

	// последний открытый уровень для данной записи
	uint8_t	OpenLevelNum; // uint8_t - 255, у нас макс 100
	// последняя выбранная миссия
	uint8_t	LastMission; // uint8_t - 255, у нас макс 100

	// опыт за каждую миссию
	int	ByMissionExperience[100]; // ставим 100, на максимум миссий
	// кол-во раз которое играли в миссию
	int	MissionReplayCount[100]; // ставим 100, на максимум миссий



	// резерв
	int 	i[3];
	uint8_t	c[3];
	bool	b[3];
	float	f[3];
};



//------------------------------------------------------------------------------------
// структура лучших результатов
//------------------------------------------------------------------------------------
struct sTopScores {
	char	Name[128];
	int	Score;
};




//------------------------------------------------------------------------------------
// структура данных настройки игры
//------------------------------------------------------------------------------------
struct sGameSetup {
	// номер билда, в котором был создан файл
	int BuildVersion;

	// язык меню
	unsigned int MenuLanguage; // 1-en, 2-de, 3-ru
	// язык голосовых сообщений
	unsigned int VoiceLanguage; // 1-en, 2-de, 3-ru
	// номер шрифта
	int	FontNumber;
	// имя шрифта для fontconfig
	char	FontName[1024];
	// размер шрифта
	int	FontSize;

	// вкл/откл музыки
	int	MusicSw;
	bool	Music_check; // вообще можем-не можем играть музыку
	// вкл/откл SFX
	int	SoundSw;
	int	VoiceSw;
	bool	Sound_check; // вообще можем-не можем играть sfx
	// режим отображения игры
	int	Width;
	int	Height;
	int	BPP;
	float	fAspectRatioWidth;
	float	fAspectRatioHeight;
	int	iAspectRatioWidth;
	int	iAspectRatioHeight;
	// поведение камеры при стандартном отношении (перемещать-не перемешать)
	int 	CameraModeWithStandardAspectRatio;

	// синхронизация
	int	VSync;
	// яркость
	int	Brightness;
	// режим фильтра текстур
	int	TextureFilteringMode;
	// режим качества прорисовки текстур
	int	TexturesQuality;
	// мультисэмпл антиалиасинг
	int	MSAA;
	int	CSAA;


	// качество визуальных эффектов (тайловая подложка, взрывы, системы частиц)  //0-2
	int	VisualEffectsQuality;
	// уровень анизотропии при фильтрации текстур
	int 	AnisotropyLevel;
	// компрессия текстур 0-выкл, 1-S3TC, 2-BPTC
	int	TexturesCompressionType;
	// использование шейдеров
	bool	UseGLSL;
	// использование шадовмеп
	int	ShadowMap;
	// кол-во точечных источников света на 1 объект
	int	MaxPointLights;



	// информация о победителях
	sTopScores	TopScores[10];




	int	KeyboardDecreaseGameSpeed;
	int	KeyboardResetGameSpeed;
	int	KeyboardIncreaseGameSpeed;
	int	KeyboardGameWeaponInfoType;
	int	KeyboardPrimaryWeaponFireMode;
	int	KeyboardSecondaryWeaponFireMode;
	// управление в игре
	// клавиатура
	int	KeyBoardLeft;
	int	KeyBoardRight;
	int	KeyBoardUp;
	int	KeyBoardDown;
	int	KeyBoardPrimary;
	int	KeyBoardSecondary;
	// мышка
	int	MousePrimary;
	int	MouseSecondary;
	// джойстик
	int	JoystickPrimary;
	int	JoystickSecondary;
	// номер джойстика (может их несколько)
	int	JoystickNum;
	// мертвая зона хода ручки джойстика
	int	JoystickDeadZone;



	// задействовать мышку
	bool	MouseControl;
	// чуствительность мышки
	int	ControlSensivity;

	// скорость времени в игре
	float 	GameSpeed;

	// показывать fps + треугольники
	bool	ShowFPS;

	// тип отображения панелей информации оружия в игре
	int 	GameWeaponInfoType;

	// профайлы игроков
	sGameProfile	Profile[5];

	// последняя выбранный профайл
	int	LastProfile;

	// показываемые хинты в загрузке
	int	LoadingHint;

	// флаги, показывать-нет подсказки на меню
	// ставим 10, чтобы было с запасом
	bool	NeedShowHint[10];

	// номер скрипта подложки меню
	int	MenuScript;



	// параметры управление движком игры
	int	VBOCoreMode;
	int	VAOCoreMode;
	int	FBOCoreMode;
	// тип работы с видео памятью, больше или нет 128 мегабайт
	bool	EqualOrMore128MBVideoRAM;
	// работа с хардварной генерацией мипмеп уровней
	bool	HardwareMipMapGeneration;
};





#endif // STRUCT_H
