#ifndef COMMA_DECORATOR_H
#define COMMA_DECORATOR_H

#include "StreamDecorator.hpp"

/**
 * \Este decorador pega um fluxo e adiciona uma vírgula após cada token que o
 * constitui, com um espaço vazio à direita antes e depois da vírgula. Nenhuma
 * vírgula é adicionada após o último token. Exemplo: "a 23 b 3,14" =>
 * "a, 23, b, 3,14"
 * Observe que vários espaços vazios são recolhidos em um único espaço.
 */
class CommaDecorator: public StreamDecorator {

public:
  /**
   * \O construtor, que envia o objeto que será decorado, ou seja, o fluxo, para
   * o decorador de base.
   * \param o objeto que deve ser decorado.
   */
  CommaDecorator(AbstractStream* streamObj): StreamDecorator(streamObj) {}

  /**
   * \O destruidor é o destruidor padrão produzido pelo compilador.
   */
  ~CommaDecorator() {};

  /**
   * \Este método decorado adiciona a vírgula entre os tokens do fluxo.
   * \retornar a string decorada com vírgulas entre os tokens.
   */
  std::string toString() override;
};

#endif