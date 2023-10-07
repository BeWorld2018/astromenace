CC = ppc-morphos-gcc-9
CXX = ppc-morphos-g++-9
RM = rm -f
OSTYPE = $(shell uname -s)
DEBUG = 0

CFLAGS = -Wall -Duse_SDL2

ifeq ($(DEBUG), 1)
CFLAGS += -g
else
CFLAGS += -O2
endif

CFLAGS += $(shell sdl2-config --cflags)

CXXFLAGS = $(CFLAGS)

LDFLAGS = $(shell sdl2-config --libs) 
LDFLAGS += -lopenal_sdl2 -lalut -lGLU -lGL

ifeq ($(OSTYPE), AROS)
#CFLAGS += 
LDFLAGS += -lfreetype2 -lvorbisfile -lvorbis -logg
endif

ifeq ($(OSTYPE), AmigaOS)
#CFLAGS += -D__USE_INLINE__
CFLAGS += -D__unix
LDFLAGS += -lfreetype -lvorbisfile -lvorbis -logg -lpthread
endif

ifeq ($(OSTYPE), MorphOS)
CFLAGS += -D__unix -I/usr/local/include
LDFLAGS += -lfreetype
endif

OBJ = \
	AstroMenaceSource/Loading.o \
	AstroMenaceSource/Loop_audio.o \
	AstroMenaceSource/Loop_proc.o \
	AstroMenaceSource/Main.o \
	AstroMenaceSource/MainFS2VFS.o \
	AstroMenaceSource/Core/Camera/Camera.o \
	AstroMenaceSource/Core/Camera/CameraMath.o \
	AstroMenaceSource/Core/CollisionDetection/AABB.o \
	AstroMenaceSource/Core/CollisionDetection/CommonMath.o \
	AstroMenaceSource/Core/CollisionDetection/OBB.o \
	AstroMenaceSource/Core/CollisionDetection/Sphere.o \
	AstroMenaceSource/Core/Font/Font.o \
	AstroMenaceSource/Core/Font/FontManager.o \
	AstroMenaceSource/Core/Light/Light.o \
	AstroMenaceSource/Core/Light/LightManager.o \
	AstroMenaceSource/Core/Math/Math.o \
	AstroMenaceSource/Core/Math/Matrix33.o \
	AstroMenaceSource/Core/Math/Matrix44.o \
	AstroMenaceSource/Core/Model3D/Model3D.o \
	AstroMenaceSource/Core/Model3D/Model3DManager.o \
	AstroMenaceSource/Core/Model3D/VW3D.o \
	AstroMenaceSource/Core/ParticleSystem/Particle.o \
	AstroMenaceSource/Core/ParticleSystem/ParticleSystem.o \
	AstroMenaceSource/Core/ParticleSystem/ParticleSystemManager.o \
	AstroMenaceSource/Core/ParticleSystem2D/Particle2D.o \
	AstroMenaceSource/Core/ParticleSystem2D/ParticleSystem2D.o \
	AstroMenaceSource/Core/RendererInterface/OGL_Draw2D.o \
	AstroMenaceSource/Core/RendererInterface/OGL_Draw3D.o \
	AstroMenaceSource/Core/RendererInterface/OGL_FBO.o \
	AstroMenaceSource/Core/RendererInterface/OGL_GLSL.o \
	AstroMenaceSource/Core/RendererInterface/OGL_Light.o \
	AstroMenaceSource/Core/RendererInterface/OGL_Main.o \
	AstroMenaceSource/Core/RendererInterface/OGL_Matrix.o \
	AstroMenaceSource/Core/RendererInterface/OGL_OcclusionQuery.o \
	AstroMenaceSource/Core/RendererInterface/OGL_Texture.o \
	AstroMenaceSource/Core/RendererInterface/OGL_VAO.o \
	AstroMenaceSource/Core/RendererInterface/OGL_VBO.o \
	AstroMenaceSource/Core/RendererInterface/RI_Int.o \
	AstroMenaceSource/Core/Sound/Buffer.o \
	AstroMenaceSource/Core/Sound/Music.o \
	AstroMenaceSource/Core/Sound/Sound.o \
	AstroMenaceSource/Core/Sound/SoundManager.o \
	AstroMenaceSource/Core/System/Keyboard.o \
	AstroMenaceSource/Core/System/Mouse.o \
	AstroMenaceSource/Core/System/System.o \
	AstroMenaceSource/Core/System/Timer.o \
	AstroMenaceSource/Core/System/Languages/de.o \
	AstroMenaceSource/Core/System/Languages/en.o \
	AstroMenaceSource/Core/System/Languages/ru.o \
	AstroMenaceSource/Core/Text/Text.o \
	AstroMenaceSource/Core/Texture/Texture.o \
	AstroMenaceSource/Core/Texture/TextureManager.o \
	AstroMenaceSource/Core/Texture/Texture_JPG.o \
	AstroMenaceSource/Core/Texture/Texture_PNG.o \
	AstroMenaceSource/Core/Texture/Texture_TGA.o \
	AstroMenaceSource/Core/VirtualFileSystem/Haff.o \
	AstroMenaceSource/Core/VirtualFileSystem/RLE.o \
	AstroMenaceSource/Core/VirtualFileSystem/VFS.o \
	AstroMenaceSource/Core/XML/XML.o \
	AstroMenaceSource/Game/Game.o \
	AstroMenaceSource/Game/Game_Camera.o \
	AstroMenaceSource/Game/Game_Mission.o \
	AstroMenaceSource/Game/Game_PlayerShip.o \
	AstroMenaceSource/Game/Game_WeaponSlot.o \
	AstroMenaceSource/GraphicFX/ShadowMap.o \
	AstroMenaceSource/GraphicFX/SkyBox.o \
	AstroMenaceSource/GraphicFX/StarSystem.o \
	AstroMenaceSource/GraphicFX/GameLvlText/GameLvlText.o \
	AstroMenaceSource/GraphicFX/GameLvlText/GameLvlTextManager.o \
	AstroMenaceSource/GraphicFX/SpaceStars/SpaceStars.o \
	AstroMenaceSource/GraphicFX/SpaceStars/Star.o \
	AstroMenaceSource/Menu/Button.o \
	AstroMenaceSource/Menu/Dialog.o \
	AstroMenaceSource/Menu/Menu.o \
	AstroMenaceSource/Menu/Menu_ConfControl.o \
	AstroMenaceSource/Menu/Menu_Credits.o \
	AstroMenaceSource/Menu/Menu_Difficulty.o \
	AstroMenaceSource/Menu/Menu_Information.o \
	AstroMenaceSource/Menu/Menu_Interface.o \
	AstroMenaceSource/Menu/Menu_Mission.o \
	AstroMenaceSource/Menu/Menu_Options.o \
	AstroMenaceSource/Menu/Menu_OptionsAdv.o \
	AstroMenaceSource/Menu/Menu_Profile.o \
	AstroMenaceSource/Menu/Menu_TopScores.o \
	AstroMenaceSource/Menu/Menu_Workshop.o \
	AstroMenaceSource/Menu/Menu_Workshop_Shipyard.o \
	AstroMenaceSource/Menu/Menu_Workshop_Weaponry.o \
	AstroMenaceSource/Menu/Menu_Workshop_Workshop.o \
	AstroMenaceSource/Object3D/AI.o \
	AstroMenaceSource/Object3D/Object3D.o \
	AstroMenaceSource/Object3D/Object3DCollision.o \
	AstroMenaceSource/Object3D/Object3DCollisionMath.o \
	AstroMenaceSource/Object3D/Object3DFunctions.o \
	AstroMenaceSource/Object3D/Object3DManager.o \
	AstroMenaceSource/Object3D/Explosion/Explosion.o \
	AstroMenaceSource/Object3D/Explosion/ExplosionGFX.o \
	AstroMenaceSource/Object3D/Explosion/ExplosionManager.o \
	AstroMenaceSource/Object3D/Explosion/BulletExplosion/BulletExplosion.o \
	AstroMenaceSource/Object3D/Explosion/GroundExplosion/GroundExplosion.o \
	AstroMenaceSource/Object3D/Explosion/SpaceExplosion/SpaceExplosion.o \
	AstroMenaceSource/Object3D/GroundObject/GroundObject.o \
	AstroMenaceSource/Object3D/GroundObject/GroundObjectManager.o \
	AstroMenaceSource/Object3D/GroundObject/Building/Building.o \
	AstroMenaceSource/Object3D/GroundObject/MilitaryBuilding/MilitaryBuilding.o \
	AstroMenaceSource/Object3D/GroundObject/Tracked/Tracked.o \
	AstroMenaceSource/Object3D/GroundObject/Wheeled/Wheeled.o \
	AstroMenaceSource/Object3D/Projectile/Projectile.o \
	AstroMenaceSource/Object3D/Projectile/ProjectileGFX.o \
	AstroMenaceSource/Object3D/Projectile/ProjectileManager.o \
	AstroMenaceSource/Object3D/SpaceObject/SpaceObject.o \
	AstroMenaceSource/Object3D/SpaceObject/SpaceObjectGFX.o \
	AstroMenaceSource/Object3D/SpaceObject/SpaceObjectManager.o \
	AstroMenaceSource/Object3D/SpaceObject/Asteroid/Asteroid.o \
	AstroMenaceSource/Object3D/SpaceObject/BasePart/BasePart.o \
	AstroMenaceSource/Object3D/SpaceObject/BigAsteroid/BigAsteroid.o \
	AstroMenaceSource/Object3D/SpaceObject/Planet/Planet.o \
	AstroMenaceSource/Object3D/SpaceObject/ShipPart/ShipPart.o \
	AstroMenaceSource/Object3D/SpaceShip/SpaceShip.o \
	AstroMenaceSource/Object3D/SpaceShip/SpaceShipManager.o \
	AstroMenaceSource/Object3D/SpaceShip/AlienSpaceFighter/AlienSpaceFighter.o \
	AstroMenaceSource/Object3D/SpaceShip/AlienSpaceFighter/AlienSpaceFighterEngine.o \
	AstroMenaceSource/Object3D/SpaceShip/AlienSpaceMotherShip/AlienSpaceMotherShip.o \
	AstroMenaceSource/Object3D/SpaceShip/AlienSpaceMotherShip/AlienSpaceMotherShipEngine.o \
	AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighter.o \
	AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighterArmour.o \
	AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighterEngine.o \
	AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighterWeapon.o \
	AstroMenaceSource/Object3D/SpaceShip/PirateShip/PirateShip.o \
	AstroMenaceSource/Object3D/SpaceShip/PirateShip/PirateShipEngine.o \
	AstroMenaceSource/Object3D/Weapon/Weapon.o \
	AstroMenaceSource/Object3D/Weapon/WeaponFunctions.o \
	AstroMenaceSource/Object3D/Weapon/WeaponManager.o \
	AstroMenaceSource/ScriptEngine/Script.o \
	AstroMenaceSource/ScriptEngine/ScriptFunction.o \
	AstroMenaceSource/ScriptEngine/Setup.o \

all: astromenace

astromenace: $(OBJ)
	$(CXX) -o $@  $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)
