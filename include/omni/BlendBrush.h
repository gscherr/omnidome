/* Copyright (c) 2014-2015 "Omnidome" by cr8tr
 * Dome Mapping Projection Software (http://omnido.me).
 * Omnidome was created by Michael Winkelmann aka Wilston Oreo (@WilstonOreo)
 * 
 * This file is part of Omnidome.
 * 
 * Omnidome is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OMNI_BLENDBRUSH_H_
#define OMNI_BLENDBRUSH_H_

#include <omni/BlendBuffer.h>

class QPointF;
class QDataStream;

namespace omni
{
  /**@brief BlendBrush for drawing on the blendmask
   * @detail Holds an internal pixel buffer
   **/
  class BlendBrush
  {
  public:
    /// Default constructor
    BlendBrush();

    /**@brief Constructor with a size and feather value (1.0 by default)
       @detail Updates internal pixel buffer
     **/
    BlendBrush(float _size, float _feather = 1.0);

    /// Returns brush size
    float size() const;
    
    /**@brief Sets size of the brush.
     * @detail Minimum size is 2 pixels, maximum size is 512 pixels
     **/
    void setSize(float _size);

    /**@brief Increase/Decrease size of the brush with a certain delta value
     * @detail Minimum size is 2 pixels, maximum size is 512 pixels
     **/
    void changeSize(float _delta);

    /// Return feather value
    float feather() const;
    
    /**@brief Set feather value
     * @detail Value must be between 0.0 and 1.0 and is clamped if necessary.
     *         A value 0.0 means a hard brush, a value of 1.0 means soft brush.
     **/
    void setFeather(float _feather); 
    
    /// Returns true if the brush is inverted (aka eraser mode)
    bool invert() const;
    
    /// Sets inverted flag of the brush
    void setInvert(bool _invert);

    /// Set brush settings and generate pixel buffer
    void setBrush(float _size, float _feather, bool _invert);
    
    /// Draws internal pixel buffer in given blend buffer
    void stamp(const QPointF& _pos, BlendBuffer& _buf) const;

    /**@brief Draws a lot from point _p0 to _p1 on given pixel buffer
      *@param _p0 Start point
      *@param _p1 End point
      *@param _buf Buffer to be drawn
      *@param _leftOver Left over value to compensate positioning errors from previous moves
      *@returns New left over value
     **/
    float drawLine(const QPointF& _p0, const QPointF& _p1, 
        BlendBuffer& _buf, float _leftOver = 0.0);

    BlendBuffer const& buffer() const;

    /// Test for equality, buffer is ignored
    friend bool operator==(BlendBrush const&,BlendBrush const&);

  private:
    /// Generate internal pixel buffer with given size and feather parameters
    void generate();

    /// Internal pixel buffer
    BlendBuffer buffer_;

    float size_ = 100.0;
    float feather_ = 1.0;
    bool invert_ = false;
  };
}

QDataStream& operator>>(QDataStream&, omni::BlendBrush&);
QDataStream& operator<<(QDataStream&, omni::BlendBrush const&);

#endif /* OMNI_BLENDBRUSH_H_ */

