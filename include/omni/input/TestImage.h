#ifndef OMNI_INPUT_TESTIMAGE_H_
#define OMNI_INPUT_TESTIMAGE_H_

#include <QOpenGLShaderProgram>
#include "Interface.h"

namespace omni
{
  namespace input
  {
    class TestImage : public Interface
    {
    public:
      OMNI_TYPEID("TestImage")

      TestImage();
      ~TestImage();

      void bind();
      void release();
      void free();
      void update();
      
      QPointF pos();
      void setPos() const;
      
      void toStream(QDataStream&) const;
      void fromStream(QDataStream&);

    private:
      QPointF pos_;
      std::unique_ptr<QOpenGLShaderProgram> shader_;
    };

  }
}

#endif /* OMNI_INPUT_TESTIMAGE_H_ */