Desafio baseado no jogo desenvolvido em sala de aula(Programação 2): AggressiveSquares.

  AggressiveSquares é um jogo simples de 2 quadrados no qual um jogador efetua disparos contra o outro, ganha quem matar o oponente primeiro.
  O desafio era dar alguma implementação ao jogo, em qualquer âmbito que fosse.

Alterações AggressiveSquares:

-   Segreguei as pastas de arquivos *.c em source, *.h em headers e *.o em objects para melhor organização
-   Criei um Makefile.
-   Aumentei o tamanho da Janela(tava pequena demais).
-   Aumentei o FPS de 30 para 60 para que o jogo ficasse mais fluido.
-   Diminui o SQUARE_MOVE de 10 para 5 para equilibrar com o FPS.
-   Manti a velocidade dos disparos para o jogo ficar mais dinâmico.
-   Devolvi os valores das Macros do Allegro(Ex: old: else if (event.type == 42) break; new: else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;) para melhor compreensão.
-   Criei uma nova arma: Tripple_Pistol, possui um Cooldown maior, mas atira em 3 direções.
-   O desenho das balas da tripple_pistol são os mesmos da pistol.
-   Criei um arquivo Tripple_Pistol.c e Tripple_Pistol.h.
-   Criei o TAD Tripple_pistol que possui um tempo de cooldown próprio e uma lista de tiros própria.
-   Criei o Tripple_pistol_shot() que cria 3 tiros que são unicamente ligados.
-   Alterações em Joystick: agora cada Joystick vem com a opção de atirar com a tripple_pistol;
                            para o player_1 o Botão é Z e para o player 2 o botão é o shift direito.
-   Alterações em Bullet: agora trajectory se chama trajectory_x;
                          cada bala possui também trajectory_y;
                          agora cada bala pode se mover na direção y.
                          exclui a função Bullet_move() visto que não estava sendo usada e as balas já estavam sendo atualizadas no bullet_update() em AggressiveSquares.c
-   Alterações em Square: agora cada square também possui seu Tripple_pistol;
                          agora existe a função square_tripple_shot() que executa o tiro para um dado square.
-   Alterações em AggressiveSquare: agora check kill confere também se uma bala de tripple_pistol acertou alguém;
                                    agora update_bullets() também atualiza as balas de tripple_pistol, conferindo também os limites do eixo y;
                                    update position agora também conta com a opção de flipar o joystick->trp_pistol.
