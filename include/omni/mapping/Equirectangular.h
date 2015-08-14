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

#ifndef OMNI_MAPPING_EQUIRECTANGULAR_H_
#define OMNI_MAPPING_EQUIRECTANGULAR_H_

#include "Rotatable.h"

namespace omni
{
  namespace mapping
  {
    /// Equirectangular spherical mapping
    class Equirectangular : 
      public Rotatable,
      Registrar<Equirectangular>
    {
    public:
      OMNI_TYPEID("Equirectangular")

      Equirectangular(); 
      ~Equirectangular();
      
      Mode mode() const;

      void bind(OutputMode = OutputMode::MAPPED_INPUT);

      /// Value between 0.0 and 1.0 for top strip position
      qreal stripTop() const;
      
      /// Top border position of strip. Value is clamped between 0.0 and 1.0 
      void setStripTop(qreal _stripTop);
      
      /// Value between 0.0 and 1.0 to for bottom strip position 
      qreal stripBottom() const;
      
      /// Bottom border position of strip. Value is clamped between 0.0 and 1.0 
      void setStripBottom(qreal _stripBottom);

      /// Deserialize from stream
      void fromStream(QDataStream&);

      /// Serialize to stream
      void toStream(QDataStream&) const;

      /// Test for equality
      friend bool operator==(Equirectangular const&,Equirectangular const&);

    private:
      /// Assures that strip bottom is always lower then strip top
      void validate();
      
      qreal stripBottom_ = 0.0, stripTop_ = 1.0;
    };
  }
}

OMNI_DECL_STREAM_OPERATORS(omni::mapping::Equirectangular)


#endif /* OMNI_MAPPING_EQUIRECTANGULAR_H_ */
