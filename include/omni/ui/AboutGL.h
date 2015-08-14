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

#ifndef OMNI_UI_ABOUTGL_H_
#define OMNI_UI_ABOUTGL_H_

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

namespace omni
{  
  namespace ui
  {
    class AboutGL : public QOpenGLWidget
    {
      Q_OBJECT
    public:
      explicit AboutGL(QWidget* _parent = nullptr);
      ~AboutGL();
      
    protected:
      void mousePressEvent(QMouseEvent*);

      void initializeGL();
      void resizeGL(int _w, int _h);    
      void paintGL();
      double startTime_;

    private:
      QOpenGLShaderProgram* shader_ = nullptr;
    };
  }
}

#endif /* OMNI_UI_ABOUTGL_H_ */
