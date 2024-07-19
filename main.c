/*=== puzmon0: ソースコードひな形 ===*/
/*** インクルード宣言 ***/

#include <stdio.h>

/*** 列挙型宣言 ***/
typedef enum Element { FIRE, WATER, WIND, EARTH, LIFE, EMPTY } Element;

/*** グローバル定数の宣言 ***/

/*** 構造体型宣言 ***/
typedef struct player_monster {
  char name[32];
  int hp;
  int max_hp;
  Element element;
  int attack;
  int defense;
} PlayerMonster;

typedef struct enemy_monster {
  char name[32];
  int hp;
  int max_hp;
  Element element;
  int attack;
  int defense;
} EnemyMonster;

typedef struct party {
  char player_name[32];
  PlayerMonster *monsters[4];
  int hp;
  int max_hp;
  int defense;
} Party;

/*** プロトタイプ宣言 ***/
void doBattle(Party *party, EnemyMonster *enemy);

/*** 関数宣言 ***/

int main(int argc, char **argv) {
  printf("*** Puzzle & Monsters ***¥n");
  return 0;
}

/*** ユーティリティ関数宣言 ***/
