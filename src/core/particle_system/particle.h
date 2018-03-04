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

#ifndef PARTICLE_H
#define PARTICLE_H

#include "../base.h"

struct sVECTOR3D;

//-----------------------------------------------------------------------------
// Структура цвета
//-----------------------------------------------------------------------------
struct sCOLORVALUE3D {
	float r;
	float g;
	float b;
	float a;
};


//-----------------------------------------------------------------------------
// Класс sParticle
//-----------------------------------------------------------------------------
struct sParticle {
	// конструктор и деструктор
	sParticle() {};
	~sParticle() {};

	// обновление информации в частице
	bool Update(float TimeDelta, sVECTOR3D ParentLocation = sVECTOR3D{0.0f,0.0f,0.0f}, bool Attractive = false, float AttractiveValue = 25.0f);
	// текущее место расположения частицы
	sVECTOR3D	Location{0.0f, 0.0f, 0.0f};
	// текущая скорость частицы
	sVECTOR3D	Velocity{0.0f, 0.0f, 0.0f};

	// texture number
	int		TextureNum{0};

	// текущий цвет частицы
	sCOLORVALUE3D	Color{1.0f, 0.0f, 0.0f, 0.5f};
	// значение приращение цвета
	sCOLORVALUE3D	ColorDelta{0.0f, 0.0f, 0.0f, 0.0f};

	// время жизни частицы в секундах
	float		Age{0.0f};

	// оставщееся время жизни частицы
	float		Lifetime{0.0f};

	// размер частицы
	float		Size{1.0f};
	// значение изменения размера
	float		SizeDelta{0.0f};

	// прозрачность
	float		Alpha{1.0f};
	// изменение прозрачности
	float		AlphaDelta{0.0f};


	// сначало ув. альфу, потом уменьшаем
	bool		AlphaShowHide{false};
	// какой цикл - затухаем, или только появляемся
	bool		Show{true};

	// если нужно замедлять и остановить
	bool		NeedStop{false};

	// указатели на цепь частиц
	sParticle	*Next{nullptr};
	sParticle	*Prev{nullptr};
};

#endif // PARTICLE_H
