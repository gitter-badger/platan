// This file is part of Platan.
// Copyright (C) 2014 Gábor Angyal
//
// Platan is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Platan is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Platan.  If not, see <http://www.gnu.org/licenses/>.

#include <QColor>

#include "colorpalette.h"

QColor pastelize(QColor color)
{
    color.setHsvF(color.hsvHueF(), color.hsvSaturationF() * 0.6, (color.valueF() + 1.0f) / 2.0f);
    return color;
}

ColorPalette::ColorPalette()
{
    //Tango color palette
    //http://tango.freedesktop.org/Tango_Icon_Theme_Guidelines

    //light
    colors.push_back(pastelize(QColor(0xef, 0x29, 0x29)));
    colors.push_back(pastelize(QColor(0xad, 0x7f, 0xa8)));
    colors.push_back(pastelize(QColor(0x72, 0x9f, 0xcf)));
    colors.push_back(pastelize(QColor(0x8a, 0xe2, 0x34)));
    colors.push_back(pastelize(QColor(0xe9, 0xb9, 0x6e)));
    colors.push_back(pastelize(QColor(0xfc, 0xaf, 0x3e)));
    colors.push_back(pastelize(QColor(0xfc, 0xe9, 0x4f)));

    //dark
    colors.push_back(pastelize(QColor(0xa4, 0x00, 0x00)));
    colors.push_back(pastelize(QColor(0x5c, 0x35, 0x66)));
    colors.push_back(pastelize(QColor(0x20, 0x4a, 0x87)));
    colors.push_back(pastelize(QColor(0x4e, 0x9a, 0x06)));
    colors.push_back(pastelize(QColor(0x8f, 0x59, 0x02)));
    colors.push_back(pastelize(QColor(0xce, 0x5c, 0x00)));
    colors.push_back(pastelize(QColor(0xc4, 0xa0, 0x00)));

    //middle
    colors.push_back(pastelize(QColor(0xcc, 0x00, 0x00)));
    colors.push_back(pastelize(QColor(0x75, 0x50, 0x7b)));
    colors.push_back(pastelize(QColor(0x34, 0x65, 0xa4)));
    colors.push_back(pastelize(QColor(0x73, 0xd2, 0x16)));
    colors.push_back(pastelize(QColor(0xc1, 0x7d, 0x11)));
    colors.push_back(pastelize(QColor(0xf5, 0x79, 0x00)));
    colors.push_back(pastelize(QColor(0xed, 0xd4, 0x00)));

    count = colors.length();
}

QColor ColorPalette::getColor(int i)
{
    return colors[i % count];
}
