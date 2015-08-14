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

#ifndef OMNI_UI_MAPPING_H_
#define OMNI_UI_MAPPING_H_

#include <memory>
#include <QGroupBox>
#include <omni/ui/SessionWidget.h>

namespace omni
{
  class Session;

  namespace ui
  {
    namespace Ui
    {
      class Mapping;
    }

    /**@brief Widget for selecting a mapping mode and the parameters
     **/
    class Mapping : 
      public QGroupBox,
      public SessionWidget
    {
      Q_OBJECT
    public:
      Mapping(QWidget* = nullptr);
      ~Mapping();
 
    signals:
      void mappingTypeChanged();
      void mappingChanged();

    public slots:
      void mappingTypeSelected(QString const&);
      void sessionParameters();

    private:
      std::unique_ptr<Ui::Mapping> ui_;
    };
  }
}

#endif /* OMNI_UI_MAPPING_H_ */
