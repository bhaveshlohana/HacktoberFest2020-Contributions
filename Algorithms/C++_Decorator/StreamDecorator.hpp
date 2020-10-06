#ifndef STREAM_DECORATOR_H
#define STREAM_DECORATOR_H

#include "AbstractStream.hpp"

/**
 * \Este é o decorador básico. Todos os outros decoradores terão que implementá-lo.
 */
class StreamDecorator: public AbstractStream {

public:
  /**
   * \O construtor, que simplesmente liga o fluxo abstrato ao estado interno
   * deste objeto.
   * \param o objeto que deve ser decorado.
   */
  StreamDecorator(AbstractStream* streamObj): _streamObj(streamObj) {}

  /**
   * \O destruidor é o destruidor padrão produzido pelo compilador.
   */
  ~StreamDecorator() {};

  /**
   * \Este é o método que terá que ser sobrescrito por qualquer decorador que
   * rodeia esta classe.
   * \retornar a string decorada não modificada.
   */
  std::string toString() override {
    return _streamObj->toString();
  }

  private:
  AbstractStream *_streamObj; ///< Um ponteiro para o objeto decorado.
};

#endif